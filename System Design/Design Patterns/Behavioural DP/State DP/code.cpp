#include <iostream>
using namespace std;

class TrafficLightContext;

// STATE INTERFACE
class TrafficLightState {
public:
    virtual void next(TrafficLightContext* context) = 0;
    virtual string getColor() = 0;
};

// Forward declare states
class RedState;
class GreenState;
class YellowState;

// CONTEXT
class TrafficLightContext {
    TrafficLightState* currState;

public:
    TrafficLightContext();

    void setState(TrafficLightState* state) {
        currState = state;
    }

    void next() {
        currState->next(this);
    }

    string getColor() {
        return currState->getColor();
    }
};

// STATE CLASSES (only declarations)
class RedState : public TrafficLightState {
public:
    void next(TrafficLightContext* context) override;
    string getColor() override { return "RED"; }
};

class GreenState : public TrafficLightState {
public:
    void next(TrafficLightContext* context) override;
    string getColor() override { return "GREEN"; }
};

class YellowState : public TrafficLightState {
public:
    void next(TrafficLightContext* context) override;
    string getColor() override { return "YELLOW"; }
};


// ✅ IMPLEMENTATION AFTER ALL CLASSES

TrafficLightContext::TrafficLightContext() {
    currState = new RedState();
}

void RedState::next(TrafficLightContext* context) {
    context->setState(new GreenState());
    cout << "RED -> GREEN\n";
}

void GreenState::next(TrafficLightContext* context) {
    context->setState(new YellowState());
    cout << "GREEN -> YELLOW\n";
}

void YellowState::next(TrafficLightContext* context) {
    context->setState(new RedState());
    cout << "YELLOW -> RED\n";
}


// MAIN
int main() {
    TrafficLightContext context;

    context.next();
    context.next();
    context.next();
}