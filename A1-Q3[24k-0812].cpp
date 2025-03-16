#include <iostream>
using namespace std;

class Vehicle;

class User {
private:
    string userID;
    string name;
    int age;
    string licenseType;
    string contact;

public:
    User(string id, string n, int a, string l, string c) : userID(id), name(n), age(a), licenseType(l), contact(c) {}
    void updateDetails(string newName, int newAge, string newLicense, string newContact) {
        name = newName;
        age = newAge;
        licenseType = newLicense;
        contact = newContact;
    }
    string getLicenseType() {
         return licenseType; }
    string getName() { 
        return name;
         }
    void rentVehicle(Vehicle** vehicles, int vehicleCount);
};

class Vehicle {
private:
    string model;
    double rentalPrice;
    string requiredLicense;

public:
    Vehicle(string m, double p, string license) : model(m), rentalPrice(p), requiredLicense(license) {}
    string getRequiredLicense() { return requiredLicense; }
    string getModel() { return model; }
    double getPrice() { return rentalPrice; }
    void displayVehicle() {
        cout << "Model: " << model << ", Price per day: " << rentalPrice << ", Required License: " << requiredLicense << endl;
    }
};

void User::rentVehicle(Vehicle** vehicles, int vehicleCount) {
    cout << "Available Vehicles:\n";
    for (int i = 0; i < vehicleCount; i++) {
        vehicles[i]->displayVehicle();
    }
    cout << "Enter the model of the vehicle you want to rent: ";
    string choice;
    cin >> choice;
    for (int i = 0 ; i < vehicleCount; i++) {
        if (vehicles[i]->getModel() == choice) {
            if (vehicles[i]->getRequiredLicense() == licenseType || licenseType == "Full") {
                cout << "Vehicle rented successfully!\n";
                return;
            } else {
                cout << "You are not eligible to rent this vehicle.\n";
                return;
            }
        }
    }
    cout << "Vehicle not found.\n";
}

int main() {
    User user("U123", "John Doe", 25, "Intermediate", "123-456-789");
    Vehicle* vehicles[3];
    vehicles[0] = new Vehicle("Car", 50, "Intermediate");
    vehicles[1] = new Vehicle("Motorbike", 30, "Full");
    vehicles[2] = new Vehicle("Bicycle", 10, "Learner");
    
    user.rentVehicle(vehicles, 3);
    
    for (int i = 0; i < 3; i++) {
        delete vehicles[i];
    }
    
    return 0;
}
