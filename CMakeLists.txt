cmake_minimum_required(VERSION 3.10)
project(game-engine CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_VS_PLATFORM_NAME}/)

#include folder
include_directories("${PROJECT_SOURCE_DIR}/game-engine/src")
include_directories("${PROJECT_SOURCE_DIR}/game-engine/src/Engine")
include_directories("${PROJECT_SOURCE_DIR}/game-engine/src/Engine/Events")

#find files
file(GLOB TOP_LEVEL_ENGINE "${PROJECT_SOURCE_DIR}/game-engine/src/*.cpp")
file(GLOB DEEP_LEVEL_ENGINE "${PROJECT_SOURCE_DIR}/game-engine/src/Engine/*cpp")
file(GLOB EVENT_ENGINE "${PROJECT_SOURCE_DIR}/game-engine/src/Engine/Events/*cpp")
file(GLOB TOP_LEVEL_ENGINE_H "${PROJECT_SOURCE_DIR}/game-engine/src/*.h")
file(GLOB DEEP_LEVEL_ENGINE_H "${PROJECT_SOURCE_DIR}/game-engine/src/Engine/*h")
file(GLOB EVENT_ENGINE_H "${PROJECT_SOURCE_DIR}/game-engine/src/Engine/Events/*.h")

#set var
set (SOURSES    ${TOP_LEVEL_ENGINE}     ${DEEP_LEVEL_ENGINE} 
                ${TOP_LEVEL_ENGINE_H}   ${DEEP_LEVEL_ENGINE_H}
                ${EVENT_ENGINE}         ${EVENT_ENGINE_H})

set (PRECOMPILE_HEADER ${PROJECT_SOURCE_DIR}/game-engine/src/mbpch.h)

#message(WARNING "Files: ${EVENT_ENGINE_H}")

#set sourse group
source_group("Source Files/src/" FILES ${TOP_LEVEL_ENGINE} ${TOP_LEVEL_ENGINE_H})
source_group("Source Files/src/Engine" FILES ${DEEP_LEVEL_ENGINE} ${DEEP_LEVEL_ENGINE_H})
source_group("Source Files/src/Engine/Events" FILES ${EVENT_ENGINE} ${EVENT_ENGINE_H})

#build lib
add_library(Maybe SHARED ${SOURSES})

#setup defenition
target_compile_definitions(Maybe PRIVATE MB_PLATFORM_WINDOWS)
target_compile_definitions(Maybe PRIVATE MB_BUILD_DLL)

#add include directory
target_include_directories(Maybe PRIVATE "${PROJECT_SOURCE_DIR}/game-engine/vendor/spdlog/include")

#remove ZERO_CHECK solution and hide ALL_BUILD into folder
set(CMAKE_SUPPRESS_REGENERATION true)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

target_precompile_headers(Maybe PRIVATE ${PRECOMPILE_HEADER})

# __________________________________________________________________________________________________________________________________________________


cmake_minimum_required(VERSION 3.10)
project(Sandbox CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#include folder
include_directories("${PROJECT_SOURCE_DIR}/Sandbox/src")

#find files
file(GLOB ClientFiles "${PROJECT_SOURCE_DIR}/Sandbox/src/*.cpp")

#set sourse group
source_group("Source Files/src/" FILES ${ClientFiles})

#create executable
add_executable(Sandbox ${ClientFiles})

#setup defenition
target_compile_definitions(Sandbox PUBLIC MB_PLATFORM_WINDOWS)

#add include directory
target_include_directories(Sandbox PRIVATE "${PROJECT_SOURCE_DIR}/game-engine/src")
target_include_directories(Sandbox PRIVATE "${PROJECT_SOURCE_DIR}/game-engine/vendor/spdlog/include")

#remove ZERO_CHECK solution and hide ALL_BUILD into folder
set(CMAKE_SUPPRESS_REGENERATION true)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Sandbox)

target_link_libraries(Sandbox PRIVATE Maybe)

target_precompile_headers(Sandbox PRIVATE ${PRECOMPILE_HEADER})