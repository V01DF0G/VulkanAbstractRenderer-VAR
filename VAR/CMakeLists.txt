set(PROJECT_NAME VAR)

################################################################################
# Source groups
################################################################################

set(src
    "src/main.cpp"
)
source_group("src" FILES ${src})

set(src__Logger
    "src/Logger/Logger.cpp"
    "src/Logger/Logger.h"
)
source_group("src\\Logger" FILES ${src__Logger})

set(src__Precompiled
    "src/Precompiled/Pch.cpp"
    "src/Precompiled/Pch.h"
)
source_group("src\\Precompiled" FILES ${src__Precompiled})

set(src__Renderer
    "src/Renderer/Renderer.cpp"
    "src/Renderer/Renderer.h"
)
source_group("src\\Renderer" FILES ${src__Renderer})

set(src__Renderer__Base
    "src/Renderer/Base/VulkanBase.h"
)
source_group("src\\Renderer\\Base" FILES ${src__Renderer__Base})

set(src__Renderer__Device
    "src/Renderer/Device/LogicalDevice.cpp"
    "src/Renderer/Device/LogicalDevice.h"
    "src/Renderer/Device/PhysicalDevice.cpp"
    "src/Renderer/Device/PhysicalDevice.h"
)
source_group("src\\Renderer\\Device" FILES ${src__Renderer__Device})

set(src__Renderer__ImageViews
    "src/Renderer/ImageViews/ImageViews.cpp"
    "src/Renderer/ImageViews/ImageViews.h"
)
source_group("src\\Renderer\\ImageViews" FILES ${src__Renderer__ImageViews})

set(src__Renderer__Instances
    "src/Renderer/Instances/ApplicationInfo.h"
    "src/Renderer/Instances/Instance.cpp"
    "src/Renderer/Instances/Instance.h"
    "src/Renderer/Instances/ValidationLayers.cpp"
    "src/Renderer/Instances/ValidationLayers.h"
)
source_group("src\\Renderer\\Instances" FILES ${src__Renderer__Instances})

set(src__Renderer__ShaderModules
    "src/Renderer/ShaderModules/ShaderModule.h"
    "src/Renderer/ShaderModules/ShaderModule.cpp"
)
source_group("src\\Renderer\\ShaderModules" FILES ${src__Renderer__ShaderModules})

set(src__Renderer__Swapchain
    "src/Renderer/Swapchain/SwapChain.cpp"
    "src/Renderer/Swapchain/SwapChain.h"
)
source_group("src\\Renderer\\Swapchain" FILES ${src__Renderer__Swapchain})

set(src__Renderer__Utilities__CustomTypes
    "src/Renderer/Utilities/CustomTypes/QueueFamiliyIndices.h"
    "src/Renderer/Utilities/CustomTypes/SwapchainSupportDetails.h"
)
source_group("src\\Renderer\\Utilities\\CustomTypes" FILES ${src__Renderer__Utilities__CustomTypes})

set(src__Renderer__Utilities__FileManagment
    "src/Renderer/Utilities/FileManagment/readFile.cpp"
    "src/Renderer/Utilities/FileManagment/readFile.h"
    "src/Renderer/Utilities/FileManagment/GetSuffix.cpp"
    "src/Renderer/Utilities/FileManagment/GetSuffix.h"
    "src/Renderer/Utilities/FileManagment/GetShaderTypeString.h"
    "src/Renderer/Utilities/FileManagment/GetShaderTypeString.cpp"
)
source_group("src\\Renderer\\Utilities\\FileManagment" FILES ${src__Renderer__Utilities__FileManagment})

set(src__Renderer__Window
    "src/Renderer/Window/WindowMultiPlatform.cpp"
    "src/Renderer/Window/WindowMultiPlatform.h"
)
source_group("src\\Renderer\\Window" FILES ${src__Renderer__Window})

