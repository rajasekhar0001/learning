#ifndef ELECTRONICS_ENGINEER_H
#define ELECTRONICS_ENGINEER_H

#include "Engineer.h"

class ElectronicEngineer : private Engineer {
    public:
    ElectronicEngineer() {
        cout << "Electronics ENginner cinstructor called\n";

        // cout << "name : " << m_name << endl;
        cout << "age : " << m_age << endl;
        cout << "id: " << m_id << endl;
        cout << "sum : " << add(2, 8) << endl;    // not accessble since prvate in Enginner class
                                                // Possible to call by resurrecting it in Engineer class as public or protected
     }

    ~ElectronicEngineer() {
        cout << "ElectronicEngineer destructor called\n";
    }
};

#endif