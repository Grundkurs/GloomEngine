# --- LeeEngine3/Test/CMakeLists.txt ---

file(GLOB_RECURSE LEE_TEST_SOURCE "src/*.cpp")
file(GLOB_RECURSE LEE_TEST_HEADERS "include/*.h")

source_group("Headers" FILES ${LEE_TEST_HEADERS})

add_executable(LeeTest ${LEE_TEST_SOURCE} ${LEE_TEST_HEADERS})
target_link_libraries(LeeTest LeeEngine)
target_include_directories(LeeTest PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_BINARY_DIR}/include)