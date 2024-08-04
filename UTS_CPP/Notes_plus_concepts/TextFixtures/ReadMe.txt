For text fixtures, we use the macro TEST_F(structure_name, subtest_name) // structure name is mandatory
For test case, we use TEST(TEst_name, subtest_name)

What are Test Fixtures ?
Ans: Googletest framework provides support for fixtures as reusable components for all the tests that are part of a test case 

Ex: There will be three things in each test case
1) Arrange (Text fixtures are replace for this step), this step not required
2) Act
3) Assert