/**
 * std::string  -> stores the string inside a character array but we dont need to worry about that
 */

#include <iostream>

int main() {
    std::string s; // string declaration without initialization
    std::string initalizer {"Hello Raja! How are you?"}; // with intialization (using = also, we can initialize)

    std::string  assign{initalizer};    // Initialize with other existing string
    std::cout << assign << std::endl;

    std::string copy_str (4, 'e');      // Initilise with multiple copies of char
    // use paranthesis which corrcetly calls the string constructor
    std::cout << "copy_str : " << copy_str << std::endl;

    std::string str {"Hello World!"};
    // --------------------------------------------------------------------
    std::string saying_hello {"Hello World", 5}; // Initialize with first 5 chrcaters of string literal
    std::cout << "saying_hello : " << saying_hello << std::endl;
    std::string difference_from {str, 3};   // Initialise from 3rd chracter to last
    std::cout << "difference_from : " << difference_from << std::endl;
    // ----------------------------------------------------------------------

    std::string saying_world {str, 6, 5}; // Initialize from 6th character, 5 characters in str
    std::cout << "saying_world : " << saying_world << std::endl;

    // assigned new string at run time, this not possible with chracter array
    char array_str[] = {"Hello raja"}; // not possible to assign some other array of characters

    // with char pointer possible, but sufficient memory should be there
    char *ptr_str = "Hello";    // The memory allocated for this wasted
    ptr_str = "New string Hello";   // new mory being used

    // string allocates memory in some other place, more flexible to use
    std::string using_string  {"Hello"}; // memory allocated here being deallocated
    using_string = "Hello frinds, All are doing good ?";    // Oreferrabke to use, memory efficient
    std::cout << using_string << std::endl;

}