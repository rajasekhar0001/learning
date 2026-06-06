#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class SmartDevice {
    public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
};

class AC {
    public:
    void connectToBluetooth() {
        cout << "Device connected to bluetooth\n";
    }

    void turnOn() {
        cout << "Turn on AC\n";
    }

    void turnOff() {
        cout << "Turn off AC\n";
    }

    void disconnectBlutooth() {
        cout << "DIsconect Blutooth\n";
    }
};

class SmartLight {
    public:
    void connectToWifi() {
        cout << "Device connected to Wifi\n";
    }

    void turnOn() {
        cout << "Turn on Smart LIght\n";
    }

    void turnOff() {
        cout << "Turn off Smart Light\n";
    }

    void disconnectWifi() {
        cout << "DIsconect Wifi\n";
    }
};

class ACAdapter : public SmartDevice {
    AC *ac;
    public:
    ACAdapter() {
        ac = new AC();
    }
    void turnOn() {
        ac->connectToBluetooth();
        ac->turnOn();
    }

    void turnOff() {
        ac->turnOff();
        ac->disconnectBlutooth();
    }
};

class SmartLightAdapter : public SmartDevice {
    SmartLight* sl;
    public:
    SmartLightAdapter() {
        sl = new SmartLight();
    }

    void turnOn() {
        sl->connectToWifi();
        sl->turnOn();
    }

    void turnOff() {
        sl->turnOff();
        sl->disconnectWifi();
    }
};


int main() {
    // Control Smart home apliances froma  single app
    // Smart Home Controller

    SmartDevice *ac = new ACAdapter();
    ac->turnOn();
    
    SmartDevice *sl = new SmartLightAdapter();
    sl->turnOn();

    ac->turnOff();
    sl->turnOff();

}