cmake_minimum_required(VERSION 3.10)
project(ProgramN30)
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
find_package(OpenGL REQUIRED)
add_subdirectory(dependencies/glfw)
include_directories(dependencies/glad/include)
add_executable(ProgramN30
    src/main.c
    dependencies/glad/src/glad.c
)
add_custom_target(copy_assets
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_CURRENT_SOURCE_DIR}/shaders"
        "${CMAKE_CURRENT_BINARY_DIR}/shaders"
)
add_dependencies(ProgramN30 copy_assets)
target_include_directories(ProgramN30 PRIVATE dependencies)
target_link_libraries(ProgramN30
    OpenGL::GL
    glfw
)
