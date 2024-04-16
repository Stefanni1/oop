#include<iostream>
#include<cstring>
using namespace std;
class Gitara{
private:
    char seriski[25];
    float nabavna;
    int godina;
    char tip[40];
public:
    Gitara(char * tip="",char * seriski="", int godina=0,float cena=0.0){
        strcpy(this->seriski,seriski);
        this->nabavna=cena;
        this->godina=godina;
        strcpy(this->tip,tip);
    }
    Gitara(const Gitara &g){
        strcpy(this->seriski,g.seriski);
        this->nabavna=g.nabavna;
        this->godina=g.godina;
        strcpy(this->tip,g.tip);
    }
    Gitara &operator=(const Gitara &g){
        strcpy(this->seriski,g.seriski);
        this->nabavna=g.nabavna;
        this->godina=g.godina;
        strcpy(this->tip,g.tip);
        return *this;
    }
    ~Gitara(){}
    bool daliIsti( Gitara &g){
        return strcmp(this->seriski, g.seriski)==0;
    }
    void pecati(){
        cout << seriski << " " << tip << " " << nabavna << endl;
    }

    const char *getSeriski() const {
        return seriski;
    }

    float getNabavna() const {
        return nabavna;
    }

    int getGodina() const {
        return godina;
    }

    const char *getTip() const {
        return tip;
    }


};
class Magacin{
private:
    char ime[30];
    char lokacija[60];
    Gitara * gitari;
    int br;
    int god;
public:
    Magacin(char *ime="",char * lokacija="",int god=0,Gitara * gitari=0, int br=0){
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
        for (int i = 0; i < m.br; ++i) {
            gitari[i]=m.gitari[i];
            br=m.br;
        }
    }
    Magacin &operator=(const Magacin &m){
        if(this!=&m){
            delete[]gitari;
            this->br=m.br;
            this->god=m.god;
            gitari=new Gitara[br];
            for (int i = 0; i < br; ++i) {
                gitari[i]=m.gitari[i];
            }
            strcpy(this->ime,m.ime);
            strcpy(this->lokacija,m.lokacija);

        }
        return *this;
    }
    ~Magacin(){
        delete[]gitari;
    }

    double vrednost() {
        double sum = 0;
        for (int i = 0; i < br; ++i) {
            sum += gitari[i].getNabavna();
        }
        return sum;
    }
    void dodadi(Gitara d){
        Gitara * tmp = new Gitara[br+1];
        for (int i = 0; i < br; ++i){
            tmp[i]=gitari[i];
        }
            tmp[br]=d;
            delete[]gitari;
            gitari=tmp;
            br++;
    }
    void prodadi(Gitara p){
        int newBr=0;
        for (int i = 0; i < br; ++i) {
            if(!gitari[i].daliIsti(p)){
                newBr++;
            }
        }
        Gitara * tmp = new Gitara[newBr];
        int j=0;
        for (int i = 0; i < br; ++i) {
            if(!gitari[i].daliIsti(p)){
                tmp[j]=gitari[i];
                j++;
            }
        }
        delete[]gitari;
        gitari=tmp;
        br=newBr;
    }
    void pecati(bool daliNovi){
        cout<<ime<<" "<<lokacija<<" "<<endl;
        for (int i = 0; i < br; ++i) {
            if(daliNovi==true && gitari[i].getGodina()>god){
                gitari[i].pecati();
            }
            else if(daliNovi==false){
                gitari[i].pecati();
            }
        }
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
