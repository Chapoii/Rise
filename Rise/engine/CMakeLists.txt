set(ENGINE_ROOT_DIR "${RISE_ROOT_DIR}/Rise/engine")
set(THIRD_PARTY_DIR "${ENGINE_ROOT_DIR}/3rdparty")

add_subdirectory(3rdparty)
add_subdirectory(src/runtime)
add_subdirectory(src/editor)
