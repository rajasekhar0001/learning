#include <gtest/gtest.h>

TEST(SampleTest, Test1) {
	EXPECT_EQ(1, 1);
}

TEST(SampleTest, Test2) {
	ASSERT_EQ(1, 2);

}
TEST(SampleTest2, Test1) {
	EXPECT_EQ(1, 1);
}

int main(int argc, char **argv) {
	    ::testing::InitGoogleTest(&argc, argv);
	        return RUN_ALL_TESTS();
}

