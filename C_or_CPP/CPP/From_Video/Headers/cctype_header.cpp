/**
 * cctype header -> contains function which works on character
 * * like std::isalnum(), std::isdigit(), etc.
 * ** These function return 1 or 0
 */
/**
 * Few example
 * std::isblank() -> checks whethet a character is blank or not (space or not)
 * std::isdigit() -> digit or not
 * std::islower() -> to check lower or not
 * std::isupper() -> to check upper or not
 * std::isalpha() -> alphanumeric or not
 * std::ispunct() -> checks chracter is punctuation character or not
 */

/**
 * std::size() -> introduced in c++ 17
 * can be used to calculate size of array, string and collections like list, vector, etc.
 */

#include <iostream>
#include <cctype>
// In c it present with name as "cctype.h"

#include <vector>

int main() {

    std::cout << "* is digit : " << std::isdigit('*') << std::endl;

    std::cout << "'2' is digit : " << std::isdigit('2') << std::endl;

    if (std::isalnum('C')) {
        std::cout << "'C' is Alphanumeric\n";
    }
    else
    {
        std::cout << "C isNOt alphanumeric\n";
    }

    if (std::isalnum('^')) {
        std::cout << "^ is Alphanumeric\n";
    }
    else
    {
        std::cout << "^ is NOt alphanumeric\n";
    }

    // chacking usage of std::size() function

    std::string s {"helo"};

    std::cout << "size of string : " << std::size(s) << std::endl;

    std::vector<int> v{1, 2, 3};
    std::cout << "size of vector : " <<  std::size(v) << std::endl;

    int arr[] = {1, 2, 3};

    std::cout << "size of array: " << std::size(arr) << std::endl;

    char *str = "hh"; // not allowed to use std::size() with char*
    std::cout << "size of char* : " << sizeof(str) << std::endl;
}