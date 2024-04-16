#include<iostream>
#include<cstring>
using namespace std;
class Product{
protected:
    char name[20];
    double price;
public:
    Product(char * name="", double price=0.0){
        strcpy(this->name,name);
        this->price=price;
    }
    ~Product(){}

};
class Discountable{
    virtual float getPrice() = 0;
    virtual float getPriceDiscount() = 0;
    virtual void print() = 0;
};
class FoodProduct : public Product, public Discountable{
private:
    int calories;
public:
    FoodProduct(char * name, double price, int calories) : Product(name,price), calories(calories) {}
    float getPrice() {
        return price;
    }
    float getPriceDiscount(){

    }
};
class DigitalProduct : public Product, public Discountable{
private:
    int size;
public:
    DigitalProduct(char * name, double price, int size) : Product(name,price), size(size){}

};


int main() {
    int n;
    cin >> n;

    Discountable **discountableProducts = new Discountable *[n];

    for (int i = 0; i < n; i++) {
        int type; //1 food 2 = digital
        char name[50];
        float price;
        float sizeInMb;
        int calories;
        cin >> type;
        if (type == 1) { //FoodProduct
            cin >> name >> price >> calories;
            discountableProducts[i] = new FoodProduct(name, price, calories);
        } else { // Digital Product
            cin >> name >> price >> sizeInMb;
            discountableProducts[i] = new DigitalProduct(name, price, sizeInMb);
        }
    }


    for (int i = 0; i < n; i++) {
        discountableProducts[i]->print();
    }

    cout << "Total discount for the products is: " << totalDiscount(discountableProducts, n) << endl;

    cout << "Total number of food products" << countFoodProducts(discountableProducts, n);
    cout << "Total number of digital products" << n - countFoodProducts(discountableProducts, n);

    return 0;

}