/**
 * std::flush()  -> causes immediate sending of data from buffere to to the terminal or connected stream
 * std::setprecision() -> To set the presision fr float 
 * std::setw()   -> To fill x characters in the number of spaces provided in setw()
 * std::right    -> default justification is right
 * std::left     -> We can specify left justification
 * std::internal -> right and left justification applies to all types while internal justification applies to integer, float and monetary o/p
 * std::setfill() -> To fill empty spaces with some character when using setw()
 * std::boolalpha -> to print true and false instead of 1 and 0
 * std::showpos -> To show + sign infront of a positive number
 * std::noshowpos -> Not tot show + sign 
 * std::hex
 * std::oct
 * std::dec
 * std::hexfloat -> to show float or double in hex form
 * std::uppercase  -> to show hexa form in uppercase
 * 
 *  Float notation using below
 * * std::scientific
 * * std::fixed
 * 
 * 
 * ** Note: Above all must be used with cout, else no use. but flush can be used alone.
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    #if 0
    // std::flush  (Rules same as in C)
    cout << "Hello Raja ";
    // std::flush(cout);
    // OR
    cout << "Hello All" << std::flushl
    while (1);

    #elif 0
    // std::setw  (right justification is default)
    cout << "setw() using right justifucation\n";
    cout << setw(15) << "Raja" << setw(15) << "mahesh" << endl;
    cout << setw(15) << "rajasekhar" << setw(15) << "bhaskar" << endl;

    // std::setw
    cout << "/nsetw() using left justifucation\n";
    cout << std::left;
    cout << setw(15) << "Raja" << setw(15) << "mahesh" << endl;
    cout << setw(15) << "rajasekhar" << setw(15) << "bhaskar" << endl;

    // std::setw 
    cout << "/nsetw() using internal justification justifucation\n";
    cout << std::internal;
    cout << setw(15) << "Raja" << setw(15) << "mahesh" << endl;
    cout << setw(15) << "rajasekhar" << setw(15) << "bhaskar" << endl;
    #endif

    #if 0
    // std::internal justification
    // default std::right
    cout << setw(15) << -1.5 << endl;
    cout << setw(15) << 4 << endl << endl;

    // observe carefully
    cout << std::internal;
    cout << setw(15) << -1.5 << endl;  // o/p:  -               15
    cout << setw(15) << 4 << endl;
    #endif

    #if 0
    // std::setfill()
    cout << setfill('_') << left;
    cout << setw(15) << "Raja" << setw(15) << "mahesh" << endl;
    cout << setw(15) << "rajasekhar" << setw(15) << "bhaskar" << endl;
    #endif

    #if 0
    // std::boolalpha
    bool statusf {true};
    bool statuss(false);
    cout << "without using boolalpha" << endl;
    cout << statusf << endl;
    cout << statuss << endl;

    cout << "Using bool alpha "<< endl;
    cout << boolalpha;
    cout << statusf << endl;
    cout << statuss << endl;
    
    #endif

    #if 0
    // show sign (poitive sign as weell)
    // std::showpos
    // std::noshowpos
    int integer {14};
    int negative {-15};
    double doubleval {418.45};
    cout << "integer : " << integer << endl;
    cout << "negative int: " << negative << endl;
    cout << "double val: " << doubleval << endl;

    // std::showpos -> shows postibe sign
    cout << showpos;
    cout << "integer : " << integer << endl;
    cout << "double val: " << doubleval << endl;
    cout << noshowpos;
    cout << "integer : " << integer << endl;
    #endif

    #if 1
    // To show in differenent formats
    // std::hex
    // std::oct
    // std::dec
    int integer {14};
    int negative {-15};
    double doubleval {418.45};
    cout << "integer : " << dec <<  integer << endl;
    cout << "integer hex: " << hex <<  integer << endl; 
    cout << "integer oct: " << oct << integer << endl; 


    cout << "double  : " << dec <<  doubleval << endl;
    cout << "double hex: " << hexfloat <<  doubleval << endl;   // hex can't be used for float, hexfloat needs to be used
    cout << "double oct: " << oct << doubleval << endl; // not showinng in oct form

    int num = 0b00001111;
    cout << "\ndecimal form : " << dec << num << endl;

    // To print hexadecimal in uppercase
    cout << uppercase;
    cout << "hex in uppercase: " << hex <<  integer << endl;   // hex can't be used for float, hexfloat needs to be used
    #endif

}