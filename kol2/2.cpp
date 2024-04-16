#include<iostream>
#include<cstring>
using namespace std;
class Vozac{
protected:
    char name[100];
    int age;
    int num;
    bool daliVeteran;
public:
    Vozac(char *name, int age, int num, bool daliVeteran) : age(age), num(num), daliVeteran(daliVeteran) {
        strcpy(this->name,name);
    }
    friend ostream &operator<<(ostream &out, Vozac &v){
        out<<v.name<<" "<<endl;
        out<<v.age<<" "<<endl;
        out<<v.num<<" "<<endl;
        if(v.daliVeteran==true){
            out<<"VETERAN"<<endl;
        }
        return out;
    }
    virtual double getZarabotuvacka() = 0;
    virtual bool operator==(Vozac &v){
        return getZarabotuvacka() == v.getZarabotuvacka();
    }
    virtual double danok() = 0;
    ~Vozac(){}
};
class Avtomobilist :  public Vozac{
private:
    double cena;
public:
    Avtomobilist(char *name, int age, int num, bool daliVeteran, double cena) : Vozac(name, age, num, daliVeteran),cena(cena) {}
    double getZarabotuvacka()override{
        return cena / 5;
    }
    double danok()override{
        if(num>10){
            return getZarabotuvacka() * 0.15;
        }else{
            return getZarabotuvacka() * 0.10;
        }
    }

};
class Motociklist : public Vozac{
private:
    int mokjnost;
public:
    Motociklist(char *name, int age, int num, bool daliVeteran, int mokjnost) : Vozac(name, age, num, daliVeteran),mokjnost(mokjnost) {}
    double getZarabotuvacka()override{
        return mokjnost * 20;
    }
    double danok()override{
        if(daliVeteran==true){
            return getZarabotuvacka() * 0.25;
        }else {
            return getZarabotuvacka() * 0.20;
        }
    }
};
int soIstaZarabotuvachka(Vozac **vozaci, int n, Vozac *v){
    int a=0;
    double r=v->getZarabotuvacka();
    for (int i = 0; i < n; ++i) {
        vozaci[i]->getZarabotuvacka();
        if(vozaci[i]->getZarabotuvacka()==r) a++;
    }
    return a;
}



int main() {
    int n, x;
    cin >> n >> x;
    Vozac **v = new Vozac*[n];
    char ime[100];
    int vozrast;
    int trki;
    bool vet;
    for(int i = 0; i < n; ++i) {
        cin >> ime >> vozrast >> trki >> vet;
        if(i < x) {
            float cena_avto;
            cin >> cena_avto;
            v[i] = new Avtomobilist(ime, vozrast, trki, vet, cena_avto);
        } else {
            int mokjnost;
            cin >> mokjnost;
            v[i] = new Motociklist(ime, vozrast, trki, vet, mokjnost);
        }
    }
    cout << "=== DANOK ===" << endl;
    for(int i = 0; i < n; ++i) {
        cout << *v[i];
        cout << v[i]->danok() << endl;
    }
    cin >> ime >> vozrast >> trki >> vet;
    int mokjnost;
    cin >> mokjnost;
    Vozac *vx = new Motociklist(ime, vozrast, trki, vet, mokjnost);
    cout << "=== VOZAC X ===" << endl;
    cout << *vx;
    cout << "=== SO ISTA ZARABOTUVACKA KAKO VOZAC X ===" << endl;
    cout << soIstaZarabotuvachka(v, n, vx);
    for(int i = 0; i < n; ++i) {
        delete v[i];
    }
    delete [] v;
    delete vx;
    return 0;
}