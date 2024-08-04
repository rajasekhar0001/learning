/**
 * Non Fatal Failure : ASSERTIONS using EXEPCT_EQ, EXPECT_TRUE, etc.
 * ASSERTIONS starting with "EXPECT_*" will cause NOn_fatala_failures
 * In a test case, even if ASSERTION fails, lines after ASSERTION will be printed
 */

#include <iostream>
#include <gtest/gtest.h>

using namespace std;


TEST(TEST1, SUBTEST1) {
    EXPECT_TRUE(1==1); // assertion success
    cout << "AFTER Assertion success\n"; // will be printed
}

TEST(TEST1, SUBTEST2) {
    EXPECT_FALSE(1==1); // assertion fails
    cout << "AFTER Assertion fails\n"; // It will also be printed
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
} 