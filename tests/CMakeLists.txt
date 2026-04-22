add_executable(greeter_test greeter_test.cpp)
target_include_directories(greeter_test PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(greeter_test GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(greeter_test)
