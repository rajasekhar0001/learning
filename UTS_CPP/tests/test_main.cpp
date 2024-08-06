#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/main.h"
#include "../src/class1.cpp"
// #include "../src/main.cpp"

// TEST(SampleTest, Test1) {
// 	EXPECT_EQ(1, 1);
// }

// TEST(SampleTest, Test2) {
// 	ASSERT_EQ(1, 2);

// }
// TEST(SampleTest2, Test1) {
// 	EXPECT_EQ(1, 1);
// }



using ::testing::_;
using ::testing::Return;
using ::testing::AtLeast;

class CheckTest : public Check{
    public:
	MOCK_METHOD(int , DoSomething, (int a), ());
};

TEST(CLASS1, TEST_001) {
	CheckTest mock;
	EXPECT_CALL(mock, DoSomethinig(_)).Times(AtLeast(1));

	mock.DoSomething(5);
}

TEST(ADD, TEST_001) {
	ASSERT_EQ(add(2, 5), 8);
}

TEST(ADD, TEST_002) {
	ASSERT_EQ(add(2, 5), 8);
}

int add(int a, int b) {
	a = change(a);
	return a+b;
}
int change(int a) {
	return a+1;
}

int main(int argc, char **argv) {
	    ::testing::InitGoogleTest(&argc, argv);
	        return RUN_ALL_TESTS();
}

