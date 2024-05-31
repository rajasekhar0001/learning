#include <iostream>
#include </workspaces/learning/uts_understanding/main.cpp>
#include </workspaces/learning/path/googletest/googlemock/include/gmock/gmock.h>
// #include <gtest/h>


using namespace std;
using ::testing::AtLeast; 
class Mock_Main : public MainClass {
    public:
    // MOCK_METHOD(int, checkType, 
    // MOCK_METHOD(int, checkType, (int num), ());

    MOCK_METHOD(int, checkType, (int num));
    // MOCK_METHOD({1:return_type}, {2:method_name}, ({3:args...}));

};