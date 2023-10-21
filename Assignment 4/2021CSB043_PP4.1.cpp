#include <iostream>
#include <string>

using namespace std;

class Vehicle {
private:
    double price;
    string manufacturer;

public:
    Vehicle() {
        price = 0.0;
        manufacturer = "";
    }

    Vehicle(double p, string m) {
        price = p;
        manufacturer = m;
    }

    Vehicle(const Vehicle& other) {
        price = other.price;
        manufacturer = other.manufacturer;
    }

    Vehicle& operator=(const Vehicle& other) {
        if (this != &other) {
            price = other.price;
            manufacturer = other.manufacturer;
        }
        return *this;
    }

    void readData() {
        cout << "Enter price: ";
        cin >> price;
        cout << "Enter manufacturer: ";
        cin >> manufacturer;
    }

    void displayData() {
        cout << "Price: " << price << endl;
        cout << "Manufacturer: " << manufacturer << endl;
    }
};

class Car : public Vehicle {
private:
    string color;
    int numSeats;
    string model;

public:
    Car() {
        color = "";
        numSeats = 0;
        model = "";
    }

    Car(double p, string m, string c, int n, string mod) : Vehicle(p, m) {
        color = c;
        numSeats = n;
        model = mod;
    }

    Car(const Car& other) : Vehicle(other) {
        color = other.color;
        numSeats = other.numSeats;
        model = other.model;
    }

    Car& operator=(const Car& other) {
        if (this != &other) {
            Vehicle::operator=(other);
            color = other.color;
            numSeats = other.numSeats;
            model = other.model;
        }
        return *this;
    }

    void readData() {
        Vehicle::readData();
        cout << "Enter color: ";
        cin >> color;
        cout << "Enter number of seats: ";
        cin >> numSeats;
        cout << "Enter model: ";
        cin >> model;
    }

    void displayData() {
        Vehicle::displayData();
        cout << "Color: " << color << endl;
        cout << "Number of seats: " << numSeats << endl;
        cout << "Model: " << model << endl;
    }
};

int main() {
    Car car1;
    car1.readData();
    car1.displayData();

    Car car2(20000, "Maruti", "Black", 4, "R402");
    car2.displayData();

    Car car3 = car2;
    car3.displayData();

    return 0;
}
