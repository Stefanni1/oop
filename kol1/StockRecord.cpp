#include<iostream>
#include<cstring>
using namespace std;
class StockRecord{
private:
    char id[13];
    char nameCompany[51];
    int priceBuy;
    double priceNow;
    int numActions;
public:
    StockRecord(char * id="", char * nameCompany="", int priceBuy=0, double priceNow=0.0, int numActions=0){
        strcpy(this->id,id);
        strcpy(this->nameCompany,nameCompany);
        this->priceBuy=priceBuy;
        this->priceNow=priceNow;
        this->numActions=numActions;
    }
    StockRecord(const StockRecord &sr){
        strcpy(this->id,sr.id);
        strcpy(this->nameCompany,sr.nameCompany);
        this->priceBuy=sr.priceBuy;
        this->priceNow=sr.priceNow;
        this->numActions=sr.numActions;
    }

    void setNewPrice(double c) {
        priceNow=c;
    }
    double value(){
        return numActions * priceNow;
    }
    double profit()const{
        return numActions * (priceNow - priceBuy);
    }
    StockRecord &operator=(const StockRecord &s){
        if(this!=&s){
            strcpy(this->id,s.id);
            strcpy(this->nameCompany,s.nameCompany);
            this->priceBuy=s.priceBuy;
            this->priceNow=s.priceNow;
            this->numActions=s.numActions;
        }
        return *this;
    }
    friend ostream &operator<<(ostream &out, const StockRecord &sr){
        out<<sr.nameCompany<<" "<<sr.numActions<<" "<<sr.priceBuy<<" "<<sr.priceNow<<" "<<sr.profit();
        return out;
    }
    ~StockRecord(){}


};

class Client{
    char nameSurname [60];
    int ID;
    StockRecord * nameCompany;
    int numObj;
public:
    Client(char *nameSurname, int id, StockRecord *nameCompany= nullptr, int numObj=0) :  ID(id),numObj(numObj) {
        strcpy(this->nameSurname,nameSurname);
        if(numObj>0 && nameCompany != nullptr){
            this->nameCompany=new StockRecord[numObj];
            for (int i = 0; i < numObj; ++i) {
                this->nameCompany[i]=nameCompany[i];
            }
        }else{
            this->nameCompany= nullptr;
        }
    }
    Client(const Client &c){
        strcpy(this->nameSurname,c.nameSurname);
        this->ID=c.ID;
        this->numObj=c.numObj;

    }
    Client &operator=(const Client &c) {
        if (this != &c) {
            delete[]nameCompany;
            strcpy(this->nameSurname, c.nameSurname);
            this->ID = c.ID;
            this->numObj = c.numObj;
        }
        return *this;
    }
    ~Client(){
        delete[]nameCompany;
    }

    int totalValue()const{
        int total =0;
        for (int i = 0; i < numObj; ++i) {
            total+=nameCompany[i].value();
        }
        return total;
    }
    Client &operator+=(const StockRecord &other){
        StockRecord *temp = new StockRecord[numObj+1];
        for (int i = 0; i < numObj; ++i) {
            temp[i]=nameCompany[i];
        }
        temp[numObj]=other;
        delete[]nameCompany;
        nameCompany=temp;
        ++numObj;
        return *this;

    }

    friend ostream &operator<<(ostream &os, const Client &client) {
        os << client.ID <<" "<<client.totalValue()<<endl;
        for (int i = 0; i < client.numObj; ++i) {
            os<<client.nameCompany[i]<<endl;
        }
        return os;
    }

};

int main(){

    int test;
    cin >> test;

    if(test == 1){
        double price;
        cout << "=====TEST NA KLASATA StockRecord=====" << endl;
        StockRecord sr("1", "Microsoft", 60.0, 100);
        cout << "Konstruktor OK" << endl;
        cin >> price;
        sr.setNewPrice(price);
        cout << "SET metoda OK" << endl;
    }
    else if(test == 2){
        cout << "=====TEST NA METODITE I OPERATOR << OD KLASATA StockRecord=====" << endl;
        char id[12], company[50];
        double price, newPrice;
        int n, shares;
        cin >> n;
        for(int i = 0; i < n; ++i){
            cin >> id;
            cin >> company;
            cin >> price;
            cin >> newPrice;
            cin >> shares;
            StockRecord sr(id, company, price, shares);
            sr.setNewPrice(newPrice);
            cout << sr.value() << endl;
            cout << sr;
        }
    }
    else if(test == 3){
        cout << "=====TEST NA KLASATA Client=====" << endl;
        char companyID[12], companyName[50], clientName[50];
        int clientID, n, shares;
        double oldPrice, newPrice;
        bool flag = true;
        cin >> clientName;
        cin >> clientID;
        cin >> n;
        Client c(clientName, clientID);
        cout << "Konstruktor OK" << endl;
        for(int i = 0; i < n; ++i){
            cin >> companyID;
            cin >> companyName;
            cin >> oldPrice;
            cin >> newPrice;
            cin >> shares;
            StockRecord sr(companyID, companyName, oldPrice, shares);
            sr.setNewPrice(newPrice);
            c += sr;
            if(flag){
                cout << "Operator += OK" << endl;
                flag = false;
            }
        }
        cout << c;
        cout << "Operator << OK" << endl;
    }
    return 0;

}