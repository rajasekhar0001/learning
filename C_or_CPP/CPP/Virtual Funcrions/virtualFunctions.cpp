// Virtual functions
// Static binding and dynamic binding

/**
 * 
 🔹 2. How Does Dynamic Dispatch or Dynamic method dispatch (dynamic bi binding) Work Internally? (Virtual Table Mechanism)

            When you use virtual functions, the compiler creates a hidden structure called a vtable
            (short for virtual table), and each class with virtual functions has one.

 🧠 Conceptually:
    vtable:
        A table (array) of function pointers — one for each virtual function.

    vptr:
        Each object of such a class has a hidden pointer (vptr) that points to its class’s vtable.

🔹 4. Notes About vtable

    Created per class, not per object.
    vptr (pointer to vtable) is added automatically by the compiler.
    Exists only if the class has at least one virtual function.
    virtual destructor ensures proper cleanup through base pointers.

| Term                 | Meaning                                                                             |
| -------------------- | ----------------------------------------------------------------------------------- |
| **vtable**           | Compiler-created table of virtual function addresses                                |
| **vptr**             | Hidden pointer inside each object pointing to its class’s vtable                    |
| **Dynamic Dispatch** | Process of calling the correct virtual function at runtime based on the object type |

 */


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
        /**
         * Even though parentObj is a Parent*, C++ calls the Derived version Child —
             --->> this is dynamic dispatch.
         */
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