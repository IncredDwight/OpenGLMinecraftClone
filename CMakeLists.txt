cmake_minimum_required(VERSION 3.15)
project(MinecraftClone LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- OpenGL ---
find_package(OpenGL REQUIRED)

# --- GLEW ---
find_package(GLEW REQUIRED)

# --- GLFW ---
find_package(glfw3 REQUIRED)

file(GLOB_RECURSE SRC_FILES
    ${CMAKE_SOURCE_DIR}/source/*.cpp
)
list(FILTER SRC_FILES EXCLUDE REGEX "/glm/")
list(FILTER SRC_FILES EXCLUDE REGEX "stb-master/tests/")
add_executable(MinecraftClone
    main.cpp
    ${SRC_FILES}
)

target_include_directories(MinecraftClone PRIVATE
    ${OPENGL_INCLUDE_DIRS}
    ${GLEW_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/source
)

target_link_libraries(MinecraftClone PRIVATE
    OpenGL::GL
    GLEW::GLEW
    glfw
)

# Copy assets
file(COPY ${CMAKE_SOURCE_DIR}/resources
     DESTINATION ${CMAKE_BINARY_DIR})

