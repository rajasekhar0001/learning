// Ex: for b)
// Factory method design pattern 

#include <iostream>
using namespace std;

class Parent {
    public:
    virtual void job () = 0;
};

class Child1 : public Parent {
    public:
    void job() {
        cout << "working as Embedded developer\n";
    }
};

class Child2 : public Parent {
    public:
    void job() {
        cout << "Working as Software engineer\n";
    }
};

class Client {
    Parent *p = NULL;
    public:
    Client(int option) {
        if (option == 1) 
            p = new Child1();
        else if (option ==2 )
            p = new Child2();
    }

    Parent* get_instance() {
        return p;
    }
};

int main() {


    /**
     * 1 -> creates object of Child1 class
     * 2 -> creates object of Child2 class
    */
    Client *c = new Client(2);
    Parent *p = c->get_instance();
    p->job();


}

