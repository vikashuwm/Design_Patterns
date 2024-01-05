#include <iostream>

using namespace std;

class Car {
protected:
    string* type;
public:
    Car() : type(nullptr) 
    {
    }
    string* getCarType() 
    {
        return type;
    }
};

class sportsCar : public Car {
public:
    sportsCar() : Car() {
        type = new string("Sports");
        cout << "Assembling your sports car .. adding parts .." << endl;
		addNitro();
    }
private:
    void addNitro() {
        cout<< "...Adding Nitro to your sports car ... Done !";
    }
    ~sportsCar() {
        delete type;
    }
};

class electricCar : public Car {
public:
    electricCar() : Car() {
        type = new string("Electric");
        cout << "Assembling your Electric car .. adding parts .." << endl;
		addCharing();
    }
private:
    void addCharing() {
        cout<< "...Adding charging to your electric car ... Done !";
    }
    ~electricCar() {
        delete type;
    }
};

class carFactory {
private:
    Car * car;
public:
    Car * getCar() {
        int choice;
        cout << "Select type of car you want: " << endl;
		cout << "1: Sports" << endl;
		cout << "2: Electric" << endl;
		cout << "Selection: ";
		cin >> choice;

        switch (choice)
        {
        case 1:
            return new sportsCar;
            break;
        case 2:
            return new electricCar;
            break;
        
        default:
            cout << "Invalid Selectino ! Car not availlable";
            break;
        }
    }

};

int main(){
    carFactory cf;
    cf.getCar();
    return 0;
}