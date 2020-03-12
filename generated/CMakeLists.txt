set(HEADER_FILES
)

set(SOURCE_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/component_serialization_funcs.generated.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/systems.generated.cpp"
)

target_sources(${PROJECT_NAME} 
    PRIVATE ${HEADER_FILES}
    PRIVATE ${SOURCE_FILES}
)