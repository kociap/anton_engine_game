cmake_minimum_required(VERSION 3.12)

project(GameEngine_Game)
enable_language(CXX)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 17)

set(GAME_ENGINE_DIRECTORY "C:/Users/An0num0us/Documents/GameEngine")
add_subdirectory(${GAME_ENGINE_DIRECTORY} "${CMAKE_CURRENT_BINARY_DIR}/GameEngine")
add_library(${PROJECT_NAME} SHARED)
target_link_libraries(${PROJECT_NAME} anton_engine)

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


target_compile_definitions(${PROJECT_NAME} 
    PRIVATE 
    ENGINE_API=${GAME_DLL_IMPORT}
    GAME_API=${GAME_DLL_EXPORT}
)

set_target_properties(${PROJECT_NAME} 
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
    RUNTIME_OUTPUT_NAME_DEBUG "GameEngine_Gamed"
    LIBRARY_OUTPUT_NAME_DEBUG "GameEngine_Gamed"
    ARCHIVE_OUTPUT_NAME_DEBUG "GameEngine_Gamed"
)