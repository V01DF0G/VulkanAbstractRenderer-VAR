set(PROJECT_NAME Sandbox)

add_executable(${PROJECT_NAME} src/main.cpp)

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")

set(ROOT_NAMESPACE Sandbox)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "Win32Proj"
)

include_directories(${PROJECT_NAME} PUBLIC
    "${CMAKE_SOURCE_DIR}/VAR/src;")


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

add_dependencies(${PROJECT_NAME} VAR)

target_link_libraries(${PROJECT_NAME} PRIVATE VAR)