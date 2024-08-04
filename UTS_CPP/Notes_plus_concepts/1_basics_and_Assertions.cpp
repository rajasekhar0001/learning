/**
 * TEST(TEST, SUBTEST); 
 * -> TEST can be function name
 * -> SUbTest can be one test case of that function
 */

#include <iostream>
#include <gtest/gtest.h>

using namespace std;


TEST(TEST1, SUBTEST1) {
    ASSERT_TRUE(1==1);
}

TEST(TEST1, SUBTEST2) {
    ASSERT_FALSE(1==1);
}

TEST(TEST2, SUBTEST1) {
    ASSERT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
} 