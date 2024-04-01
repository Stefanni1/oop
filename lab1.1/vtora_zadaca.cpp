#include <iostream>
#include <cstring>

using namespace std;

class Product {
private:
    char name[101];
    int id;
    char category[101];
    double price;
    int quantity;

public:
    // Default constructor
    Product() {}

    // Constructor with arguments
    Product(const char* _name, int _id, const char* _category, double _price, int _quantity) {
        strncpy(name, _name, 100);
        name[100] = '\0';
        id = _id;
        strncpy(category, _category, 100);
        category[100] = '\0';
        price = _price;
        quantity = _quantity;
    }

    // Set methods
    void setName(const char* _name) {
        strncpy(name, _name, 100);
        name[100] = '\0';
    }

    void setId(int _id) {
        id = _id;
    }

    void setCategory(const char* _category) {
        strncpy(category, _category, 100);
        category[100] = '\0';
    }

    void setPrice(double _price) {
        price = _price;
    }

    void setQuantity(int _quantity) {
        quantity = _quantity;
    }

    // Get methods
    const char* getName() const {
        return name;
    }

    int getId() const {
        return id;
    }

    const char* getCategory() const {
        return category;
    }

    double getPrice() const {
        return price;
    }

    int getQuantity() const {
        return quantity;
    }

    // Print product information
    void print() const {
        cout << "Name: " << name << ", Id: " << id << ", Price: " << price << ", Quantity: " << quantity << endl;
    }
};

// Function to print products by category
void printByCategory(Product *products, int n, const char *category) {
    double totalSum = 0.0;
    cout << "Category: " << category << endl;
    for (int i = 0; i < n; ++i) {
        if (strcmp(products[i].getCategory(), category) == 0) {
            products[i].print();
            totalSum += products[i].getPrice() * products[i].getQuantity();
        }
    }
    cout << "Total sum: " << totalSum << endl;
}

int main() {
    int m;
    cin >> m;
    if (m == 0) {
        cout << "---Testing constructor with arguments and print()---" << "\n";
        char name[100] = "Book";
        int id = 1;
        char category[100] = "Books";
        double price = 14.99;
        int quantity = 3;

        Product product = Product(name, id, category, price, quantity);
        product.print();
    }
    else if (m == 1) {
        cout << "---Testing get and set methods---" << "\n";
        char name[100] = "Book";
        int id = 1;
        char category[100] = "Books";
        double price = 14.99;
        int quantity = 3;
        Product product;
        product.setName(name);
        product.setId(id);
        product.setCategory(category);
        product.setPrice(price);
        product.setQuantity(quantity);
        cout << "Name: " << product.getName() << endl;
        cout << "Id: " << product.getId() << endl;
        cout << "Category: " << product.getCategory() << endl;
        cout << "Price: " << product.getPrice() << endl;
        cout << "Quantity: " << product.getQuantity() << endl;
    }
    else if (m == 2) {
        const int numProducts = 8;
        Product products[numProducts];

        for (int i = 0; i < numProducts; ++i) {
            char name[100];
            int id;
            char category[100];
            double price;
            int quantity;
            cin >> name >> id >> category >> price >> quantity;
            products[i] = Product(name, id, category, price, quantity);
        }

        cout << "---Testing function---" << "\n";
        printByCategory(products, numProducts, "Electronics");
        cout << endl;
        printByCategory(products, numProducts, "Clothing");
        cout << endl;
        printByCategory(products, numProducts, "Books");
    }
    return 0;
}
