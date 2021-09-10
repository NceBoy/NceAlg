// Copyright (C) 2018-2020 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

/**
 * @brief a header that defines wrappers for internal GPU plugin-specific
 * OpenCL context and OpenCL shared memory blobs
 *
 * @file gpu_context_api_ocl.hpp
 */
#pragma once

#include <memory>
#include <string>
#include "ie_compound_blob.h"
#include "ie_core.hpp"
#include "gpu_params.hpp"
#include "details/gpu_context_helpers.hpp"
#include "gpu_ocl_wrapper.hpp"

namespace InferenceEngine {

namespace gpu {
/**
* @brief This class represents an abstraction for GPU plugin remote context
* which is shared with OpenCL context object.
* The plugin object derived from this class can be obtained either with
* GetContext() method of Executable network or using CreateContext() Core call.
*/
class ClContext : public RemoteContext, public details::param_map_obj_getter {
public:
    /**
    * @brief A smart pointer to the ClContext object
    */
    using Ptr = std::shared_ptr<ClContext>;

    /**
     * @brief Returns the underlying OpenCL context handle.
     */
    cl_context get() {
        return _ObjFromParams<cl_context, gpu_handle_param>(getParams(), GPU_PARAM_KEY(OCL_CONTEXT),
            GPU_PARAM_KEY(CONTEXT_TYPE), GPU_PARAM_VALUE(OCL), GPU_PARAM_VALUE(VA_SHARED));
    }

    /**
     * @brief OpenCL context handle conversion operator for the ClContext object.
     * @return Underlying OpenCL context handle
     */
    operator cl_context() {
        return get();
    }

    /**
     * @brief Standard Khronos cl::Context wrapper conversion operator for the ClContext object.
     * @return cl::Context object
     */
    operator cl::Context() {
        return cl::Context(get(), true);
    }
};

/**
* @brief The basic class for all GPU plugin remote blob objects.
* The OpenCL memory object handle (cl_mem) can be obtained from this class object.
*/
class ClBlob : public RemoteBlob {
public:
    /**
    * @brief A smart pointer to the ClBlob object
    */
    using Ptr = std::shared_ptr<ClBlob>;

    /**
     * @brief Creates a ClBlob object with the specified dimensions and layout.
     * @param tensorDesc Tensor description
     */
    explicit ClBlob(const TensorDesc& tensorDesc) : RemoteBlob(tensorDesc) {}
};

/**
* @brief This class represents an abstraction for GPU plugin remote blob
* which can be shared with user-supplied OpenCL buffer.
* The plugin object derived from this class can be obtained with CreateBlob() call.
* @note User can obtain OpenCL buffer handle from this class.
*/
class ClBufferBlob : public ClBlob, public details::param_map_obj_getter {
public:
    /**
    * @brief A smart pointer to the ClBufferBlob object
    */
    using Ptr = std::shared_ptr<ClBufferBlob>;

    /**
     * @brief Creates a ClBufferBlob object with the specified dimensions and layout.
     * @param tensorDesc Tensor description
     */
    explicit ClBufferBlob(const TensorDesc& tensorDesc) : ClBlob(tensorDesc) {}

    /**
     * @brief Returns the underlying OpenCL memory object handle.
     */
    cl_mem get() {
        return _ObjFromParams<cl_mem, gpu_handle_param>(getParams(), GPU_PARAM_KEY(MEM_HANDLE),
            GPU_PARAM_KEY(SHARED_MEM_TYPE), GPU_PARAM_VALUE(OCL_BUFFER), GPU_PARAM_VALUE(DX_BUFFER));
    }

    /**
     * @brief OpenCL memory handle conversion operator.
     */
    operator cl_mem() {
        return get();
    }

    /**
     * @brief Standard Khronos cl::Buffer wrapper conversion operator.
     * @return cl::Buffer object
     */
    operator cl::Buffer() {
        return cl::Buffer(get(), true);
    }
};

/**
* @brief This class represents an abstraction for GPU plugin remote blob
* which can be shared with user-supplied OpenCL 2D Image.
* The plugin object derived from this class can be obtained with CreateBlob() call.
* @note User can obtain OpenCL image handle from this class.
*/
class ClImage2DBlob : public ClBlob, public details::param_map_obj_getter {
public:
    /**
    * @brief A smart pointer to the ClImage2DBlob object
    */
    using Ptr = std::shared_ptr<ClImage2DBlob>;

    /**
     * @brief Creates a ClImage2DBlob object with the specified dimensions and layout.
     * @param tensorDesc Tensor description
     */
    explicit ClImage2DBlob(const TensorDesc& tensorDesc) : ClBlob(tensorDesc) {}

    /**
     * @brief Returns the underlying OpenCL memory object handle.
     */
    cl_mem get() {
        return _ObjFromParams<cl_mem, gpu_handle_param>(getParams(), GPU_PARAM_KEY(MEM_HANDLE),
            GPU_PARAM_KEY(SHARED_MEM_TYPE), GPU_PARAM_VALUE(OCL_IMAGE2D), GPU_PARAM_VALUE(VA_SURFACE));
    }

    /**
     * @brief OpenCL memory handle conversion operator.
     */
    operator cl_mem() {
        return get();
    }

