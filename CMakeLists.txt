cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY $<1:${CMAKE_BINARY_DIR}/bin>)

if(WIN32)
set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
endif()

project(vk_demo)

find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)
find_package(Vulkan REQUIRED)

make_directory(${CMAKE_BINARY_DIR}/bin/shaders)
execute_process(
  COMMAND glslc ${CMAKE_SOURCE_DIR}/src/shaders/shader.vert
             -o ${CMAKE_BINARY_DIR}/bin/shaders/vert.spv
  )
execute_process(
  COMMAND glslc ${CMAKE_SOURCE_DIR}/src/shaders/shader.frag
             -o ${CMAKE_BINARY_DIR}/bin/shaders/frag.spv
  )
file(
  COPY ${CMAKE_SOURCE_DIR}/resources/textures/
  DESTINATION ${CMAKE_BINARY_DIR}/bin/textures/
  )
file(
  COPY ${CMAKE_SOURCE_DIR}/resources/models/
  DESTINATION ${CMAKE_BINARY_DIR}/bin/models/
  )

add_executable(
  ${PROJECT_NAME}
  src/HelloTriangleApplication.cpp
  src/main.cpp
  )

target_include_directories(
  ${PROJECT_NAME}
  PRIVATE
  include
  ${Vulkan_INCLUDE_DIR}
  )

target_link_libraries(
  ${PROJECT_NAME}
  PRIVATE
  glfw
  ${Vulkan_LIBRARIES}
  )
