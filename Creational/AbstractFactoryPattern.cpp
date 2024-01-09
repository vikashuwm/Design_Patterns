#include <iostream>

using namespace std;

// Abstract class representing Brake functionality
class Brake {
public:
    Brake() { }
    virtual void brake() = 0;
    virtual ~Brake() { }  // Virtual destructor for proper cleanup
};

// Concrete class for Sports Brake
class SportsBrake : public Brake {
public:
    SportsBrake() {
        cout << "Creating a sports brake..." << endl;
    }
    void brake() override {
        cout << "sss_zzzzzz" << endl;
    }
};

// Concrete class for Electric Brake
class ElectricBrake : public Brake {
public:
    ElectricBrake() {
        cout << "Creating an electric brake..." << endl;
    }
    void brake() override {
        cout << "ss_jj ...." << endl;
    }
};

// Abstract class representing Engine functionality
class Engine {
public:
    Engine() { }
    virtual void run() = 0;
    virtual ~Engine() { }  // Virtual destructor for proper cleanup
};

// Concrete class for Sports Engine
class SportsEngine : public Engine {
public:
    SportsEngine() {
        cout << "Creating a sports engine..." << endl;
    }
    void run() override {
        cout << "broooommmmmm......" << endl;
    }
};

// Concrete class for Electric Engine
class ElectricEngine : public Engine {
public:
    ElectricEngine() {
        cout << "Creating an electric engine..." << endl;
    }
    void run() override {
        cout << "sssssss......." << endl;
    }
};

// Abstract factory class for creating Brake and Engine objects
class CarFactory {
public:
    virtual Brake* buildBrake() = 0;
    virtual Engine* buildEngine() = 0;
    virtual ~CarFactory() { }  // Virtual destructor for proper cleanup
};

// Concrete factory class for creating Sports Car components
class SportsCarFactory : public CarFactory {
public:
    SportsCarFactory() {}
    Brake* buildBrake() override {
        return new SportsBrake();
    }
    Engine* buildEngine() override {
        return new SportsEngine();
    }
};

// Concrete factory class for creating Electric Car components
class ElectricCarFactory : public CarFactory {
public:
    ElectricCarFactory() {}
    Brake* buildBrake() override {
        return new ElectricBrake();
    }
    Engine* buildEngine() override {
        return new ElectricEngine();
    }
};

int main() {
    CarFactory* carPlant;
    int choice;

    cout << "Select a car type: " << endl;
    cout << "1: Sports" << endl;
    cout << "2: Electric" << endl;
    cout << "Selection: ";
    cin >> choice;
    cout << endl;

    switch (choice) {
        case 1:
            carPlant = new SportsCarFactory;
            break;
        case 2:
            carPlant = new ElectricCarFactory;
            break;
        default:
            cout << "Invalid Selection" << endl;
            carPlant = nullptr;
            break;
    }

    if (carPlant != nullptr) {
        Brake* myBrake = carPlant->buildBrake();
        Engine* myEngine = carPlant->buildEngine();

        myEngine->run();
        myBrake->brake();

        // Cleanup
        delete myEngine;
        delete myBrake;
        delete carPlant;
    }

    return 0;
}
