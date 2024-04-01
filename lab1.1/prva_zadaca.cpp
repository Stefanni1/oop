
#include <iostream>
#include <cstring>

using namespace std;

class MobilePhone {
private:
    char model[21]; // 20 characters + null terminator
    int modelNumber;
    int releaseYear;

public:
    // Default constructor
    MobilePhone() {
        model[0] = '\0';
        modelNumber = 0;
        releaseYear = 0;
    }

    // Constructor with arguments
    MobilePhone(const char* _model, int _modelNumber, int _releaseYear) {
        strncpy(model, _model, 20);
        model[20] = '\0'; // Null terminator to ensure proper string termination
        modelNumber = _modelNumber;
        releaseYear = _releaseYear;
    }

    // Copy constructor
    MobilePhone(const MobilePhone& other) {
        strncpy(model, other.model, 20);
        model[20] = '\0'; // Null terminator to ensure proper string termination
        modelNumber = other.modelNumber;
        releaseYear = other.releaseYear;
    }

    // Destructor
    ~MobilePhone() {}

    // Getter methods
    const char* getModel() const {
        return model;
    }

    int getModelNumber() const {
        return modelNumber;
    }

    int getReleaseYear() const {
        return releaseYear;
    }

    // Print information about the mobile phone
    void print() const {
        cout << getModel() << " " << getModelNumber() << " release year: " << getReleaseYear() << endl;
    }
};

class Owner {
private:
    char name[21]; // 20 characters + null terminator
    char surname[21]; // 20 characters + null terminator
    MobilePhone mobilePhone;

public:
    // Default constructor
    Owner() {
        name[0] = '\0';
        surname[0] = '\0';
    }

    // Constructor with arguments
    Owner(const char* _name, const char* _surname, const MobilePhone& _mobilePhone) {
        strncpy(name, _name, 20);
        name[20] = '\0'; // Null terminator to ensure proper string termination
        strncpy(surname, _surname, 20);
        surname[20] = '\0'; // Null terminator to ensure proper string termination
        mobilePhone = _mobilePhone;
    }

    // Destructor
    ~Owner() {}

    // Getter methods
    const char* getName() const {
        return name;
    }

    const char* getSurname() const {
        return surname;
    }

    const MobilePhone& getMobilePhone() const {
        return mobilePhone;
    }

    // Print information about the owner and their mobile phone
    void print() const {
        cout << getName() << " " << getSurname() << " has a mobile phone:" << endl;
        mobilePhone.print();
    }
};

int main() {
    char model[20];
    int modelNumber;
    int year;
    char name[20];
    char surname[20];

    int testCase;

    cin >> testCase;

    cin >> model;
    cin >> modelNumber;
    cin >> year;
    cin >> name;
    cin >> surname;

    if (testCase == 1) {
        MobilePhone mobilePhone(model, modelNumber, year);

        Owner owner(name, surname, mobilePhone);
        owner.print();
    }

    return 0;
}
