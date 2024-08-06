/**
 * FATAL failure occurs if we use -> ASSERT_EQ, ASSERT_TRUE, etc
 *  Assertions starting with "ASSERT_*"  will cause FAtal_failure
 * in a test case if assertion fails, the lines after ASSERtion will not be executed
 */
#include <iostream>
#include <gtest/gtest.h>

using namespace std;


TEST(TEST1, SUBTEST1) {
    ASSERT_TRUE(1==1); // ASSERTION success
    cout << "AFTER succeeded ASSERTION" << endl;    // it will be printed
}

TEST(TEST2, SUBTEST1) {
    ASSERT_EQ(1, 2);    // ASSERTION will fail
    cout << "After failed ASSERTION" << endl; // it will not be printed
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
} 