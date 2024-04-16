#include<iostream>
#include<cstring>
using namespace std;
class Ucesnik{
private:
    char * name;
    bool pol;
    int vozrast;
public:
    Ucesnik(char * name="", bool pol=true, int vozrast=0){
        this->name=new char[strlen(name)+1];
        strcpy(this->name,name);
        this->pol=pol;
        this->vozrast=vozrast;
    }
    Ucesnik(const Ucesnik &u){
        this->name=new char[strlen(u.name)+1];
        strcpy(this->name,u.name);
        this->pol=u.pol;
        this->vozrast=u.vozrast;
    }
    Ucesnik &operator =(const Ucesnik &u){
        if(this!=&u){
            delete[]name;
            this->name=new char[strlen(u.name)+1];
            strcpy(this->name,name);
            this->pol=u.pol;
            this->vozrast=u.vozrast;
        }
        return *this;
    }
    bool operator>(const Ucesnik &u)const{
        return this->vozrast>u.vozrast;
    }
    friend ostream &operator<<(ostream &out, const Ucesnik &u){
        out<<u.name<<endl;
        out<<u.pol<<(u.pol ? "mashki" : "zhenski")<<endl;
        out<<u.vozrast<<endl;
        return out;
    }
    ~Ucesnik(){
        delete[]name;
    }

    char *getName() const {
        return name;
    }

    bool isPol() const {
        return pol;
    }

    int getVozrast() const {
        return vozrast;
    }
};
class Maraton{
private:
    char  lokacija[100];
    Ucesnik * ucesnici;
    int brUcesnici;
public:
    Maraton(char * lokacija="", Ucesnik * ucesnici=NULL, int brUcesnici=0){
        strcpy(this->lokacija,lokacija);
        this->ucesnici=ucesnici;
        this->brUcesnici=brUcesnici;
    }
    Maraton(const Maraton &m){
        strcpy(this->lokacija,m.lokacija);
        this->ucesnici= new Ucesnik[m.brUcesnici];
        this->brUcesnici=m.brUcesnici;
        for (int i = 0; i < m.brUcesnici; ++i) {
            this->ucesnici[i]=m.ucesnici[i];
        }
    }
    Maraton &operator=(const Maraton &m){
        if(this!=&m){
            delete[]ucesnici;
            strcpy(this->lokacija,m.lokacija);
            this->ucesnici= new Ucesnik[m.brUcesnici];
            this->brUcesnici=m.brUcesnici;
            for (int i = 0; i < m.brUcesnici; ++i) {
                this->ucesnici[i]=m.ucesnici[i];
            }
        }
        return *this;
    }
    Maraton &operator+=(const Ucesnik &u){
        Ucesnik * temp = new Ucesnik[brUcesnici+1];
        for (int i = 0; i < brUcesnici; ++i) {
            temp[i]=ucesnici[i];
        }
        temp[brUcesnici]=u;
        delete[]ucesnici;
        ucesnici=temp;
        brUcesnici++;
        return *this;
    };
    ~Maraton(){
        delete[]ucesnici;
    }
    double prosecnoVozrast(){
        double sum=0;
        for (int i = 0; i < brUcesnici; ++i) {
            sum+=ucesnici[i].getVozrast();
        }
        return sum/brUcesnici;
    }
    void pecatiPomladi(Ucesnik &u){
        for (int i = 0; i < brUcesnici; ++i) {
            if(ucesnici[i].getVozrast() < u.getVozrast()){
                cout<<ucesnici[i]<<endl;
            }
        }
    }
};

int main() {
    char ime[100];
    bool maski;
    int vozrast, n;
    cin >> n;
    char lokacija[100];
    cin >> lokacija;
    Maraton m(lokacija);
    Ucesnik **u = new Ucesnik*[n];
    for(int i = 0; i < n; ++i) {
        cin >> ime >> maski >> vozrast;
        u[i] = new Ucesnik(ime, maski, vozrast);
        m += *u[i];
    }
    m.pecatiPomladi(*u[n - 1]);
    cout << m.prosecnoVozrast() << endl;
    for(int i = 0; i < n; ++i) {
        delete u[i];
    }
    delete [] u;
    return 0;
}