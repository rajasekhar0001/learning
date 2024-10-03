#ifndef PERSON_H
#define PERSON_H

class Person {
    private:
    string m_name {"Rajasekhar"};

    public:
    int m_age {22};

    Person ();

    ~Person() {
        cout << "Person destructor called\n";
    }

    int add (int a, int b) const {
        return a + b;
    }

    protected:
    
    int m_id {1};

};

Person::Person() {
    cout << "Person constructor called\n";
    cout << "name : " << m_name << endl;
    cout << "Age " << m_age << endl;
    cout << "Id: " << m_id << endl;
}

#endif