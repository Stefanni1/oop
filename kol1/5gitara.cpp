#include<iostream>
#include<cstring>
using namespace std;
class Gitara{
private:
    char seriski[25];
    float cena;
    int godina;
    char tip[40];
public:
    Gitara(char * seriski="", float cena=0.0,int godina=0,char * tip=""){
        strcpy(this->seriski,seriski);
        this->cena=cena;
        this->godina=godina;
        strcpy(this->tip,tip);
    }
    Gitara(const Gitara &g){
        strcpy(this->seriski,g.seriski);
        this->cena=g.cena;
        this->godina=g.godina;
        strcpy(this->tip,g.tip);
    }
    bool daliIsti( Gitara g){
        if(seriski != g.seriski){
            bool daliIsti=false;
        }
        else {
            bool daliIsti=true;
        }
    }
    void pecati(){
        cout<<"[ "<<seriski<<"] "<<"[ "<<tip<<"] "<<"[ "<<cena<<"] "<<endl;
    }

    const char *getSeriski() const {
        return seriski;
    }

    float getCena() const {
        return cena;
    }

    int getGodina() const {
        return godina;
    }

    const char *getTip() const {
        return tip;
    }

    ~Gitara(){}
};
class Magacin{
private:
    char ime[30];
    char lokacija[60];
    Gitara * gitari;
    int br;
    int god;
public:
    Magacin(char *ime="",char * lokacija="",Gitara * gitari=0, int br=0,int god=0){
        strcpy(this->ime,ime);
        strcpy(this->lokacija,lokacija);
        this->gitari=new Gitara[br];
        this->br=br;
        this->god=god;
    }
    Magacin(const Magacin &m){
        strcpy(this->ime,m.ime);
        strcpy(this->lokacija,m.lokacija);
        this->gitari=new Gitara[m.br];
        this->br=m.br;
        this->god=m.god;
    }
    Magacin &operator=(const Magacin &m){
        if(this!=&m){
            delete[]gitari;
            strcpy(this->ime,m.ime);
            strcpy(this->lokacija,m.lokacija);
            this->br=m.br;
            this->god=m.god;
        }
        return *this;
    }
    double vrednost(){
        double sum=0;

    }
};






int main() {
    // se testira zadacata modularno
    int testCase;
    cin >> testCase;

    int n, godina;
    float cena;
    char seriski[50],tip[50];

    if(testCase == 1) {
        cout << "===== Testiranje na klasata Gitara ======" << endl;
        cin>>tip;
        cin>>seriski;
        cin >> godina;
        cin >> cena;
        Gitara g(tip,seriski, godina,cena);
        cout<<g.getTip()<<endl;
        cout<<g.getSeriski()<<endl;
        cout<<g.getGodina()<<endl;
        cout<<g.getNabavna()<<endl;
    } else if(testCase == 2){
        cout << "===== Testiranje na klasata Magacin so metodot print() ======" << endl;
        Magacin kb("Magacin1","Lokacija1");
        kb.pecati(false);
    }
    else if(testCase == 3) {
        cout << "===== Testiranje na klasata Magacin so metodot dodadi() ======" << endl;
        Magacin kb("Magacin1","Lokacija1",2005);
        cin>>n;
        for (int i=0;i<n;i++){
            cin>>tip;
            cin>>seriski;
            cin >> godina;
            cin >> cena;
            Gitara g(tip,seriski, godina,cena);
            cout<<"gitara dodadi"<<endl;
            kb.dodadi(g);
        }
        kb.pecati(true);
    }

    else if(testCase == 4) {
        cout << "===== Testiranje na klasata Magacin so metodot prodadi() ======" << endl;
        Magacin kb("Magacin1","Lokacija1",2012);
        cin>>n;
        Gitara brisi;
        for (int i=0;i<n;i++){
            cin>>tip;
            cin>>seriski;
            cin >> godina;
            cin >> cena;

            Gitara g(tip,seriski, godina,cena);
            if(i==2)
                brisi=g;
            cout<<"gitara dodadi"<<endl;
            kb.dodadi(g);
        }
        kb.pecati(false);
        kb.prodadi(brisi);
        kb.pecati(false);
    }
    else if(testCase == 5) {
        cout << "===== Testiranje na klasata Magacin so metodot prodadi() i pecati(true) ======" << endl;
        Magacin kb("Magacin1","Lokacija1",2011);
        cin>>n;
        Gitara brisi;
        for (int i=0;i<n;i++){
            cin>>tip;
            cin>>seriski;
            cin >> godina;
            cin >> cena;

            Gitara g(tip,seriski, godina,cena);
            if(i==2)
                brisi=g;
            cout<<"gitara dodadi"<<endl;
            kb.dodadi(g);
        }
        kb.pecati(true);
        kb.prodadi(brisi);
        cout<<"Po brisenje:"<<endl;
        Magacin kb3;
        kb3=kb;
        kb3.pecati(true);
    }
    else if(testCase ==6)
    {
        cout << "===== Testiranje na klasata Magacin so metodot vrednost()======" << endl;
        Magacin kb("Magacin1","Lokacija1",2011);
        cin>>n;
        Gitara brisi;
        for (int i=0;i<n;i++){
            cin>>tip;
            cin>>seriski;
            cin >> godina;
            cin >> cena;

            Gitara g(tip,seriski, godina,cena);
            if(i==2)
                brisi=g;
            kb.dodadi(g);
        }
        cout<<kb.vrednost()<<endl;
        kb.prodadi(brisi);
        cout<<"Po brisenje:"<<endl;
        cout<<kb.vrednost();
        Magacin kb3;
        kb3=kb;
    }
    return 0;
}
