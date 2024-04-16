#include <iostream>
#include <cstring>
using namespace std;

class IceCream{
private:
    char *name;
    char ingridients[100];
    double price;
    int discount;
public:
    IceCream(const char *name="", char *ingridients="", double price = 0){
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
        strcpy(this->ingridients, ingridients);
        this->price = price;
        this->discount = discount;
    }
    IceCream(const IceCream & other){
        this->name = new char[strlen(other.name)+1];
        strcpy(this->name, other.name);
        strcpy(this->ingridients, other.ingridients);
        this->price = other.price;
        this->discount = other.discount;
    }
    IceCream & operator = (const IceCream & other){
        if(this!=&other){
            delete [] name;
            this->name = new char[strlen(other.name)+1];
            strcpy(this->name, other.name);
            strcpy(this->ingridients, other.ingridients);
            this->price = other.price;
            this->discount = other.discount;
        }
        return *this;
    }
    friend ostream & operator <<(ostream & o, const IceCream & ic){
        o << ic.name << ": " << ic.ingridients << " " << ic.price << " ";
        if(ic.discount != 0){
            o << "(" << ic.price * (100 - ic.discount) / 100 << ")";
        }
        return o;
    }

    IceCream & operator++(){
        discount += 5;
        return *this;
    }
    IceCream operator+(const char extra) {

        char* newName = new char[strlen(name) + strlen(extra) + 4];
        strcat(newName, name);
        strcat(newName, " + ");
        strcat(newName, extra);

        IceCream res(newName, ingridients, price + 10);
        res.setDiscount(discount);
        return res;
    }
    void setName(const char* n) {
        delete [] name;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    void setDiscount(int d) {

        if(d>=0&&d<=100)
            discount = d;
    }
    ~IceCream() {
        delete [] name;
    }
};

class IceCreamShop{
private:
    char nameShop[50];
    IceCream *icecreams;
    int NumIceCreams;
public:
    IceCreamShop(char *nameshop=""){
        strcpy(this->nameShop, nameshop);
        this->icecreams = new IceCream[0];
        this->NumIceCreams = 0;
    }
    IceCreamShop(const IceCreamShop & other) {
        strcpy(this->nameShop, other.nameShop);
        this->NumIceCreams = other.NumIceCreams;
        this->icecreams = new IceCream[other.NumIceCreams];
        for (int i = 0; i < other.NumIceCreams; i++) {
            this->icecreams[i] = other.icecreams[i]; // Deep copy IceCream objects
        }
    }
    IceCreamShop & operator = (const IceCreamShop & other){
        if(this!=&other){
            delete [] icecreams;
            strcpy(this->nameShop, other.nameShop);
            this->NumIceCreams = other.NumIceCreams;
            this->icecreams = new IceCream[other.NumIceCreams];
            for(int i = 0; i < other.NumIceCreams; i++){
                icecreams[i] = other.icecreams[i];
            }
        }
        return *this;
    }
    IceCreamShop & operator +=(const IceCream & ic) {
        IceCream * tmp = icecreams;
        icecreams = new IceCream[NumIceCreams + 1];
        for (int i = 0; i < NumIceCreams; i++) {
            icecreams[i] = tmp[i]; // Deep copy IceCream objects
        }
        icecreams[NumIceCreams] = ic;
        NumIceCreams++;
        delete [] tmp;
        return *this;
    }
    friend ostream & operator <<(ostream & o, const IceCreamShop & ics){
        o << ics.nameShop << endl;
        for(int i = 0; i < ics.NumIceCreams; i++){
            o << ics.icecreams[i] << endl;
        }
    }
    ~IceCreamShop(){
        delete [] icecreams;
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

