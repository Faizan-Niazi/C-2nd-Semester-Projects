#include <iostream>
#include <string>
using namespace std;

class Vehicle {
private:
    string LicensePlate_No;
    string Model_No;
    string Type;
    string Color;

public:
    // Default Constructor
    Vehicle();

    // Parameterized Constructor
    Vehicle(string LicensePlate_No, string Model_No, string Type, string Color);

    // Setters
    void setLicensePlateNo(string licensePlateNo);
    void setModelNo(string modelNo);
    void setType(string type);
    void setColor(string color);

    // Getters
    string getLicensePlateNo();
    string getModelNo();
    string getType();
    string getColor();

    // Functionalities
    void registerVehicle(string licenseNo, string modelNo, string type, string color);
    void updateVehicle(string licenseNo, string modelNo, string type, string color);
    bool deleteVehicle(string search);
    bool searchVehicle(string search);
    void showVehicle();
};

// Default Constructor
Vehicle::Vehicle() : LicensePlate_No("Unknown"), Model_No("Unknown"), Type("Unknown"), Color("Unknown") {}

// Parameterized Constructor
Vehicle::Vehicle(string LicensePlate_No, string Model_No, string Type, string Color) {
    this->LicensePlate_No = LicensePlate_No;
    this->Model_No = Model_No;
    this->Type = Type;
    this->Color = Color;
}

// Setters
void Vehicle::setLicensePlateNo(string licensePlateNo) { this->LicensePlate_No = licensePlateNo; }
void Vehicle::setModelNo(string modelNo) { this->Model_No = modelNo; }
void Vehicle::setType(string type) { this->Type = type; }
void Vehicle::setColor(string color) { this->Color = color; }

// Getters
string Vehicle::getLicensePlateNo() { return LicensePlate_No; }
string Vehicle::getModelNo() { return Model_No; }
string Vehicle::getType() { return Type; }
string Vehicle::getColor() { return Color; }

// Register Vehicle
void Vehicle::registerVehicle(string licenseNo, string modelNo, string type, string color) {
    setLicensePlateNo(licenseNo);
    setModelNo(modelNo);
    setType(type);
    setColor(color);
    cout << "Vehicle Registered Successfully!\n";
}

// Update Vehicle
void Vehicle::updateVehicle(string licenseNo, string modelNo, string type, string color) {
    setLicensePlateNo(licenseNo);
    setModelNo(modelNo);
    setType(type);
    setColor(color);
    cout << "Vehicle Updated Successfully!\n";
}

// Delete Vehicle
bool Vehicle::deleteVehicle(string search) {
    if (search == LicensePlate_No) {
        LicensePlate_No = "Unknown";
        Model_No = "Unknown";
        Type = "Unknown";
        Color = "Unknown";
        return true;
    }
    return false;
}

// Search Vehicle
bool Vehicle::searchVehicle(string search) {
    return search == LicensePlate_No;
}

// Show Vehicle Details
void Vehicle::showVehicle() {
    cout << "\nVehicle Details:";
    cout << "\nLicense Plate: " << getLicensePlateNo();
    cout << "\nModel No: " << getModelNo();
    cout << "\nType: " << getType();
    cout << "\nColor: " << getColor() << "\n";
}

// Main Function
int main() {
    Vehicle Vehicles[10];  // Array for storing up to 10 vehicles
    int vehicleCount = 0;  // Tracks registered vehicles

    int choice;
    while (true) {
        cout << "\nVehicle Management System";
        cout << "\n1. Register Vehicle";
        cout << "\n2. Update Vehicle";
        cout << "\n3. Search Vehicle";
        cout << "\n4. Delete Vehicle";
        cout << "\n5. Show All Vehicles";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        string LicensePlate_No, Model_No, Type, Color, search;

        if (choice == 1) {  // Register Vehicle
            if (vehicleCount >= 10) {
                cout << "Storage Full! Cannot register more vehicles.\n";
                continue;
            }
            cout << "Enter License Plate: ";
            cin >> LicensePlate_No;
            cout << "Enter Model No: ";
            cin >> Model_No;
            cout << "Enter Type: ";
            cin >> Type;
            cout << "Enter Color: ";
            cin >> Color;

            Vehicles[vehicleCount].registerVehicle(LicensePlate_No, Model_No, Type, Color);
            vehicleCount++;

        } else if (choice == 2) {  // Update Vehicle
            cout << "Enter License Plate to Update: ";
            cin >> search;
            bool found = false;
            for (int i = 0; i < vehicleCount; i++) {
                if (Vehicles[i].searchVehicle(search)) {
                    cout << "Enter New License Plate: ";
                    cin >> LicensePlate_No;
                    cout << "Enter New Model No: ";
                    cin >> Model_No;
                    cout << "Enter New Type: ";
                    cin >> Type;
                    cout << "Enter New Color: ";
                    cin >> Color;

                    Vehicles[i].updateVehicle(LicensePlate_No, Model_No, Type, Color);
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Vehicle Not Found!\n";

        } else if (choice == 3) {  // Search Vehicle
            cout << "Enter License Plate to Search: ";
            cin >> search;
            bool found = false;
            for (int i = 0; i < vehicleCount; i++) {
                if (Vehicles[i].searchVehicle(search)) {
                    Vehicles[i].showVehicle();
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Vehicle Not Found!\n";

        } else if (choice == 4) {  // Delete Vehicle
            cout << "Enter License Plate to Delete: ";
            cin >> search;
            bool found = false;
            for (int i = 0; i < vehicleCount; i++) {
                if (Vehicles[i].deleteVehicle(search)) {
                    cout << "Vehicle Deleted Successfully!\n";
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Vehicle Not Found!\n";

        } else if (choice == 5) {  // Show All Vehicles
            if (vehicleCount == 0) {
                cout << "No Vehicles Registered Yet!\n";
                continue;
            }
            for (int i = 0; i < vehicleCount; i++) {
                cout << "\nVehicle " << i + 1;
                Vehicles[i].showVehicle();
            }

        } else if (choice == 6) {  // Exit
            cout << "Exiting Vehicle Management System...\n";
            break;

        } else {
            cout << "Invalid Choice! Try Again.\n";
        }
    }
    return 0;
}
