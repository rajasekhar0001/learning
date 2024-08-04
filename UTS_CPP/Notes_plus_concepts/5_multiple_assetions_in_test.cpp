/**
 * Multiple assertions in a test case
 * -> Not preferred to use but we can use (Some ambiguity for the compiler)
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
    ASSERT_STRNE(val.c_str(), "raja");  // compiler will confuse to choose which one, it will go with one randomly, not preferred
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
} 