/**
 * 
 * Resurrectting public or protected members in case of private inheritance
 * Further to make use in next stage if inheritance as public or protected
 */

/**
 * Scenario
 * Consider there are  3 classes, A, B, C
 * A inherits B as private
 * B inherits C as piublic or private or protected
 * * In B, public and protected members are considered as protected and accessible but not private member
 * * In C, not possible to access private members in B class
 * * In C, to access public and proivate members in A, we use resurrecting in B
 * * Refer example
 * * resurrecting is possible for public and protected members of that particualr class's Base class
 * ***** using  -> BaseClass::member_name;
 */

#include <iostream>
using namespace std;

#include "Person.h"
#include "Engineer.h"
#include "ElectronicsEngineer.h"

int main() {
    // Person p;
    // Engineer e;
    ElectronicEngineer obj;
}