set(SRCS_DIR "src")

file(GLOB_RECURSE CPP_SRCS "${SRCS_DIR}/*.cpp")
file(GLOB_RECURSE C_SRCS "${SRCS_DIR}/*.c")

idf_component_register(
    SRCS
        ${C_SRCS}
        ${CPP_SRCS}
    INCLUDE_DIRS
        ${SRCS_DIR}
    REQUIRES
        esp-io-expander
        lvgl
        esp32_display_panel
)

target_compile_options(${COMPONENT_LIB} PRIVATE -Wno-missing-field-initializers -Wno-narrowing)
