#include <iostream>
#include <string>

using namespace std;

// Base class representing a Car
class Car {
protected:
    string* type;

public:
    Car() : type(nullptr) {
    }

    // Virtual destructor to ensure proper cleanup in derived classes
    virtual ~Car() {
        delete type;
    }

    // Getter method for retrieving the car type
    string* getCarType() {
        return type;
    }
};

// Derived class for Sports Car
class SportsCar : public Car {
public:
    SportsCar() : Car() {
        type = new string("Sports");
        cout << "Assembling your sports car... adding parts..." << endl;
        addNitro();
    }

    // Additional functionality specific to Sports Car
private:
    void addNitro() {
        cout << "...Adding Nitro to your sports car... Done!" << endl;
    }

    // Destructor to clean up resources
    ~SportsCar() {
        // Cleanup performed in base class
    }
};

// Derived class for Electric Car
class ElectricCar : public Car {
public:
    ElectricCar() : Car() {
        type = new string("Electric");
        cout << "Assembling your Electric car... adding parts..." << endl;
        addCharging();
    }

    // Additional functionality specific to Electric Car
private:
    void addCharging() {
        cout << "...Adding charging to your electric car... Done!" << endl;
    }

    // Destructor to clean up resources
    ~ElectricCar() {
        // Cleanup performed in base class
    }
};

// Factory class to create different types of cars
class CarFactory {
public:
    // Method to get a new Car based on user input
    Car* getCar() {
        int choice;
        cout << "Select the type of car you want: " << endl;
        cout << "1: Sports" << endl;
        cout << "2: Electric" << endl;
        cout << "Selection: ";
        cin >> choice;

        switch (choice) {
            case 1:
                return new SportsCar;
            case 2:
                return new ElectricCar;
            default:
                cout << "Invalid Selection! Car not available." << endl;
                return nullptr;
        }
    }
};

int main() {
    // Creating an instance of the CarFactory
    CarFactory carFactory;

    // Getting a new car based on user input
    Car* newCar = carFactory.getCar();

    // Displaying the type of the created car
    if (newCar) {
        cout << "You have a new " << *newCar->getCarType() << " car!" << endl;
        delete newCar; // Cleaning up the allocated memory
    }

    return 0;
}
