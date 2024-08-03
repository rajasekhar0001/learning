/**
 * C++ style  -> str.find(string_type, fromPos (optional));
 * C style    -> str.find(char*_type, fromPos(optional));
 */

#if 1
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s = "This is what I know. Can you check from your side once? can";
    string s_fmt = "izs";
    char* c_fmt = "is";

    unsigned long ret = s.find(s_fmt, 0);
    cout << string::npos  << "  "  << ret << endl;
}
#else
// fromm geek for geeks
#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, world!";
    std::size_t found = str.find("wor5ld");

    if (found != std::string::npos) {
        std::cout << "'world' found at position: " << found << std::endl;
    } else {
        std::cout << "'world' not found" << std::endl;
    }

    return 0;
}
#endif