set(ALL_FILES
    ${src}
    ${src__Logger}
    ${src__Precompiled}
    ${src__Renderer}
    ${src__Renderer__Base}
    ${src__Renderer__Device}
    ${src__Renderer__ImageViews}
    ${src__Renderer__Instances}
    ${src__Renderer__ShaderModules}
    ${src__Renderer__Swapchain}
    ${src__Renderer__Utilities__CustomTypes}
    ${src__Renderer__Utilities__FileManagment}
    ${src__Renderer__Window}
)

add_executable(${PROJECT_NAME} ${ALL_FILES})

target_precompile_headers(${PROJECT_NAME} PRIVATE "src/Precompiled/Pch.h")

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")

set(ROOT_NAMESPACE VAR)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "Win32Proj"
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    TARGET_NAME_DEBUG   "VAR"
    TARGET_NAME_RELEASE "VAR"
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/../bin/Debug-windows-x86_64/VAR/"
    OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/../bin/Release-windows-x86_64/VAR/"
)

get_property(MSVC_RUNTIME_LIBRARY_DEFAULT TARGET ${PROJECT_NAME} PROPERTY MSVC_RUNTIME_LIBRARY)
string(CONCAT "MSVC_RUNTIME_LIBRARY_STR"
    $<$<CONFIG:Debug>:
        MultiThreadedDebugDLL
    >
    $<$<CONFIG:Release>:
        MultiThreadedDLL
    >
    $<$<NOT:$<OR:$<CONFIG:Debug>,$<CONFIG:Release>>>:${MSVC_RUNTIME_LIBRARY_DEFAULT}>
)
set_target_properties(${PROJECT_NAME} PROPERTIES MSVC_RUNTIME_LIBRARY ${MSVC_RUNTIME_LIBRARY_STR})

target_include_directories(${PROJECT_NAME} PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Logger;"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer;"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer/Base;"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer/Buffers;"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer/Device;"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer/Errors;"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer/ImageViews;"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer/Instances;"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer/ShaderModules;"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer/Pipelines;"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer/ShaderModules;"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer/Swapchain;"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer/Utilities;"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer/Window;"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer/Utilities/CustomTypes;"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer/Utilities/FileManagment;"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer/Utilities/Functions;"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer/Utilities/Math;"
    "${CMAKE_CURRENT_SOURCE_DIR}/Vendor/spdlog/include;"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Precompiled;"
    "${GLFW_INCLUDE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/Vendor/Vulkan/Include;"
    "${CMAKE_CURRENT_SOURCE_DIR}/Vendor/glm;"
)


target_compile_definitions(${PROJECT_NAME} PRIVATE
    "$<$<CONFIG:Debug>:"
        "DEBUG"
    ">"
    "$<$<CONFIG:Release>:"
        "NDEBUG"
    ">"
    "_CRT_SECURE_NO_WARNINGS;"
    "GLFW_INCLUDE_NONE;"
    "UNICODE;"
    "_UNICODE"
)

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Debug>:
            /Od;
            /ZI
        >
        $<$<CONFIG:Release>:
            /Ox;
            /Oi;
            /GF;
            /Gy;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
        >
        /MP;
        /std:c++17;
        /Gm-;
        /W3;
        ${DEFAULT_CXX_EXCEPTION_HANDLING}
    )
    target_link_options(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Debug>:
            /DEBUG;
            /INCREMENTAL
        >
        $<$<CONFIG:Release>:
            /DEBUG:FULL;
            /OPT:REF;
            /OPT:ICF;
            /INCREMENTAL:NO
        >
        /SUBSYSTEM:CONSOLE
    )
endif()


add_dependencies(${PROJECT_NAME} glfw )

# Link with other targets.
target_link_libraries(${PROJECT_NAME} PRIVATE
    glfw
)

set(ADDITIONAL_LIBRARY_DEPENDENCIES
    "vulkan-1"
)
target_link_libraries(${PROJECT_NAME} PRIVATE "${ADDITIONAL_LIBRARY_DEPENDENCIES}")

target_link_directories(${PROJECT_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Vendor/Vulkan/Lib"
)

