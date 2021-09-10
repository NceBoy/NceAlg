// Copyright (C) 2018-2020 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

/**
 * @brief This is a header file for the Inference Engine Core class C++ API
 *
 * @file ie_core.hpp
 */
#pragma once

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "cpp/ie_plugin_cpp.hpp"
#include "details/os/os_filesystem.hpp"
#include "ie_extension.h"
#include "ie_remote_context.hpp"

namespace InferenceEngine {

/**
 * @brief This class represents Inference Engine Core entity.
 *
 * It can throw exceptions safely for the application, where it is properly handled.
 */
class INFERENCE_ENGINE_API_CLASS(Core) {
    class Impl;
    std::shared_ptr<Impl> _impl;

public:
    /** @brief Constructs Inference Engine Core instance using XML configuration file with
     * plugins description.
     *
     * See RegisterPlugins for more details.
     *
     * @param xmlConfigFile A path to .xml file with plugins to load from. If XML configuration file is not specified,
     * then default Inference Engine plugins are loaded from the default plugin.xml file.
     */
    explicit Core(const std::string& xmlConfigFile = std::string());

    /**
     * @brief Returns plugins version information
     *
     * @param deviceName Device name to indentify plugin
     * @return A vector of versions
     */
    std::map<std::string, Version> GetVersions(const std::string& deviceName) const;

    /**
     * @deprecated IErrorListener is not used anymore. An exception is thrown in case of any unexpected situations.
     * @brief Sets logging callback
     *
     * Logging is used to track what is going on inside the plugins, Inference Engine library
     *
     * @param listener Logging sink
     */
    IE_SUPPRESS_DEPRECATED_START
    INFERENCE_ENGINE_DEPRECATED("IErrorListener is not used anymore. An exception is thrown in case of any unexpected situations.")
    void SetLogCallback(IErrorListener& listener) const;
    IE_SUPPRESS_DEPRECATED_END

#ifdef ENABLE_UNICODE_PATH_SUPPORT
    /**
     * @brief Reads IR xml and bin files
     * @param modelPath path to IR file
     * @param binPath path to bin file, if path is empty, will try to read bin file with the same name as xml and
     * if bin file with the same name was not found, will load IR without weights.
     * @return CNNNetwork
     */
    CNNNetwork ReadNetwork(const std::wstring& modelPath, const std::wstring& binPath = std::wstring()) const {
        return ReadNetwork(details::wStringtoMBCSstringChar(modelPath), details::wStringtoMBCSstringChar(binPath));
    }
#endif

    /**
     * @brief Reads IR xml and bin files
     * @param modelPath path to IR file
     * @param binPath path to bin file, if path is empty, will try to read bin file with the same name as xml and
     * if bin file with the same name was not found, will load IR without weights.
     * @return CNNNetwork
     */
    CNNNetwork ReadNetwork(const std::string& modelPath, const std::string& binPath = "") const;
    /**
     * @brief Reads IR xml and bin (with the same name) files
     * @param model string with IR
     * @param weights shared pointer to constant blob with weights
     * @return CNNNetwork
     */
    CNNNetwork ReadNetwork(const std::string& model, const Blob::CPtr& weights) const;

    /**
     * @brief Creates an executable network from a network object.
     *
     * Users can create as many networks as they need and use
     *        them simultaneously (up to the limitation of the hardware resources)
     *
     * @param network CNNNetwork object acquired from CNNNetReader
     * @param deviceName Name of device to load network to
     * @param config Optional map of pairs: (config parameter name, config parameter value) relevant only for this load
     * operation
     * @return An executable network reference
     */
    ExecutableNetwork LoadNetwork(
        const CNNNetwork network, const std::string& deviceName,
        const std::map<std::string, std::string>& config = std::map<std::string, std::string>());

    /**
     * @brief Registers extension
     * @param extension Pointer to already loaded extension
     */
    void AddExtension(const IExtensionPtr& extension);

    /**
     * @brief Creates an executable network from a network object within a specified remote context.
     * @param network CNNNetwork object acquired from CNNNetReader
     * @param context Pointer to RemoteContext object
     * @param config Optional map of pairs: (config parameter name, config parameter value) relevant only for this load
     * operation
     * @return An executable network reference
     */
    ExecutableNetwork LoadNetwork(
        const CNNNetwork network, RemoteContext::Ptr context,
        const std::map<std::string, std::string>& config = std::map<std::string, std::string>());

    /**
     * @brief Registers extension for the specified plugin
     *
     * @param extension Pointer to already loaded extension
     * @param deviceName Device name to identify plugin to add an executable extension
     */
    void AddExtension(IExtensionPtr extension, const std::string& deviceName);

    /**
     * @brief Creates an executable network from a previously exported network
     *
     * @param deviceName Name of device load executable network on
     * @param modelFileName Path to the location of the exported file
     * @param config Optional map of pairs: (config parameter name, config parameter value) relevant only for this load
     * operation*
     * @return An executable network reference
     */
    ExecutableNetwork ImportNetwork(
        const std::string& modelFileName, const std::string& deviceName,
        const std::map<std::string, std::string>& config = std::map<std::string, std::string>());

