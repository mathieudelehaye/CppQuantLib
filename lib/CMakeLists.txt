set(LIB_NAME CppQuantLib)

file(GLOB_RECURSE LIB_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/common/*.cpp"
)

add_library(${LIB_NAME} SHARED ${LIB_SOURCES})

target_include_directories(${LIB_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_definitions(${LIB_NAME} PRIVATE MYLIBRARY_EXPORTS)

# Copy built .so to ../output/lib
add_custom_command(
    TARGET ${LIB_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory
            ${CMAKE_SOURCE_DIR}/../output/lib
    COMMAND ${CMAKE_COMMAND} -E copy
            $<TARGET_FILE:${LIB_NAME}>
            ${CMAKE_SOURCE_DIR}/../output/lib/
)
