#include<iostream>
#include<cstring>
using namespace std;
class Pica{
private:
    char ime[15];
    int cena;
    char * sostojki;
    int namaluvanje;
public:
    Pica(const char * ime="", int cena=0, const char * sostojki="", int namaluvanje=0){
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
        delete [] sostojki;
    }
    Pica &operator=(const Pica &p){
        if(this!=&p){
            strcpy(this->ime,p.ime);
            this->cena=p.cena;
            delete[]sostojki;
            this->sostojki=new char[strlen(p.sostojki)+1];
            this->namaluvanje=p.namaluvanje;
        }
        return *this;
    }


    int getCena()  {
        return cena;
    }

    int getNamaluvanje()  {
        return namaluvanje;
    }
    void pecati(){
        cout << ime << " - " << sostojki << ", " << cena;
    }
    bool istiSe(Pica p){
        return(strcmp(sostojki, p.sostojki)==0);
    }
};
class Picerija{
private:
    char ime[15];
    Pica * p;
    int brPici;
public:
    Picerija(const char * ime=""){
        strncpy(this->ime,ime,14);
        this->ime[14]=0;
        p=NULL;
        brPici=0;
    }

    Picerija(const char * ime, Pica *p, int brPici){
        strncpy(this->ime,ime,14);
        this->ime[14]=0;
        this->brPici=brPici;
        this->p=new Pica[brPici];
        for (int i = 0; i < brPici; ++i) {
            this->p[i]=p[i];
        }
    }
    Picerija(const Picerija &pc){
        strcpy(this->ime,pc.ime);
        this->brPici=pc.brPici;
        this->p=new Pica[brPici];
        for (int i = 0; i < brPici; ++i) {
            this->p[i]=pc.p[i];
        }
    }
    Picerija &operator=(const Picerija &pc){
        if(this!=&pc){
        strcpy(this->ime,pc.ime);
        this->brPici=pc.brPici;
        delete[]p;
        p=new Pica[brPici];
        for (int i = 0; i < brPici; ++i)
            this->p[i]=pc.p[i];
        }
        return *this;
    }
    ~Picerija(){
        delete[]p;
    }
    Picerija &operator +=(const Pica &other){
        bool imaIsta=false;
        for (int i = 0; i < brPici; ++i)
            if(p[i].istiSe(other))
                imaIsta=true;
            if(!imaIsta){
                Pica * tmp = new Pica[brPici+1];
                for (int i = 0; i< brPici; ++i)
                    tmp[i]=p[i];
                    tmp[brPici++]=other;
                    delete[]p;
                    p=tmp;
;                }
                return *this;
        }
    void piciNaPromocija(){
        for (int i = 0; i < brPici; ++i) {
            if(p[i].getNamaluvanje()!=0){
                p[i].pecati();
                cout<<" "<<p[i].getCena() * (1 - p[i].getNamaluvanje() /100.0)<<endl;
            }
        }
    }

    const char *getIme()  {
        return ime;
    }
    void setIme(const char *ime){
        strncpy(this->ime,ime,14);
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
