add_executable(tests main.cpp)

target_link_libraries(tests PUBLIC list heap)

target_include_directories(tests PUBLIC "${PROJECT_SOURCE_DIR}/list" "${PROJECT_SOURCE_DIR}/heap")