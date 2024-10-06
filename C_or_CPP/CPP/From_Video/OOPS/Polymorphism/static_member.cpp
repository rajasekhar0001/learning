/**
 * static member varaible
 */

#include <iostream>
using namespace std;

class Shape {
    public:
    static int m_count;
    Shape() {
        m_count++;
    }
};

class Circle : public Shape {
    public:
    //  static int m_x;
};

int Shape::m_count = 0;
// int Shape::m_count = 5;

int main() {
    Shape::m_count = 5;
    cout << "Before creating objects: m_count : "  << Shape::m_count << endl;
    Shape s1;
    cout << "s1 -> m_Count : " << Shape::m_count << endl;
    Circle c1;
    cout << "cq -> m_count : " << Circle::m_count << endl;
    // Circle
    // cout << "declaration with intilization: " << Circle::m_x << endl;
    // Circle::m_x = 5;
    // cout << "declaration with intilization: " << Circle::m_x << endl;
}