#include<iostream>
#include<cstring>
#include <cstdlib>
using namespace std;
class Oglas{
protected:
    char naslov[50];
    char kategorija[30];
    char opis[100];
    float cena;
public:
    Oglas() : cena(cena) {
        strcpy(this->naslov,naslov);
        strcpy(this->kategorija,kategorija);
        strcpy(this->opis,opis);
    }
    bool operator > (Oglas &o){
        return this-> cena > o.cena;
    }
    friend ostream &operator <<(ostream &out, Oglas &o){
        out<<o.naslov<<" "<<endl;
        out<<o.opis<<" "<<endl;
        out<<o.cena<<"evra"<<endl;
        return out;
    }
    float getCena(){return cena;}
    char *getKategorija(){return kategorija;}
};

class NegativnaVrednost{
public:
    void print(){
        cout << "Oglasot ima nevalidna vrednost za cenata i nema da bide evidentiran!\n";
    }
};

class Oglasnik{
    char ime[20];
    Oglas *oglasi = nullptr;
    int n;
public:
    Oglasnik(char * ime): oglasi(nullptr),n(0){
        strncpy(this->ime,ime,20);
        this->ime[19]='\0';
    }
    Oglasnik& operator+=(Oglas &o) {
        if (o.getCena() < 0)
            throw NegativnaVrednost();
    }
        Oglas* tmp = new Oglas[n + 1];
        for (int i = 0; i < n; ++i) {
        tmp[i] = oglasi[i];
    }
        tmp[n++] = o;
        delete[]oglasi;
        oglasi = tmp;

        return *this;
    }
    friend ostream &operator << (ostream &out, Oglasnik &os){
        out<<os.ime<<" "<<endl;
        for (int i = 0; i < os.n; ++i) {
            out<<os.oglasi[i]<<endl;
        }
        return out;
    }
    void oglasiOdKategorija(const char *k){
        for (int i = 0; i < n; ++i) {
            if(strcmp(oglasi[i].getKategorija(),k)==0) cout<<oglasi[i]<<endl;
        }
    }
    void najniskaCena(){
        Oglas najevtin=oglasi[0];
        for (int i = 1; i < n; ++i) {
            if(oglasi[i].getCena()<najevtin.getCena())
                najevtin=oglasi[i];
        }
        cout<<najevtin;
    }
};

int main(){

    char naslov[50];
    char kategorija[30];
    char opis[100];
    float cena;
    char naziv[50];
    char k[30];
    int n;

    int tip;
    cin>>tip;

    if (tip==1){
        cout<<"-----Test Oglas & operator <<-----" <<endl;
        cin.get();
        cin.getline(naslov,49);
        cin.getline(kategorija,29);
        cin.getline(opis,99);
        cin>>cena;
        Oglas o();
        cout<<o;
    }
    else if (tip==2){
        cout<<"-----Test Oglas & operator > -----" <<endl;
        cin.get();
        cin.getline(naslov,49);
        cin.getline(kategorija,29);
        cin.getline(opis,99);
        cin>>cena;
        Oglas o1();
        cin.get();
        cin.getline(naslov,49);
        cin.getline(kategorija,29);
        cin.getline(opis,99);
        cin>>cena;
        Oglas o2();
        if (o1>o2) cout<<"Prviot oglas e poskap."<<endl;
        else cout<<"Prviot oglas ne e poskap."<<endl;
    }
    else if (tip==3){
        cout<<"-----Test Oglasnik, operator +=, operator << -----" <<endl ;
        cin.get();
        cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
            Oglas o();
            ogl+=o;
        }
        cout<<ogl;
    }
    else if (tip==4){
        cout<<"-----Test oglasOdKategorija -----" <<endl ;
        cin.get();
        cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
            Oglas o();
            ogl+=o;
        }
        cin.get();
        cin.getline(k,29);
        cout<<"Oglasi od kategorijata: " <<k<<endl;
        ogl.oglasiOdKategorija(k);

    }
    else if (tip==5){
        cout<<"-----Test Exception -----" <<endl ;
        cin.get();
        cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
            Oglas o();
            ogl+=o;
        }
        cout<<ogl;

    }
    else if (tip==6){
        cout<<"-----Test najniskaCena -----" <<endl ;
        cin.get();
        cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
            Oglas o();
            ogl+=o;
        }
        cout<<"Oglas so najniska cena:"<<endl;
        ogl.najniskaCena();

    }
    else if (tip==7){
        cout<<"-----Test All -----" <<endl ;
        cin.get();
        cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
            Oglas o();
            ogl+=o;
        }
        cout<<ogl;

        cin.get();
        cin.get();
        cin.getline(k,29);
        cout<<"Oglasi od kategorijata: " <<k<<endl;
        ogl.oglasiOdKategorija(k);

        cout<<"Oglas so najniska cena:"<<endl;
        ogl.najniskaCena();

    }

    return 0;
}
