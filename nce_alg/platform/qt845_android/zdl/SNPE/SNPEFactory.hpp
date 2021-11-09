//==============================================================================
//
//  Copyright (c) 2015-2019 Qualcomm Technologies, Inc.
//  All Rights Reserved.
//  Confidential and Proprietary - Qualcomm Technologies, Inc.
//
//==============================================================================

#ifndef _SNPE_FACTORY_HPP_
#define _SNPE_FACTORY_HPP_

#include "SNPE/SNPE.hpp"
#include "DlSystem/DlEnums.hpp"
#include "DlSystem/UDLFunc.hpp"
#include "DlSystem/ZdlExportDefine.hpp"
#include "DlSystem/DlOptional.hpp"

namespace zdl {
   namespace DlSystem
   {
      class ITensorFactory;
      class IUserBufferFactory;
   }
   namespace DlContainer
   {
      class IDlContainer;
   }
}



namespace zdl { namespace SNPE {
/** @addtogroup c_plus_plus_apis C++
@{ */

/**
 * The factory class for creating SNPE objects.
 *
 */
class ZDL_EXPORT SNPEFactory
{
public:

   /**
    * Indicates whether the supplied runtime is available on the
    * current platform.
    *
    * @param[in] runtime The target runtime to check.
    *
    * @param[in] option Extent to perform runtime available check.
    *
    * @return True if the supplied runtime is available; false,
    *         otherwise.
    */
   static bool isRuntimeAvailable(zdl::DlSystem::Runtime_t runtime);

   /**
    * Indicates whether the supplied runtime is available on the
    * current platform.
    *
    * @param[in] runtime The target runtime to check.
    *
    * @param[in] option Extent to perform runtime available check.
    *
    * @return True if the supplied runtime is available; false,
    *         otherwise.
    */
   static bool isRuntimeAvailable(zdl::DlSystem::Runtime_t runtime,
                                  zdl::DlSystem::RuntimeCheckOption_t option);

   /**
    * Gets a reference to the tensor factory.
    *
    * @return A reference to the tensor factory.
    */
   static zdl::DlSystem::ITensorFactory& getTensorFactory();

   /**
    * Gets a reference to the UserBuffer factory.
    *
    * @return A reference to the UserBuffer factory.
    */
   static zdl::DlSystem::IUserBufferFactory& getUserBufferFactory();

   /**
    * Gets the version of the SNPE library.
    *
    * @return Version of the SNPE library.
    *
    */
   static zdl::DlSystem::Version_t getLibraryVersion();

   /**
    * Set the SNPE storage location for all SNPE instances in this
    * process. Note that this may only be called once, and if so
    * must be called before creating any SNPE instances.
    *
    * @param[in] storagePath Absolute path to a directory which SNPE may
    *  use for caching and other storage purposes.
    *
    * @return True if the supplied path was succesfully set as
    *  the SNPE storage location, false otherwise.
    */
   static bool setSNPEStorageLocation(const char* storagePath);

#ifdef DNN_RUNTIME_HAVE_UDO_CAPABILITY
   /**
    * @brief Add an operations package to registry.
    *
    * @param[in] regLibraryPath Path to the dynamic library of the registration library
    *                      that allows clients to point a SNPE instance to implementation
    *                      libraries corresponding to operations that are part of the package
    *
    * @return True if successful, False otherwise.
    */
   static bool addOpPackage( const std::string& regLibraryPath );
#endif

   /**
    * Indicates whether the OpenGL and OpenCL interoperability is supported
    * on GPU platform.
    *
    * @return True if the OpenGL and OpenCl interop is supported; false,
    *         otherwise.
    */
   static bool isGLCLInteropSupported();
};

/** @} */ /* end_addtogroup c_plus_plus_apis C++ */
}}


#endif