    /**
     * @brief Creates an executable network from a previously exported network
     * @param deviceName Name of device load executable network on
     * @param networkModel network model stream
     * @param config Optional map of pairs: (config parameter name, config parameter value) relevant only for this load
     * operation*
     * @return An executable network reference
     */
    ExecutableNetwork ImportNetwork(std::istream& networkModel, const std::string& deviceName = {},
                                    const std::map<std::string, std::string>& config = {});

    /**
     * @brief Creates an executable network from a previously exported network within a specified
     * remote context.
     *
     * @param networkModel Network model stream
     * @param context Pointer to RemoteContext object
     * @param config Optional map of pairs: (config parameter name, config parameter value) relevant only for this load
     * operation
     * @return An executable network reference
     */
    ExecutableNetwork ImportNetwork(std::istream& networkModel,
                                    const RemoteContext::Ptr& context,
                                    const std::map<std::string, std::string>& config = {});

    /**
     * @brief Query device if it supports specified network with specified configuration
     *
     * @param deviceName A name of a device to query
     * @param network Network object to query
     * @param config Optional map of pairs: (config parameter name, config parameter value)
     * @return Pointer to the response message that holds a description of an error if any occurred
     */
    QueryNetworkResult QueryNetwork(
        const ICNNNetwork& network, const std::string& deviceName,
        const std::map<std::string, std::string>& config = std::map<std::string, std::string>()) const;

    /**
     * @brief Sets configuration for device, acceptable keys can be found in ie_plugin_config.hpp
     *
     * @param deviceName An optinal name of a device. If device name is not specified, the config is set for all the
     * registered devices.
     *
     * @param config Map of pairs: (config parameter name, config parameter value)
     */
    void SetConfig(const std::map<std::string, std::string>& config, const std::string& deviceName = std::string());

    /**
     * @brief Gets configuration dedicated to device behaviour.
     *
     * The method is targeted to extract information which can be set via SetConfig method.
     *
     * @param deviceName  - A name of a device to get a configuration value.
     * @param name  - value of config corresponding to config key.
     * @return Value of config corresponding to config key.
     */
    Parameter GetConfig(const std::string& deviceName, const std::string& name) const;

    /**
     * @brief Gets general runtime metric for dedicated hardware.
     *
     * The method is needed to request common device properties
     * which are executable network agnostic. It can be device name, temperature, other devices-specific values.
     *
     * @param deviceName - A name of a device to get a metric value.
     * @param name - metric name to request.
     * @return Metric value corresponding to metric key.
     */
    Parameter GetMetric(const std::string& deviceName, const std::string& name) const;

    /**
     * @brief Returns devices available for neural networks inference
     *
     * @return A vector of devices. The devices are returned as { CPU, FPGA.0, FPGA.1, MYRIAD }
       If there more than one device of specific type, they are enumerated with .# suffix.
     */
    std::vector<std::string> GetAvailableDevices() const;

    /**
     * @brief Register new device and plugin which implement this device inside Inference Engine.
     *
     * @param pluginName A name of plugin. Depending on platform pluginName is wrapped with shared library suffix and
     * prefix to identify library full name
     *
     * @param deviceName A device name to register plugin for. If device name is not specified, then it's taken from
     * plugin using InferenceEnginePluginPtr::GetName function
     */
    void RegisterPlugin(const std::string& pluginName, const std::string& deviceName);

    /**
     * @brief Unloads previously loaded plugin with a specified name from Inference Engine
     * The method is needed to remove plugin instance and free its resources. If plugin for a
     * specified device has not been created before, the method throws an exception.
     *
     * @param deviceName Device name identifying plugin to remove from Inference Engine
     */
    void UnregisterPlugin(const std::string& deviceName);

    /** @brief Registers plugin to Inference Engine Core instance using XML configuration file with
     * plugins description.
     *
     *  XML file has the following structure:
     *
     * ```xml
     * <ie>
     *     <plugins>
     *         <plugin name="" location="">
     *             <extensions>
     *                 <extension location=""/>
     *             </extensions>
     *             <properties>
     *                 <property key="" value=""/>
     *             </properties>
     *         </plugin>
     *     </plugins>
     * </ie>
     * ```
     *
     * - `name` identifies name of device enabled by plugin
     * - `location` specifies absolute path to dynamic library with plugin. A path can also be relative to inference
     * engine shared library. It allows to have common config for different systems with different configurations.
     * - Properties are set to plugin via the `SetConfig` method.
     * - Extensions are set to plugin via the `AddExtension` method.
     *
     * @param xmlConfigFile A path to .xml file with plugins to register.
     */
    void RegisterPlugins(const std::string& xmlConfigFile);

    /**
     * @brief Create a new shared context object on specified accelerator device
     * using specified plugin-specific low level device API parameters (device handle, pointer, etc.)
     * @param deviceName Name of a device to create new shared context on.
     * @param params Map of device-specific shared context parameters.
     * @return A shared pointer to a created remote context.
     */
    RemoteContext::Ptr CreateContext(const std::string& deviceName, const ParamMap& params);

    /**
     * @brief Get a pointer to default(plugin-supplied) shared context object for specified accelerator device.
     * @param deviceName  - A name of a device to get create shared context from.
     * @return A shared pointer to a default remote context.
     */
    RemoteContext::Ptr GetDefaultContext(const std::string& deviceName);
};
}  // namespace InferenceEngine
