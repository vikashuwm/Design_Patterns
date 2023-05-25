/* FactoryImp.cpp
*  author Vikash Kuamr
*/

#include <iostream>

using namespace std;

class Pizza
{
protected:
    char _type[20];
public:
    Pizza()
    {

    }
    char *getType() 
    {
        return _type;
    }
};
// concrete class
class Veg : public Pizza
{
public:
    Veg() : Pizza()
    {
        strcpy(_type, "Veg");
        cout << endl << "Making a veg pizza" << endl;
        cout << "Adding the veg items" << endl;
    }
};

class NonVeg : public Pizza 
{
public:
    NonVeg() : Pizza()
    {
        strcpy(_type, "NonVeg");
        cout << endl << "Making a NonVeg Pizza" << endl;
        cout << "Adding the veg items" << endl;
        cout << "Adding the Non-veg items" << endl;
    }
};

class PizzaMakerFactory
{
private:
    Pizza * _pizza;
public:
    Pizza * GetPizza()
    {
        int choice;
        cout << "Select a type of Pizza you want" << endl;
        cout << "1 : Veg \n" << "2: Non-Veg" << endl << "Selection : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            return new Veg;
        case 2:
            return new NonVeg;
        default:
            cout << "Invalid Selection " << endl;
            return NULL;
        }
    }

};

int main ()
{
    PizzaMakerFactory pizzaMaker;
    Pizza *pizza;
    pizza = pizzaMaker.GetPizza();
    cout << endl << "You had asked for a(n)" << pizza->getType() << endl;
    return 0;
}