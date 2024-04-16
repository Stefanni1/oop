#include<iostream>
#include<cstring>
using namespace std;
class Pica{
private:
    char name[15];
    int cena;
    char * sostojki;
    int namaluvanje;
public:
    Pica(char * name="", int cena=0, char * sostojki="", int namaluvanje=0){
        strcpy(this->name,name);
        this->cena=cena;
        this->sostojki=new char[strlen(sostojki)+1];
        strcpy(this->sostojki,sostojki);
        this->namaluvanje=namaluvanje;
    }
    Pica(const Pica &p){
        strcpy(this->name,p.name);
        this->cena=p.cena;
        this->sostojki=new char[strlen(p.sostojki)+1];
        strcpy(this->sostojki,p.sostojki);
        this->namaluvanje=p.namaluvanje;
    }
    Pica &operator=(const Pica &p){
        if(this!=&p){
            delete[]sostojki;
            strcpy(this->name,p.name);
            this->cena=p.cena;
            this->sostojki=new char[strlen(p.sostojki)+1];
            strcpy(this->sostojki,p.sostojki);
            this->namaluvanje=p.namaluvanje;
        }
        return *this;
    }

    int getCena() const {
        return cena;
    }

    void setCena(int c) {
        Pica::cena = c;
    }

    char *getSostojki() const {
        return sostojki;
    }

    int getNamaluvanje() const {
        return namaluvanje;
    }

    ~Pica(){
        delete[]sostojki;
    }
    void pecati(){
        cout<<name<<" - "<<sostojki<<", "<<cena;
    }
    bool istiSe(Pica p){
     return (strcmp(sostojki, p.sostojki) == 0);
    }
};
class Picerija{
private:
    char ime[15];
    Pica * pici;
    int broj;
public:
    Picerija(char * ime="",Pica *pici= nullptr,int broj=0){
        strcpy(this->ime,ime);
        this->broj=broj;
        this->pici=new Pica[broj];
        for (int i = 0; i < broj; ++i) {
            this->pici[i]=pici[i];
        }
    }
    Picerija(const Picerija &pc){
        strcpy(this->ime,pc.ime);
        this->broj=pc.broj;
        this->pici=new Pica[pc.broj];
        for (int i = 0; i < pc.broj; ++i) {
            this->pici[i]=pc.pici[i];
        }
    }
    Picerija &operator=(const Picerija &pc){
        if(this!=&pc){
            strcpy(this->ime,pc.ime);
            this->broj=pc.broj;
            this->pici=new Pica[pc.broj];
            for (int i = 0; i < pc.broj; ++i) {
                this->pici[i]=pc.pici[i];
            }
        }
        return *this;
    }
    ~Picerija(){
        delete[]pici;
    }
    void setIme(){
        Picerija ::ime;
    }


    const char *getIme() const {
        return ime;
    }
    Picerija &operator +=(Pica &p){
        bool imaIsta = false;
        for (int i = 0; i < broj; ++i)
            if(pici[i].istiSe(p))
                imaIsta=true;
            if(!imaIsta)
            {
                Pica * tmp = new Pica[broj+1];
                for (int i = 0; i < broj; ++i)
                    tmp[i]=pici[i];
                    tmp[broj++]=p;
                    delete[]pici;
                    pici=tmp;
            }
            return * this;
    }
    void piciNaPromocija(){
        for (int i = 0; i < broj; ++i) {
            if(pici[i].getNamaluvanje() != 0 ){
                pici[i].pecati();
                cout<<" "<< pici[i].getCena() * (1-pici[i].getNamaluvanje() / 100)<<endl;
            }
        }
    }
    const char * getIme(){
        return ime;
    }
    void setIme(const char *ime){
        strncpy(this->ime,ime, 14);
        this->ime[14]=0;
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

