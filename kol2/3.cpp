#include<iostream>
#include<cstring>
#include<exception>
using namespace std;
const int MAX=50;
enum typeC{
    standard,
    loyal,
    vip
};
class Customer{
private:
    char name[50];
    char email[50];
    typeC tip;
    int discount;
    int extraDiscount;
    int numProducts;
public:
    Customer(const char *name="",const char *email="", typeC tip=standard, int discount=0, int extraDiscount=0, int numProducts=0){
        strcpy(this->name,name);
        strcpy(this->email,email);
        this->tip=tip;
        this->discount=discount;
        this->extraDiscount=extraDiscount;
        this->numProducts=numProducts;
    }
    Customer(const Customer &c){
        strcpy(this->name,c.name);
        strcpy(this->email,c.email);
        this->tip=c.tip;
        this->discount=c.discount;
        this->extraDiscount=c.extraDiscount;
        this->numProducts=c.numProducts;
    }

    const char *getName() const {
        return name;
    }

    const char *getEmail() const {
        return email;
    }

    typeC getTip() const {
        return tip;
    }

    int getDiscount() const {
        return discount;
    }
    void setDiscount(int newDiscount) {
        this->discount = newDiscount;
    }
    void setTip(typeC newTip) {
        this->tip = newTip;
    }

    int getExtraDiscount() const {
        return extraDiscount;
    }

    int getNumProducts() const {
        return numProducts;
    }

    ~Customer(){}
    int popust() const {
        if(tip == standard) {
            return 0;
        } else if(tip == loyal) {
            return discount;
        } else {
            return discount + extraDiscount;
        }
    }
    friend ostream &operator<<(ostream &os, Customer &c){
        os<<c.name<<endl;
        os<<c.email<<endl;
        os<<c.numProducts<<endl;
        os<<c.tip<<" "<<c.popust()<<endl;
        return os;
    }
};
class UserExistsException : public exception{
public:
    const char * what() const throw(){
        return "The user already exists in the list";
    }
};
class FINKI_bookstore{
private:
    Customer * buyers;
    int numBuyers;
public:
    FINKI_bookstore(int numBuyers=0){
        this->numBuyers=numBuyers;
        buyers=new Customer[numBuyers];
    }
    FINKI_bookstore(const FINKI_bookstore &fb){
        this->numBuyers=fb.numBuyers;
        buyers=new Customer[fb.numBuyers];
        for (int i = 0; i < fb.numBuyers; ++i) {
            buyers[i]=fb.buyers[i];
        }
    }
    FINKI_bookstore &operator=(const FINKI_bookstore &fb){
        if(this!=&fb){
            this->numBuyers=fb.numBuyers;
            buyers=new Customer[fb.numBuyers];
            for (int i = 0; i < fb.numBuyers; ++i) {
                buyers[i]=fb.buyers[i];
            }
            delete[]buyers;
        }
        return * this;
    }
    FINKI_bookstore &operator+=(const Customer &c){
        for (int i = 0; i < numBuyers; ++i) {
            if(strcmp(buyers[i].getEmail(), c.getEmail())==0){
                throw UserExistsException();
            }
        }
            Customer *temp = new Customer[numBuyers+1];
            for (int i = 0; i < numBuyers; ++i) {
                temp[i]=buyers[i];
            }
            temp[numBuyers]=c;
            ++numBuyers;
            delete[]buyers;
            buyers=temp;
        return *this;
    }

    ~FINKI_bookstore(){
        delete[]buyers;
    }
    void update() {
        for (int i = 0; i < numBuyers; ++i) {
            if (buyers[i].getNumProducts() > 10) {
                buyers[i].setTip(vip);
            } else if (buyers[i].getNumProducts() > 5) {
                buyers[i].setTip(loyal);
            } else {
                buyers[i].setTip(standard);
            }
        }
    }


