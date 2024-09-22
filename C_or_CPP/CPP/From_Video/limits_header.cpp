#include <iostream>
#include <limits>

using namespace std;

int main() {
    cout << "short range from " << numeric_limits<short>::min() << " to " << numeric_limits<short>::max() << endl;

    cout << "unsigned int range from " << numeric_limits<unsigned int>::min() << " to " << numeric_limits<unsigned int>::max() << endl;

    cout << "Float range from " << numeric_limits<float>::min() << " to "<< numeric_limits<float>::max() << endl;
}