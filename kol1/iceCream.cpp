#include<iostream>
#include<cstring>
using namespace std;
class IceCream{
private:
    char * name;
    char ingr[100];
    double price;
    int discount=0;
public:
    IceCream(char * name="", char * ingr="", double price=0.0,int discount=0){
        this->name=new char[strlen(name)+1];
        strcpy(this->name,name);
        strcpy(this->ingr,ingr);
        this->price=price;
        this->discount=discount;
    }
    IceCream(const IceCream &ic){
        this->name=new char[strlen(ic.name)+1];
        strcpy(this->name,ic.name);
        strcpy(this->ingr,ic.ingr);
        this->price=ic.price;
        this->discount=ic.discount;
    }
    IceCream &operator=(const IceCream &ic){
        if(this!=&ic){
            delete[]name;
            this->name=new char[strlen(ic.name)+1];
            strcpy(this->name,ic.name);
            strcpy(this->ingr,ic.ingr);
            this->price=ic.price;
            this->discount=ic.discount;
        }
        return *this;
    }
        char *getName() const {
        return name;
    }

    void setName(char *name) {
        IceCream::name = name;
    }

    const char *getIngr() const {
        return ingr;
    }

    double getPrice() const {
        return price;
    }

    void setPrice(double price) {
        IceCream::price = price;
    }

    int getDiscount() const {
        return discount;
    }

    void setDiscount(int discount) {
        IceCream::discount = discount;
    }

    IceCream &operator++(){
        discount+=5;
        return *this;
    }

};


int main() {
    char name[100];
    char ingr[100];
    float price;
    int discount;

    int testCase;

    cin >> testCase;
    cin.get();
    if(testCase == 1) {
        cout << "====== TESTING IceCream CLASS ======" << endl;
        cin.getline(name,100);
        cin.getline(ingr,100);
        cin >> price;
        cin >> discount;
        cout << "CONSTRUCTOR" << endl;
        IceCream ic1(name, ingr, price);
        ic1.setDiscount(discount);
        cin.get();
        cin.getline(name,100);
        cin.getline(ingr,100);
        cin >> price;
        cin >> discount;
        IceCream ic2(name, ingr, price);
        ic2.setDiscount(discount);
        cout << "OPERATOR <<" << endl;
        cout << ic1 << endl;
        cout << ic2 << endl;
        cout << "OPERATOR ++" << endl;
        ++ic1;
        cout << ic1 << endl;
        cout << "OPERATOR +" << endl;
        IceCream ic3 = ic2 + "chocolate";
        cout << ic3 << endl;
    } else if(testCase == 2) {
        cout << "====== TESTING IceCream CONSTRUCTORS ======" << endl;
        cin.getline(name,100);
        cin.getline(ingr,100);
        cin >> price;
        //cin >> discount;
        cout << "CONSTRUCTOR" << endl;
        IceCream ic1(name, ingr, price);
        cout << ic1 << endl;
        cout << "COPY CONSTRUCTOR" << endl;
        IceCream ic2(ic1);
        cin.get();
        cin.getline(name,100);
        ic2.setName(name);
        cout << ic1 << endl;
        cout << ic2 << endl;
        cout << "OPERATOR =" << endl;
        ic1 = ic2;
        cin.getline(name,100);
        ic2.setName(name);
        cout << ic1 << endl;
        cout << ic2 << endl;

        cin >> discount;
        ic1.setDiscount(discount);


    } else if(testCase == 3) {
        cout << "====== TESTING IceCreamShop ======" << endl;
        char icsName[50];
        cin.getline(icsName,100);
        cout << "CONSTRUCTOR" << endl;
        IceCreamShop ics(icsName);
        int n;
        cin >> n;
        cout << "OPERATOR +=" << endl;
        for(int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name,100);
            cin.getline(ingr,100);
            cin >> price;
            IceCream ic(name, ingr, price);
            ics += ic;
        }
        cout << ics;
    } else if(testCase == 4) {
        cout << "====== TESTING IceCreamShop CONSTRUCTORS ======" << endl;
        char icsName[50];
        cin.getline(icsName,100);
        IceCreamShop ics(icsName);
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name,100);
            cin.getline(ingr,100);
            cin >> price;
            IceCream ic(name, ingr, price);
            ics += ic;
        }
        IceCream x("FINKI fruits", "strawberry ice cream, raspberry ice cream, blueberry ice cream", 60);
        IceCreamShop icp = ics;
        ics+=x;
        cout << ics << endl;
        cout << icp << endl;
    }


    return 0;
}
