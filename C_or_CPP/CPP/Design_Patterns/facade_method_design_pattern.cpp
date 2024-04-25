/*
2) Structural design pattern:
     Structural design patterns are a subset of design patterns in software development
that focus on the composition of classes or objects to form larger, more complex structures.
They help in organizing and managing relationships between objects to achieve greater 
flexibility, reusability, and maintainability in a software system.

	a) Facade method design pattern 

	 It provides a simplified and unified interface to a set of interfaces or 
subsystems within a larger system, making it easier to use and reducing the complexity
of the system for clients. Essentially, it acts as a facade or entry point to a 
more complex system, shielding clients from its intricacies.

Ex:
*/

#include <iostream>

using namespace std;

class Engine {
    public:
    void engineOn() {
        cout << "Engine turned ON\n";
    }
    void engineOff() {
        cout << "Engine turned OFF\n";
    }
};
class Lights {
    public:
    void lightTurnOn() {
        cout << "Lights turned on\n";
    }

    void lightsTurnOff() {
        cout << "Lights turned OFF\n";
    }
};

class Car {
    private:
    Engine e;
    Lights l;
    public:
    void start() {
        e.engineOn();
        l.lightTurnOn();
    }

    void stop() {
        l.lightsTurnOff();
        e.engineOff();
    }
};
int main() {

    Car c;
    c.start();
    c.stop();

}