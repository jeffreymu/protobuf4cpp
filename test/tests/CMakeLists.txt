add_executable(run_actual_tests
        ../../src/Source/IamAClass.cpp
        jeff_test.cpp
        testFILE_1.cpp
        testFILE_2.cpp)

target_link_libraries(run_actual_tests gtest gtest_main)
target_link_libraries(run_actual_tests gmock gmock_main)
