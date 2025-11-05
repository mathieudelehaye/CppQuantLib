set(EXE_NAME FintechExecutable)
add_executable(${EXE_NAME} libExecutable.cpp)

# Path to the shared output directory
set(OUTPUT_DIR ${CMAKE_SOURCE_DIR}/../output)

# Include headers from the lib project
target_include_directories(${EXE_NAME}
    PRIVATE
        ${CMAKE_SOURCE_DIR}/../lib/include
)

# Link against the prebuilt shared library in output/lib
target_link_libraries(${EXE_NAME}
    PRIVATE
        ${OUTPUT_DIR}/lib/libCppQuantLib.so
)
