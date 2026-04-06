#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ==================== COMPOSITION ====================
// Definition: "HAS-A" relationship with STRONG ownership
// - Part cannot exist without the whole
// - Lifetime of part is managed by the whole
// - When container dies, parts die too

class Engine {
private:
    int horsepower;
public:
    Engine(int hp) : horsepower(hp) {
        cout << "Engine created with " << hp << " HP\n";
    }
    ~Engine() {
        cout << "Engine destroyed\n";
    }
    void start() { cout << "Engine started\n"; }
};

class Car {
private:
    Engine engine;  // Engine is PART OF Car (created with Car)
    string model;
public:
    Car(string m, int hp) : model(m), engine(hp) {
        cout << "Car " << model << " created\n";
    }
    ~Car() {
        cout << "Car " << model << " destroyed\n";
    }
    void startCar() {
        cout << model << " starting...\n";
        engine.start();
    }
};

// ==================== AGGREGATION ====================
// Definition: "HAS-A" relationship with WEAK ownership
// - Part can exist independently of the whole
// - Lifetime of part is NOT managed by the whole
// - When container dies, parts can still exist

class Teacher {
private:
    string name;
public:
    Teacher(string n) : name(n) {
        cout << "Teacher " << name << " created\n";
    }
    ~Teacher() {
        cout << "Teacher " << name << " destroyed\n";
    }
    string getName() { return name; }
};

class Department {
private:
    string deptName;
    vector<Teacher*> teachers;  // Pointers to existing teachers
public:
    Department(string name) : deptName(name) {
        cout << "Department " << deptName << " created\n";
    }
    ~Department() {
        cout << "Department " << deptName << " destroyed\n";
        // Teachers are NOT deleted here - they exist independently
    }
    void addTeacher(Teacher* t) {
        teachers.push_back(t);
        cout << "Teacher " << t->getName() << " added to " << deptName << "\n";
    }
};

// ==================== ASSOCIATION ====================
// Definition: "USES-A" relationship with NO ownership
// - Objects are completely independent with their own lifecycle
// - Objects interact by passing copies or data
// - No direct references or pointers maintained

class Book {
private:
    string title;
    string author;
public:
    Book(string t, string a) : title(t), author(a) {}
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
};

class Student {
private:
    string name;
    int studentId;
public:
    Student(string n, int id) : name(n), studentId(id) {
        cout << "Student " << name << " (ID: " << id << ") created\n";
    }
    ~Student() {
        cout << "Student " << name << " destroyed\n";
    }
    
    // Association: Student interacts with Library by passing data
    void borrowBook(class Library lib, string bookTitle) {
        cout << name << " requesting to borrow '" << bookTitle << "'\n";
        lib.lendBook(bookTitle, name, studentId);
    }
};

class Library {
private:
    string libraryName;
    vector<Book> books;
public:
    Library(string name) : libraryName(name) {
        books.push_back(Book("C++ Primer", "Stanley Lippman"));
        books.push_back(Book("Design Patterns", "Gang of Four"));
        books.push_back(Book("Clean Code", "Robert Martin"));
        cout << "Library '" << libraryName << "' created with books\n";
    }
    ~Library() {
        cout << "Library '" << libraryName << "' destroyed\n";
    }
    
    // Receives data, not references to Student
    void lendBook(string bookTitle, string studentName, int studentId) {
        cout << "Library: Lending '" << bookTitle << "' to " 
             << studentName << " (ID: " << studentId << ")\n";
    }
    
    // Another association example - completely independent interaction
    void addBook(Book book) {
        books.push_back(book);
        cout << "Library: Added book '" << book.getTitle() << "'\n";
    }
};

// ==================== MAIN - DEMONSTRATION ====================
int main() {
    cout << "=== COMPOSITION EXAMPLE ===\n";
    {
        Car myCar("Tesla Model 3", 450);
        myCar.startCar();
        // When myCar is destroyed, Engine is automatically destroyed
    }
    cout << "\n";

    cout << "=== AGGREGATION EXAMPLE ===\n";
    {
        Teacher t1("Dr. Smith");
        Teacher t2("Prof. Johnson");
        
        {
            Department csDept("Computer Science");
            csDept.addTeacher(&t1);
            csDept.addTeacher(&t2);
            // Department destroyed here
        }
        cout << "Department destroyed, but teachers still exist:\n";
        cout << "Teacher 1: " << t1.getName() << "\n";
        cout << "Teacher 2: " << t2.getName() << "\n";
        // Teachers destroyed here
    }
    cout << "\n";

    cout << "=== ASSOCIATION EXAMPLE ===\n";
    {
        Student alice("Alice", 101);
        Student bob("Bob", 102);
        Library cityLibrary("City Central Library");
        
        // Objects interact independently - passing copies/data
        alice.borrowBook(cityLibrary, "C++ Primer");
        bob.borrowBook(cityLibrary, "Clean Code");
        
        // Library can be used independently
        Book newBook("Effective C++", "Scott Meyers");
        cityLibrary.addBook(newBook);
        
        // All objects are completely independent
        cout << "\nAll objects exist independently and can be destroyed in any order\n";
    }
    
    return 0;
}