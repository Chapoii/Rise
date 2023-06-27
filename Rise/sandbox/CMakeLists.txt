set(TARGET_NAME Sandbox)

file(GLOB SANDBOX_HEADERS CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)
file(GLOB SANDBOX_SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SANDBOX_HEADERS} ${SANDBOX_SOURCES})

add_executable(${TARGET_NAME} ${SANDBOX_HEADERS} ${SANDBOX_SOURCES})

if(WIN32)
	add_compile_definitions("RS_PLATFORM_WINDOWS")
endif()
if(CMAKE_BUILD_TYPE MATCHES Debug)
	add_compile_definitions("RS_DEBUG")
endif()

set_target_properties(${TARGET_NAME} PROPERTIES CXX_STANDARD 17 OUTPUT_NAME "Sandbox")
set_target_properties(${TARGET_NAME} PROPERTIES FOLDER "Sandbox")

target_compile_options(${TARGET_NAME} PUBLIC "$<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/WX->")

target_link_libraries(${TARGET_NAME} RiseRuntime)

target_include_directories(
  ${TARGET_NAME} 
  PUBLIC $<BUILD_INTERFACE:${ENGINE_ROOT_DIR}/src>
  $<INSTALL_INTERFACE:include/${TARGET_NAME}-${PROJECT_VERSION}>
)

target_include_directories(
  ${TARGET_NAME} 
  PUBLIC $<BUILD_INTERFACE:${ENGINE_ROOT_DIR}/src/runtime>
  $<INSTALL_INTERFACE:include/${TARGET_NAME}-${PROJECT_VERSION}>
)

if(CMAKE_BUILD_TYPE MATCHES Release)
	set(POST_BUILD_COMMANDS
	  COMMAND ${CMAKE_COMMAND} -E make_directory "${BINARY_ROOT_DIR}"
	  COMMAND ${CMAKE_COMMAND} -E copy_directory "$<TARGET_FILE_DIR:${TARGET_NAME}>/" "${BINARY_ROOT_DIR}"
	)

	add_custom_command(TARGET ${TARGET_NAME} ${POST_BUILD_COMMANDS})
endif()
