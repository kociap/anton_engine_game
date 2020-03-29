cmake_minimum_required(VERSION 3.12)

project(anton_engine_game)
enable_language(CXX)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 17)

if(NOT DEFINED ANTON_ENGINE_SRC_DIR)
    message(FATAL "ANTON_ENGINE_SRC_DIR not set.")
endif()

add_subdirectory(${ANTON_ENGINE_SRC_DIR} "${CMAKE_CURRENT_BINARY_DIR}/GameEngine")
add_library(anton_engine_game SHARED)
target_link_libraries(anton_engine_game anton_engine)

add_subdirectory(generated)
add_subdirectory(scripts)

# Compiler flags
if("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU")
    set(GAME_DLL_EXPORT "")
    set(GAME_DLL_IMPORT "")
elseif("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
    if(NOT WIN32)
        set(GAME_DLL_EXPORT "")
        set(GAME_DLL_IMPORT "")
    else()
        set(GAME_DLL_EXPORT "__declspec(dllexport)")
        set(GAME_DLL_IMPORT "__declspec(dllimport)")
    endif()

elseif(MSVC)
    set(GAME_DLL_EXPORT "__declspec(dllexport)")
    set(GAME_DLL_IMPORT "__declspec(dllimport)")
endif()


target_compile_definitions(anton_engine_game 
    PRIVATE 
    ENGINE_API=${GAME_DLL_IMPORT}
    GAME_API=${GAME_DLL_EXPORT}
)

set_target_properties(anton_engine_game 
    PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/bin"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/bin"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/bin"
    LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/bin"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/bin"
    ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/bin"
    RUNTIME_OUTPUT_NAME_DEBUG "anton_engine_game_d"
    LIBRARY_OUTPUT_NAME_DEBUG "anton_engine_game_d"
    ARCHIVE_OUTPUT_NAME_DEBUG "anton_engine_game_d"
)
