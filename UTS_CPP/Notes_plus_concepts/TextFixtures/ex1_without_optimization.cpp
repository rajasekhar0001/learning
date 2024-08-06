/**
 * Text Fixtures
 * Solution to place the code under "Arrange" which is common code in all test cases in Structure and passing structure name as
   first argument in TEST_F()
 * COmmon code is like intilizaton code
 */

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Increment {
    int value;
    public:
    Increment(int val) {
        value = val;
    }

    int incrementByValue(int val) {
        value += val;
        return value;
    }

};

TEST(WITHOUT_FIXTURE, INCREMENT_BY_5) {
    // Arrange
    Increment obj(10);  // kind  of initialization which is duplicate in all test case of incrementbyvalue

    //Act
    int value = obj.incrementByValue(5);

    //ASSERT
    ASSERT_EQ(value, 15);
}

TEST(WITHOUT_FIXTURE, INCREMENT_BY_10) {
    // Arrange
    Increment obj(10);  // duplicate
    // solution for these duplicates 

    //Act
    int value = obj.incrementByValue(10);

    //ASSERT
    ASSERT_EQ(value, 20);
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}