/**
 * Using Text Fixtures i.e., TEST_F()
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

// Strcture needs to be used

struct MyIncrementTest : public testing::Test {
    Increment *obj;
    void SetUp() {
        // Keep common code here
        // cout << "ALive\n";
        obj = new Increment(10);
    }  
    void TearDown() {
        // dealocate used memory if any
        // cout << "Dead\n";
        delete obj;
    }
};

TEST_F(MyIncrementTest, INCREMENT_BY_5) {
    //Act
    int value = obj->incrementByValue(5);

    //ASSERT
    ASSERT_EQ(value, 15);
}

TEST_F(MyIncrementTest, INCREMENT_BY_10) {

    //Act
    int value = obj->incrementByValue(10);

    //ASSERT
    ASSERT_EQ(value, 20);
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}