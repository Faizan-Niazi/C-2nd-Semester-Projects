#include <iostream>
using namespace std;

class PopSalon {
private:
    string customerName, mobileNumber, email, serviceQuality;
    int totalAmount;
    bool giftWrapper;

    // Maximum orders
    const int MAX_ORDERS = 10;

    // Arrays for available options
    string flavours[11] = {"Chocolate", "English Toffee", "Salted Caramel", "Caramel", "Jalapeno",
                           "Cheese", "Spiced Cheese", "Plain Salted", "Buttered", "Salt and Pepper", "Garlic"};

    string packetSizes[4] = {"Small Pack", "Medium Pack", "Large Pack", "Large Tin Pack"};
    int packetPrices[4] = {100, 250, 500, 750}; // Prices corresponding to sizes

    string extraToppings[4] = {"None", "Chocolate Sauce", "Caramel Sauce", "Melted Cheese"};
    int toppingPrices[4] = {0, 50, 30, 60}; // Prices corresponding to toppings

    // Multiple order
    string selectedFlavors[10], selectedPacketSizes[10], selectedToppings[10];
    int orderPrices[10];
    int orderCount;

public:
    PopSalon();  // Constructor
    void showMenu();
    void takeOrders();
    void getCustomerDetails();
    void displayBill();
    ~PopSalon();  // Destructor
};

// Constructor
PopSalon::PopSalon() {
    totalAmount = 0;
    giftWrapper = false;
    orderCount = 0;
    cout << "Welcome to PopSalon Vendor!\n";
}

// Function to display menu
void PopSalon::showMenu() {
    cout << "\nFlavors Available:\n";
    for (int i = 0; i < 11; i++)
        cout << i + 1 << ". " << flavours[i] << endl;

    cout << "\nPacket Sizes & Prices:\n";
    for (int i = 0; i < 4; i++)
        cout << i + 1 << ". " << packetSizes[i] << " - Rs. " << packetPrices[i] << endl;

    cout << "\nExtra Toppings:\n";
    for (int i = 0; i < 4; i++)
        cout << i + 1 << ". " << extraToppings[i] << " - Rs. " << toppingPrices[i] << endl;

    cout << "\nGift Wrapping Available (Extra Rs. 50)\n";
}

// Function to take orders
void PopSalon::takeOrders() {
    int choice;
    char moreOrders;

    do {
        if (orderCount >= MAX_ORDERS) {
            cout << "Maximum order limit reached!\n";
            break;
        }

        // Select Flavor
        cout << "\nSelect a flavor (Enter option number): ";
        cin >> choice;
        while (choice < 1 || choice > 11) {
            cout << "Invalid choice! Please select a valid flavor: ";
            cin >> choice;
        }
        selectedFlavors[orderCount] = flavours[choice - 1];

        // Select Packet Size
        cout << "\nSelect packet size (Enter option number): ";
        cin >> choice;
        while (choice < 1 || choice > 4) {
            cout << "Invalid choice! Please select a valid packet size: ";
            cin >> choice;
        }
        selectedPacketSizes[orderCount] = packetSizes[choice - 1];
        int itemPrice = packetPrices[choice - 1];

        // Select Toppings
        cout << "\nSelect a topping (Enter option number, 1 for None): ";
        cin >> choice;
        while (choice < 1 || choice > 4) {
            cout << "Invalid choice! Please select a valid topping: ";
            cin >> choice;
        }
        selectedToppings[orderCount] = extraToppings[choice - 1];
        itemPrice += toppingPrices[choice - 1];

        // Store total for this item
        orderPrices[orderCount] = itemPrice;
        totalAmount += itemPrice;
        orderCount++;

        // Asking for more orders
        cout << "Would you like to add another order? (Y/N): ";
        cin >> moreOrders;
    } while (moreOrders == 'Y' || moreOrders == 'y');

    // Gift Wrapping
    char wrapChoice;
    cout << "\nWould you like gift wrapping? (Y/N): ";
    cin >> wrapChoice;
    if (wrapChoice == 'Y' || wrapChoice == 'y') {
        giftWrapper = true;
        totalAmount += 50;
    }
}

// Function to get customer details
void PopSalon::getCustomerDetails() {
    cout << "\nEnter your Name: ";
    cin.ignore();
    getline(cin, customerName);
    cout << "Enter your Mobile Number: ";
    cin >> mobileNumber;
    cout << "Enter your Email: ";
    cin >> email;
    cout << "Rate Our Service (Good/Neutral/Bad): ";
    cin >> serviceQuality;
}

// Function to display the final bill
void PopSalon::displayBill() {
    cout << "\n--- Final Bill ---\n";
    cout << "Customer: " << customerName << endl;
    cout << "Mobile: " << mobileNumber << endl;
    cout << "Email: " << email << endl;

    for (int i = 0; i < orderCount; i++) {
        cout << "\nOrder " << i + 1 << ":\n";
        cout << "Flavor: " << selectedFlavors[i] << endl;
        cout << "Packet Size: " << selectedPacketSizes[i] << endl;
        cout << "Topping: " << selectedToppings[i] << endl;
        cout << "Price: Rs. " << orderPrices[i] << endl;
    }

    if (giftWrapper)
        cout << "Gift Wrap: Yes (Rs. 50)\n";

    cout << "Total Amount Payable: Rs. " << totalAmount << endl;
    cout << "Service Feedback: " << serviceQuality << endl;
}

// Destructor
PopSalon::~PopSalon() {
    cout << "\nThank you for visiting PopSalon! Have a great day!\n";
}

int main() {
    PopSalon customerOrder;
    customerOrder.showMenu();
    customerOrder.takeOrders();
    customerOrder.getCustomerDetails();
    customerOrder.displayBill();

    return 0;
}
