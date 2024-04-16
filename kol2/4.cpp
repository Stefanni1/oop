#include<iostream>
#include<cstring>
using namespace std;
    enum Size{
        small,
        big,
        family
    };
class Pizza{
protected:
    char name[20];
    char ingredients[100];
    double inPrice;
public:
    Pizza(char *name, char *ingredients, float inPrice) :  inPrice(inPrice) {
        strcpy(this->name,name);
        strcpy(this->ingredients,ingredients);
    }
    virtual double price(){
        return inPrice;
    }
   bool operator < (Pizza &p){
        return this->price() < p.price();
    }
    friend ostream& operator << (ostream &out, Pizza &p){
        out<<p.name<<" "<<p.ingredients;
        return out;
    }

    ~Pizza(){}
};
class FlatPizza : public Pizza{
private:
    Size size=small;
public:
    FlatPizza(char *name1, char *ingredients1, float inPrice1, char *name, char *ingredients, double inPrice,
              Size size) : Pizza(name1, ingredients1, inPrice1) {

    }
double price() override{
        switch(size){
            case small: return inPrice *1.1;
            case big: return inPrice *1.2;
            case family: return inPrice *1.3;
        }
        return inPrice;
    }
    friend ostream &operator<<(ostream &out, FlatPizza &fp){
        out<<fp.name<<": "<<fp.ingredients<<", "<<"- "<<fp.price()<<endl;
        return out;
    }
};
class FoldedPizza : public Pizza{
private:
    bool isWhiteFlour;
public:
    FoldedPizza(char *name, char *ingredients, float inPrice) : Pizza(name, ingredients, inPrice),isWhiteFlour(isWhiteFlour) {}
    double price()override{
        if(isWhiteFlour){
            return inPrice*1.1;
        }else {
            return inPrice*1.3;
        }
    }
    friend ostream &operator<<(ostream &out, FoldedPizza &flp){
        out<<flp.name<<": "<<endl;
        out<<((flp.isWhiteFlour) ? "wf" : "nwf");
        out<<" - "<<flp.price()<<endl;
        return out;
    }

    void setWhiteFlour(bool whiteFlour) {
        FoldedPizza::isWhiteFlour = whiteFlour;
    }

};
Pizza* expensivePizza(Pizza ** pizzas, int n){
    if(n==0)return nullptr;
    Pizza* maxPizza = pizzas[0];
    for (int i = 0; i <n; ++i) {
        if(*pizzas[i]<*maxPizza){
            maxPizza=pizzas[i];
        }
    }
    return maxPizza;

}


int main() {
    int test_case;
    char name[20];
    char ingredients[100];
    float inPrice;
    Size size;
    bool whiteFlour;

    cin >> test_case;
    if (test_case == 1) {
        // Test Case FlatPizza - Constructor, operator <<, price
        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        FlatPizza fp(nullptr, nullptr, 0, name, ingredients, inPrice, family);
        cout << fp;
    } else if (test_case == 2) {
        // Test Case FlatPizza - Constructor, operator <<, price
        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        int s;
        cin>>s;
        FlatPizza fp(nullptr, nullptr, 0, name, ingredients, inPrice, (Size) s);
        cout << fp;

    } else if (test_case == 3) {
        // Test Case FoldedPizza - Constructor, operator <<, price
        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        FoldedPizza fp(name, ingredients, inPrice);
        cout << fp;
    } else if (test_case == 4) {
        // Test Case FoldedPizza - Constructor, operator <<, price
        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        FoldedPizza fp(name, ingredients, inPrice);
        fp.setWhiteFlour(false);
        cout << fp;

    } else if (test_case == 5) {
        // Test Cast - operator <, price
        int s;

        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        cin>>s;
        FlatPizza *fp1 = new FlatPizza(nullptr, nullptr, 0, name, ingredients, inPrice, (Size) s);
        cout << *fp1;

        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        cin>>s;
        FlatPizza *fp2 = new FlatPizza(nullptr, nullptr, 0, name, ingredients, inPrice, (Size) s);
        cout << *fp2;

        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        FoldedPizza *fp3 = new FoldedPizza(name, ingredients, inPrice);
        cout << *fp3;

        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        FoldedPizza *fp4 = new FoldedPizza(name, ingredients, inPrice);
        fp4->setWhiteFlour(false);
        cout << *fp4;

        cout<<"Lower price: "<<endl;
        if(*fp1<*fp2)
            cout<<fp1->price()<<endl;
        else cout<<fp2->price()<<endl;

        if(*fp1<*fp3)
            cout<<fp1->price()<<endl;
        else cout<<fp3->price()<<endl;

        if(*fp4<*fp2)
            cout<<fp4->price()<<endl;
        else cout<<fp2->price()<<endl;

        if(*fp3<*fp4)
            cout<<fp3->price()<<endl;
        else cout<<fp4->price()<<endl;

    } else if (test_case == 6) {
        // Test Cast - expensivePizza
        int num_p;
        int pizza_type;

        cin >> num_p;
        Pizza **pi = new Pizza *[num_p];
        for (int j = 0; j < num_p; ++j) {

            cin >> pizza_type;
            if (pizza_type == 1) {
                cin.get();
                cin.getline(name,20);

                cin.getline(ingredients,100);
                cin >> inPrice;
                int s;
                cin>>s;
                FlatPizza *fp = new FlatPizza(nullptr, nullptr, 0, name, ingredients, inPrice, (Size) s);
                cout << (*fp);
                pi[j] = fp;
            }
            if (pizza_type == 2) {

                cin.get();
                cin.getline(name,20);
                cin.getline(ingredients,100);
                cin >> inPrice;
                FoldedPizza *fp =
                        new FoldedPizza (name, ingredients, inPrice);
                if(j%2)
                    (*fp).setWhiteFlour(false);
                cout << (*fp);
                pi[j] = fp;

            }
        }

        cout << endl;
        cout << "The most expensive pizza:\n";
        expensivePizza(pi,num_p);


    }
    return 0;
}
