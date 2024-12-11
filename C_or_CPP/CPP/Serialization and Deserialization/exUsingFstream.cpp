/**
* Serialization and Deserialization of an object in CPP
 */

#include <iostream>
#include <fstream> // header file to use CPP based streams
using namespace std;

class Serialize {
    private:
    int no;
    string name;

    public:

    Serialize() {};

    Serialize(int no, string name): name(name), no(no) {}
    
    int getNo() {
        return no;
    }

    string getName() {
        return name;
    }
};

int main() {
    Serialize obj(1, "raja");

    // Process to serialize the object
    ofstream file("ss.bin", ios::binary);
    if (!file.is_open()) {
        cerr << "Failed to open file\n";
        perror("cerr");
    }
    file.write(reinterpret_cast <const char*>(&obj), sizeof(obj));
    file.close();
    cout << "Object serialized successfully\n";

    // process to deserialize the object
    ifstream file1("ss.bin", ios::binary);
    if (!file1.is_open()) {
        cerr << "Failed to open file to read\n";
        exit(1);
    }
    Serialize readobj;
    file1.read(reinterpret_cast<char *> (&obj), sizeof(obj));
    file1.close();
    cout << "Object deserilized successfully\n";
    
    cout << obj.getName() << endl;
    cout << obj.getNo() << endl;
}