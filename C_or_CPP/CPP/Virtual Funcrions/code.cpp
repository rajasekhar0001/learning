// Virtual functions
// Static binding and dynamic binding


#include <bits/stdc++.h>
using namespace std;

class Parent {
    int id;
    public:
    // virtual void pureVirtualShow() = 0; // abstract class if there is pure virtual function, cant instantiate this class
    virtual void virtualShow() {
        cout << "virtualShow from Parent\n";
    }
    void show() {
        cout << "show from Parent\n";
    }
};

class Child: public Parent {
    public:
    void pureVirtualShow() {
        cout << "pureVirtualShow from Child\n";
    }
    void virtualShow() { // In case of dynamic binding, overrides the parent
        cout << "virtualShow from child\n";
    }
    void show() {
        cout << "show from Child\n";
    }
};

int main() {
    // Trie with Parent
    // Static binding
    {
        Parent p;
        Parent* ptr = new Parent();
        // Verify normal show method
        p.show();
        ptr->show();
        
        // Verify virtualShow method
        p.virtualShow();
        ptr->virtualShow();
        
        delete ptr;
    }
    
    cout << endl <<  endl;
    
    // True with Child
    // Static Binding
    {
        Child c;
        Child* ptr = new Child();
        // Verify normal show method
        c.show();
        ptr->show();
        
        // Verify virtualShow method
        c.virtualShow();
        ptr->virtualShow();
        
        delete ptr;
    }
    cout <<"\n\n";
    
    // Polymorphism -> Parent class object points to child class object  D
    // Dynamic binding
    {
        Child c;
        Child* ptr = new Child();
        Parent *parentObj = &c;  // or
        //  Parent *parentObj = ptr;
        
        cout << "---------Verify Dynamic binding or Late binding--------\n";
        
        // Verify virtualShow method
        parentObj->virtualShow();
        parentObj->show();
        
        delete ptr;
    }
}

/**
 * 
 * OUtput:

show from Parent
show from Parent
virtualShow from Parent
virtualShow from Parent


show from Child
show from Child
virtualShow from child
virtualShow from child


---------Verify Dynamic binding or Late binding--------
virtualShow from child
show from Parent

 */