    // Overloaded insertion operator to print information about all registered customers
    friend ostream& operator<<(ostream& os, const FINKI_bookstore& fb) {
        os << "Registered Customers:" << endl;
        for (int i = 0; i < fb.numBuyers; ++i) {
            os << "Customer " << i + 1 << ":" << endl;
            os << fb.buyers[i] << endl;
        }
        return os;
    }
    void setCustomers(Customer *customers, int numCustomers) {
        delete[] buyers; // Delete any existing buyers array
        numBuyers = numCustomers;
        buyers = new Customer[numBuyers];
        for (int i = 0; i < numBuyers; ++i) {
            buyers[i] = customers[i];
        }
    }


};


int main(){
    int testCase;
    cin >> testCase;

    char name[MAX];
    char email[MAX];
    int tC;
    int discount;
    int numProducts;


    if (testCase == 1){
        cout << "===== Test Case - Customer Class ======" << endl;
        cin.get();
        cin.getline(name,MAX);
        cin.getline(email,MAX);
        cin >> tC;
        cin >> numProducts;
        cout << "===== CONSTRUCTOR ======" << endl;
        Customer c(name, email, (typeC) tC, numProducts);
        cout << c;

    }

    if (testCase == 2){
        cout << "===== Test Case - Static Members ======" << endl;
        cin.get();
        cin.getline(name,MAX);
        cin.getline(email,MAX);
        cin >> tC;
        cin >> numProducts;
        cout << "===== CONSTRUCTOR ======" << endl;
        Customer c(name, email, (typeC) tC, numProducts);
        cout << c;

        c.setDiscount(5);

        cout << c;
    }

    if (testCase == 3){
        cout << "===== Test Case - FINKI-bookstore ======" << endl;
        FINKI_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        for(int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name,MAX);
            cin.getline(email,MAX);
            cin >> tC;
            cin >> numProducts;
            Customer c(name, email, (typeC) tC, numProducts);
            customers[i] = c;
        }

        fc.setCustomers(customers, n);

        cout << fc <<endl;
    }

    if (testCase == 4){
        cout << "===== Test Case - operator+= ======" << endl;
        FINKI_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        for(int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name,MAX);
            cin.getline(email,MAX);
            cin >> tC;
            cin >> numProducts;
            Customer c(name, email, (typeC) tC, numProducts);
            customers[i] = c;
        }

        fc.setCustomers(customers, n);
        cout << "OPERATOR +=" << endl;
        cin.get();
        cin.getline(name,MAX);
        cin.getline(email,MAX);
        cin >> tC;
        cin >> numProducts;
        Customer c(name, email, (typeC) tC, numProducts);
        try {
            fc += c;
        }catch (const UserExistsException &e){
            cout<<e.what()<<endl;
        }
        cout << fc;
    }

    if (testCase == 5){
        cout << "===== Test Case - operator+= (exception!!!) ======" << endl;
        FINKI_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        for(int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name,MAX);
            cin.getline(email,MAX);
            cin >> tC;
            cin >> numProducts;
            Customer c(name, email, (typeC) tC, numProducts);
            customers[i] = c;
        }

        fc.setCustomers(customers, n);
        cout << "OPERATOR +=" << endl;
        cin.get();
        cin.getline(name,MAX);
        cin.getline(email,MAX);
        cin >> tC;
        cin >> numProducts;
        Customer c(name, email, (typeC) tC, numProducts);
        fc+=c;

        cout << fc;
    }

    if (testCase == 6){
        cout << "===== Test Case - update method  ======" << endl << endl;
        FINKI_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        for(int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name,MAX);
            cin.getline(email,MAX);
            cin >> tC;
            cin >> numProducts;
            Customer c(name, email, (typeC) tC, numProducts);
            customers[i] = c;
        }

        fc.setCustomers(customers, n);

        cout << "Update:" << endl;
        fc.update();
        cout << fc;
    }
    return 0;

}
