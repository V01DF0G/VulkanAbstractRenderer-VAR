set(PROJECT_NAME Sandbox)

add_executable(${PROJECT_NAME} src/main.cpp)

include_directories(${PROJECT_NAME} PUBLIC
    "${CMAKE_SOURCE_DIR}/VAR/src;")

add_dependencies(${PROJECT_NAME} VAR)

target_link_libraries(${PROJECT_NAME} PRIVATE VAR)