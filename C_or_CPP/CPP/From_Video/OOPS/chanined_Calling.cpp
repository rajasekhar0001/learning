#include <iostream>

using namespace std;

class Name {
    private:
    string name;
    string age;
    string village;

    public:
    Name* setName(string name) {
        this->name = name;
        return this;
    }

    Name* setAge(string age) {
        this->age = age;
        return this;
    }

    void print() {
        cout << "name: " << name << endl;
        cout << "Age : " << age << endl;
    }

};

int main() {
    Name *obj = new Name();
    obj->setName("raja")->setAge("22");

    obj->print();
}