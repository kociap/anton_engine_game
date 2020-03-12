set(HEADER_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/asteroid.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/projectile.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/spaceship.hpp"
)

set(SOURCE_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/asteroid.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/projectile.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/spaceship.cpp"
)

target_include_directories(${PROJECT_NAME}
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_sources(${PROJECT_NAME} 
    PRIVATE ${HEADER_FILES}
    PRIVATE ${SOURCE_FILES}
)