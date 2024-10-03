#ifndef ENGINEER_H
#define ENGINEER_H
#include "Person.h"

class Engineer : public Person {
    public:
    // int x;
    Engineer () {
        cout << "Enginner constructor called\n";
        // cout << "Name : " << m_name << endl;
        cout << "Age : " << m_age << endl;
        cout << "Roll No: " << m_id << endl;
        cout << "sum : " << add(1, 2) << endl;

    }

    ~Engineer() {
        cout << "ENgineer destructor called\n";
    }

    // Resurrecting members
    protected:
    using Person::m_id;
    using Person::m_age;
    using Person::add;

    // using Person::m_name; // Compilation error, can't be used this way with private member
};

#endif 