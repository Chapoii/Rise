if(WIN32)
    add_compile_options("/MP")
    set_property(DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Sandbox)
endif()

add_subdirectory(engine)
add_subdirectory(sandbox)
