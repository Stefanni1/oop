#include<iostream>
#include<cstring>
using namespace std;
class Pica{
private:
    char ime[15];
    int cena;
    char * sostojki;
    bool namaluvanje;
public:
    Pica(char * ime="",int cena=0,char * sostojki="",bool namaluvanje=0){
        strcpy(this->ime,ime);
        this->cena=cena;
        this->sostojki=new char[strlen(sostojki)+1];
        strcpy(this->sostojki,sostojki);
        this->namaluvanje=namaluvanje;
    }
    Pica(const Pica &p){
        strcpy(this->ime,p.ime);
        this->cena=p.cena;
        this->sostojki=new char[strlen(p.sostojki)+1];
        strcpy(this->sostojki,p.sostojki);
        this->namaluvanje=p.namaluvanje;
    }
    ~Pica(){
        delete[]sostojki;
    }
    Pica &operator=(const Pica &p){
        if(this!=&p){
            delete[]sostojki;
            strcpy(this->ime,p.ime);
            this->cena=p.cena;
            this->sostojki=new char[strlen(p.sostojki)+1];
            strcpy(this->sostojki,p.sostojki);
            this->namaluvanje=p.namaluvanje;
        }
        return *this;
    }
    void pecati(){
        cout<<ime<<" - "<<sostojki<<", "<<cena<<endl;
    }
    bool istiSe(Pica p){
        return (strcmp(sostojki, p.sostojki)==0);
    }

    const char *getIme() const {
        return ime;
    }

    int getCena() const {
        return cena;
    }

    void setCena(int cena) {
        Pica::cena = cena;
    }

    char *getSostojki() const {
        return sostojki;
    }

    void setSostojki(char *sostojki) {
        Pica::sostojki = sostojki;
    }

    bool isNamaluvanje() const {
        return namaluvanje;
    }

    void setNamaluvanje(bool namaluvanje) {
        Pica::namaluvanje = namaluvanje;
    }
};
class Picerija{
private:
    char ime[15];
    Pica * pici;
    int brPici;
public:
   Picerija(char * ime="", Pica * p= nullptr, int brPici=0){
       strcpy(this->ime,ime);
       this->pici=new Pica[brPici];
       for (int i = 0; i < brPici; ++i) {
           this->pici[i]=pici[i];
       }
   }
   Picerija(const Picerija &p){
       strcpy(this->ime,p.ime);
       this->pici=new Pica[p.brPici];
       for (int i = 0; i < p.brPici; ++i) {
           this->pici[i]=p.pici[i];
       }
   }
   ~Picerija(){
       delete[]pici;
   }
   Picerija &operator=(const Picerija &pc){
       if(this!=&pc){
           strcpy(this->ime,pc.ime);
           this->pici=new Pica[pc.brPici];
           delete[]pici;
           for (int i = 0; i < pc.brPici; ++i) {
               this->pici[i]=pc.pici[i];
           }
       }
       return *this;
   }

    const char *getIme() const {
        return ime;
    }
    void setIme(){
       Picerija ::ime;
   }

    Picerija &operator +=(const Picerija &pc){
       bool imaIsta = false;
        for (int i = 0; i < brPici; ++i)
            if(pici[i].istiSe(pc))
                imaIsta= true;
        if(!imaIsta)
        {

            Pica* tmp = new Pica[brPici + 1];
            for (int i = 0; i < brPici; i++)
                tmp[i] = pici[i];
            tmp[brPici++] = pc;
            delete[] pici;
            pici = tmp;
        }
        return *this;
        }

   }

};


int main() {

    int n;
    char ime[15];
    cin >> ime;
    cin >> n;

    Picerija p1(ime);
    for (int i = 0; i < n; i++){
        char imp[100];
        cin.get();
        cin.getline(imp, 100);
        int cena;
        cin >> cena;
        char sostojki[100];
        cin.get();
        cin.getline(sostojki, 100);
        int popust;
        cin >> popust;
        Pica p(imp, cena, sostojki, popust);
        p1+=p;
    }

    Picerija p2 = p1;
    cin >> ime;
    p2.setIme(ime);
    char imp[100];
    cin.get();
    cin.getline(imp, 100);
    int cena;
    cin >> cena;
    char sostojki[100];
    cin.get();
    cin.getline(sostojki, 100);
    int popust;
    cin >> popust;
    Pica p(imp, cena, sostojki, popust);
    p2+=p;

    cout << p1.getIme() << endl;
    cout << "Pici na promocija:" << endl;
    p1.piciNaPromocija();

    cout << p2.getIme() << endl;
    cout << "Pici na promocija:" << endl;
    p2.piciNaPromocija();

    return 0;
}
