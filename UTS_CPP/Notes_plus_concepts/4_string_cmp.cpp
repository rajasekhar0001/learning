/**
 * To compare strings EXPECT_STREQ or ASSERT_STREQ  --> preferred to compare strings
 * similarly, EXPECT_STRNQ, etc
 * 
 * But we can use normal ones also like EXPECT_EQ  -> usualy preferred to compare inegral type npt strings but it will work
 * 
 * NOte:
 * "raja" -> c_style string, if directly used without assigning to string type
 * string s = "raja"  -> cpp style string
 */

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class MyTest {
    string s;
    public:
    MyTest(string ss) {
        s = ss;
    }
    string getId() {
        return s;
    }
};


TEST(TEST1, SUBTEST1) {
    //Arrange
    MyTest obj("raja");

    //Act (some operation)
    string val= obj.getId();

    // Assert
    ASSERT_STREQ(val.c_str(), "raja");
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
} 