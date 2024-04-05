#include<iostream>
#include<cstring>
using namespace std;
class Patnik{
private:
    char name[100];
    int vagon;
    bool velosiped;
public:
    Patnik(char * name="", int vagon=0,bool velosiped=true){
        strcpy(this->name,name);
        this->vagon=vagon;
        this->velosiped=velosiped;
    }
    Patnik(const Patnik &p){
        strcpy(this->name,p.name);
        this->vagon=p.vagon;
        this->velosiped=p.velosiped;
    }
    friend ostream &operator<<(ostream &out, Patnik &p){
        out<<p.name<<endl;
        out<<p.vagon<<endl;
        out<<p.velosiped<<endl;
        return out;
    }

    int getVagon() const {
        return vagon;
    }

    bool getVelosiped() const {
        return velosiped;
    }

    ~Patnik(){}
};
class Voz{
private:
    char destinacija[100];
    Patnik * patnik;
    int brElementi;
    int brVelosipedi;
public:
    Voz(char *destinacija="", int brVelosipedi=0){
        strcpy(this->destinacija,destinacija);
        this->patnik=new Patnik[brElementi];
        this->brElementi=0;
        this->brVelosipedi=brVelosipedi;
    }
    Voz(const Voz &v){
        strcpy(this->destinacija,v.destinacija);
        this->brElementi=v.brElementi;
        this->patnik=new Patnik[v.brElementi];
        for (int i = 0; i < brElementi; ++i) {
            this->patnik[i]=v.patnik[i];
        }
        this->brVelosipedi=v.brVelosipedi;
    }
    Voz &operator=(const Voz &v){
        if(this!=&v){
            delete[]patnik;
            strcpy(this->destinacija,v.destinacija);
            this->brElementi=v.brElementi;
            this->patnik=new Patnik[v.brElementi];
            for (int i = 0; i < brElementi; ++i) {
                this->patnik[i]=v.patnik[i];
            }
        }
        return *this;
    }
    Voz &operator+=(const Patnik &other){
        if(other.getVelosiped() && !brVelosipedi){
            return *this;
        }
        Patnik *tmp =new Patnik[brElementi+1];
        for (int i = 0; i < brElementi; ++i) {
            tmp[i]=patnik[i];
        }
        tmp[brElementi++]=other;
        delete[]patnik;
        this->patnik=new Patnik[brElementi];
        for (int i = 0; i < brElementi; ++i) {
            patnik[i]=tmp[i];
        }
        delete[]tmp;
        return *this;
    }
    friend ostream &operator<<(ostream &out, Voz &v){
        out<<v.destinacija<<" "<<endl;
        for (int i = 0; i < v.brElementi; ++i) {
            out<<v.patnik[i]<<endl;
        }
        return out;
    }
    void patniciNemaMesto(){
        int m1=0, m2=0, bc=brVelosipedi;
        for (int i = 0; i < brElementi; ++i) {
            if(patnik[i].getVelosiped() && patnik[i].getVagon()==1){
                if(bc){
                    bc--;
                }
                else{
                    m1++;
                }
            }
        }
        for (int i = 0; i < brElementi; ++i) {
            if(patnik[i].getVelosiped() && patnik[i].getVagon()==2){
                if(bc){
                    bc--;
                }
                else{
                    m2++;
                }
            }
        }
        cout<< "Brojot na patnici od 1-va klasa koi ostanale bez mesto e: "<<m1<<endl;
        cout<< "Brojot na patnici od 2-ra klasa koi ostanale bez mesto e: "<<m2<<endl;
    }
    ~Voz(){
        delete[]patnik;
    }

};


int main()
{
    Patnik p;
    char ime[100], destinacija[100];
    int n;
    bool velosiped;
    int klasa;
    int maxv;
    cin >> destinacija >> maxv;
    cin >> n;
    Voz v(destinacija, maxv);
    //cout<<v<<endl;
    for (int i = 0; i < n; i++){
        cin >> ime >> klasa >> velosiped;
        Patnik p(ime, klasa, velosiped);
        //cout<<p<<endl;
        v += p;
    }
    cout << v;
    v.patniciNemaMesto();

    return 0;
}
