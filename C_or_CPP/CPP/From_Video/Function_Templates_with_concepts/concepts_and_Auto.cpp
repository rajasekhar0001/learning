/**
 * concept and auto
 * We can you use built in concept in normal code as well but those are strict
 */

#include <iostream>
#include <concepts>

using namespace std;

// This syntax contains auto parameters you pass in
// to comply with std::integral concept
std::integral auto add (std::integral auto a, std::integral auto b) {
    return a + b;
}

int main() {
    // std::floating_point auto v = add(5, 6); // error since the return type of add is int in this case

    std::integral auto v = add(3, 7);  // allowed but no use

    std::floating_point auto v1 = 7.3; // allowed but no use

}