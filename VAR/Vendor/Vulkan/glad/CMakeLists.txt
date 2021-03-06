set(PROJECT_NAME glad)


add_library(${PROJECT_NAME} STATIC "include/vk_platform.h" "include/glad/vulkan.h" "src/vulkan.c")

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include;")