    /**
     * @brief Standard Khronos cl::Image2D wrapper conversion operator for the ClContext object.
     * @return cl::Image2D object
     */
    operator cl::Image2D() {
        return cl::Image2D(get(), true);
    }
};

/**
* @brief This function is used to construct a NV12 compound blob object from two cl::Image2D wrapper objects.
* The resulting compound contains two remote blobs for Y and UV planes of the surface.
* @param ctx RemoteContext plugin object derived from ClContext class.
* @param nv12_image_plane_y cl::Image2D object containing Y plane data.
* @param nv12_image_plane_uv cl::Image2D object containing UV plane data.
* @return Pointer to plugin-specific context class object, which is derived from RemoteContext.
*/
static inline Blob::Ptr make_shared_blob_nv12(RemoteContext::Ptr ctx, cl::Image2D& nv12_image_plane_y, cl::Image2D& nv12_image_plane_uv) {
    auto casted = std::dynamic_pointer_cast<ClContext>(ctx);
    if (nullptr == casted) {
        THROW_IE_EXCEPTION << "Invalid remote context passed";
    }

    size_t width = nv12_image_plane_y.getImageInfo<CL_IMAGE_WIDTH>();
    size_t height = nv12_image_plane_y.getImageInfo<CL_IMAGE_HEIGHT>();

    // despite of layout, blob dimensions always follow in N,C,H,W order
    TensorDesc ydesc(Precision::U8, { 1, 1, height, width }, Layout::NHWC);

    ParamMap blobParams = {
        { GPU_PARAM_KEY(SHARED_MEM_TYPE), GPU_PARAM_VALUE(OCL_IMAGE2D) },
        { GPU_PARAM_KEY(MEM_HANDLE), static_cast<gpu_handle_param>(nv12_image_plane_y.get()) }
    };
    Blob::Ptr y_blob = std::dynamic_pointer_cast<Blob>(casted->CreateBlob(ydesc, blobParams));

    TensorDesc uvdesc(Precision::U8, { 1, 2, height / 2, width / 2 }, Layout::NHWC);
    blobParams[GPU_PARAM_KEY(MEM_HANDLE)] = static_cast<gpu_handle_param>(nv12_image_plane_uv.get());
    Blob::Ptr uv_blob = std::dynamic_pointer_cast<Blob>(casted->CreateBlob(uvdesc, blobParams));

    Blob::Ptr res = make_shared_blob<NV12Blob>(y_blob, uv_blob);
    return res;
}

/**
* @brief This function is used to obtain remote context object from user-supplied OpenCL context handle
*/
static inline RemoteContext::Ptr make_shared_context(Core& core, std::string deviceName, cl_context ctx) {
    ParamMap contextParams = {
        { GPU_PARAM_KEY(CONTEXT_TYPE), GPU_PARAM_VALUE(OCL) },
        { GPU_PARAM_KEY(OCL_CONTEXT), static_cast<gpu_handle_param>(ctx) }
    };
    return core.CreateContext(deviceName, contextParams);
}

/**
* @brief This function is used to create remote blob object within default GPU plugin OpenCL context
*/
static inline Blob::Ptr make_shared_blob(const TensorDesc& desc, ClContext::Ptr ctx) {
    return std::dynamic_pointer_cast<Blob>(ctx->CreateBlob(desc));
}

/**
* @brief This function is used to obtain remote blob object from user-supplied cl::Buffer wrapper object
*/
static inline Blob::Ptr make_shared_blob(const TensorDesc& desc, RemoteContext::Ptr ctx, cl::Buffer& buffer) {
    auto casted = std::dynamic_pointer_cast<ClContext>(ctx);
    if (nullptr == casted) {
        THROW_IE_EXCEPTION << "Invalid remote context passed";
    }

    ParamMap params = {
        { GPU_PARAM_KEY(SHARED_MEM_TYPE), GPU_PARAM_VALUE(OCL_BUFFER) },
        { GPU_PARAM_KEY(MEM_HANDLE), static_cast<gpu_handle_param>(buffer.get()) }
    };
    return std::dynamic_pointer_cast<Blob>(casted->CreateBlob(desc, params));
}

/**
* @brief This function is used to obtain remote blob object from user-supplied OpenCL buffer handle
*/
static inline Blob::Ptr make_shared_blob(const TensorDesc& desc, RemoteContext::Ptr ctx, cl_mem buffer) {
    auto casted = std::dynamic_pointer_cast<ClContext>(ctx);
    if (nullptr == casted) {
        THROW_IE_EXCEPTION << "Invalid remote context passed";
    }

    ParamMap params = {
        { GPU_PARAM_KEY(SHARED_MEM_TYPE), GPU_PARAM_VALUE(OCL_BUFFER) },
        { GPU_PARAM_KEY(MEM_HANDLE), static_cast<gpu_handle_param>(buffer) }
    };
    return std::dynamic_pointer_cast<Blob>(casted->CreateBlob(desc, params));
}

/**
* @brief This function is used to obtain remote blob object from user-supplied cl::Image2D wrapper object
*/
static inline Blob::Ptr make_shared_blob(const TensorDesc& desc, RemoteContext::Ptr ctx, cl::Image2D& image) {
    auto casted = std::dynamic_pointer_cast<ClContext>(ctx);
    if (nullptr == casted) {
        THROW_IE_EXCEPTION << "Invalid remote context passed";
    }

    ParamMap params = {
        { GPU_PARAM_KEY(SHARED_MEM_TYPE), GPU_PARAM_VALUE(OCL_IMAGE2D) },
        { GPU_PARAM_KEY(MEM_HANDLE), static_cast<gpu_handle_param>(image.get()) }
    };
    return std::dynamic_pointer_cast<Blob>(casted->CreateBlob(desc, params));
}

};  // namespace gpu

};  // namespace InferenceEngine
