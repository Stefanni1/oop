#include <iostream>
#include <cstring>

using namespace std;

class Ingredient {
private:
    char* name;
    int quantity;
    int calories;

public:
    // Default constructor
    Ingredient() : name(nullptr), quantity(0), calories(0) {}

    // Constructor with arguments
    Ingredient(const char* _name, int _quantity, int _calories) : quantity(_quantity), calories(_calories) {
        name = new char[strlen(_name) + 1];
        strcpy(name, _name);
    }

    // Copy constructor
    Ingredient(const Ingredient& other) : quantity(other.quantity), calories(other.calories) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }

    // Destructor
    ~Ingredient() {
        delete[] name;
    }

    // Method to calculate total calories
    int getTotalCalories() const {
        return quantity * calories;
    }

    // Overloading << operator for printing
    friend ostream& operator<<(ostream& os, const Ingredient& ingredient) {
        os << "- " << ingredient.name << ": " << ingredient.quantity << "g/ml" << endl;
        return os;
    }

    // Overloading = operator
    Ingredient& operator=(const Ingredient& other) {
        if (this != &other) {
            delete[] name;
            quantity = other.quantity;
            calories = other.calories;
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
        }
        return *this;
    }
};

class Dish {
private:
    Ingredient* ingredients;
    char* dishName;
    int ingredientCount;

public:
    // Constructor with parameters
    Dish(const char* _dishName) : dishName(nullptr), ingredientCount(0) {
        dishName = new char[strlen(_dishName) + 1];
        strcpy(dishName, _dishName);
        ingredients = nullptr;
    }

    // Copy constructor
    Dish(const Dish& other) : dishName(nullptr), ingredientCount(other.ingredientCount) {
        dishName = new char[strlen(other.dishName) + 1];
        strcpy(dishName, other.dishName);

        ingredients = new Ingredient[ingredientCount];
        for (int i = 0; i < ingredientCount; ++i) {
            ingredients[i] = other.ingredients[i];
        }
    }

    // Destructor
    ~Dish() {
        delete[] dishName;
        delete[] ingredients;
    }

    // Method to get total calories
    int getTotalCalories() const {
        int totalCalories = 0;
        for (int i = 0; i < ingredientCount; ++i) {
            totalCalories += ingredients[i].getTotalCalories();
        }
        return totalCalories;
    }

    // Overloading + operator
    Dish operator+(const Dish& other) const {
        Dish combinedDish = *this;
        combinedDish += other;
        return combinedDish;
    }

    // Overloading += operator
    Dish& operator+=(const Dish& other) {
        Ingredient* newIngredients = new Ingredient[ingredientCount + other.ingredientCount];
        int index = 0;
        for (int i = 0; i < ingredientCount; ++i) {
            newIngredients[index++] = ingredients[i];
        }
        for (int i = 0; i < other.ingredientCount; ++i) {
            newIngredients[index++] = other.ingredients[i];
        }

        delete[] ingredients;
        ingredients = newIngredients;
        ingredientCount += other.ingredientCount;

        return *this;
    }

    // Overloading == operator
    bool operator==(const Dish& other) const {
        return getTotalCalories() == other.getTotalCalories();
    }

    // Overloading << operator for printing
    friend ostream& operator<<(ostream& os, const Dish& dish) {
        os << "Dish: " << dish.dishName << endl;
        for (int i = 0; i < dish.ingredientCount; ++i) {
            os << dish.ingredients[i];
        }
        os << "Total Calories: " << dish.getTotalCalories() << endl;
        return os;
    }

    // Method to add ingredient to dish
    void addIngredient(const Ingredient& ingredient) {
        Ingredient* newIngredients = new Ingredient[ingredientCount + 1];
        for (int i = 0; i < ingredientCount; ++i) {
            newIngredients[i] = ingredients[i];
        }
        newIngredients[ingredientCount++] = ingredient;

        delete[] ingredients;
        ingredients = newIngredients;
    }
};

int main() {
    char name[50];
    cin >> name;

    // Create Ingredients
    Ingredient tomato(name, 200, 20);
    cin >> name;
    Ingredient onion(name, 100, 30);
    cin >> name;
    Ingredient cheese(name, 50, 50);

    cin >> name;
    // Create Dishes
    Dish salad(name);
    salad.addIngredient(tomato);
    salad.addIngredient(onion);

    cin >> name;
    Dish pizza(name);
    pizza.addIngredient(tomato);
    pizza.addIngredient(cheese);

    // Test + operator
    Dish combinedDish = salad + pizza;
    cout << combinedDish;

    cout << "---------------------" << endl;

    //Test = operator
    Ingredient ingredient = tomato;
    cout << ingredient;
    cout << endl;

    cout << "---------------------" << endl;

    // Test == operator
    if (salad == pizza) {
        cout << "Salad and Pizza have the same calories." << endl;
    } else {
        cout << "Salad and Pizza do not have the same calories." << endl;
    }

    cout << "---------------------" << endl;

    //Test << operator
    cout << "Salad:" << endl;
    cout << salad;

    cout << "Pizza:" << endl;
    cout << pizza;

    return 0;
}
