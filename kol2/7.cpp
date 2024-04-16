#include<iostream>
#include<cstring>
using namespace std;

class Karticka{
protected:
    char smetka[16];
    int pin;
    bool povekjePin;
public:
    Karticka(char* smetka,int pin){
        strcpy(this->smetka,smetka);
        this->pin=pin;
        this->povekjePin=false;
    }
    virtual int tezinaProbivanje(){

    }
    bool getDopolnitelenPin(){
        return povekjePin;
    };
    char * getSmetka(){
        return smetka;
    }
    // дополниете ја класата
    friend ostream &operator<<(ostream &out, Karticka &k){
        out<<k.smetka<<": "<<k.tezinaProbivanje()<<endl;
        int a=k.tezinaProbivanje();
        return out;
    }
    ~Karticka(){}
};
class OutOfBondException{
public:
    void print(){
        cout<<"Brojot na pin kodovi ne moze da go nadmine dozvolenoto"<<endl;
    }
};
//вметнете го кодот за SpecijalnaKarticka
class SpecijalnaKarticka : Karticka{
  int * dopolnitelenPin;
  int brojPin;
  static int p;
public:
    SpecijalnaKarticka(char *smetka, int pin, int *dopolnitelenPin, int brojPin);

    int tezinaProbivanje() override{
        return (Karticka::tezinaProbivanje()+brojPin);
    }
    friend ostream &operator<<(ostream &out, SpecijalnaKarticka &sk){
        out<<sk.smetka<<": "<<sk.tezinaProbivanje()<<endl;
        return out;
    }
    SpecijalnaKarticka &operator+=(int pin){
        if(brojPin<5) throw OutOfBondException();
        int *tmp = new int[brojPin+1];
        for (int i = 0; i < brojPin; ++i) {
            tmp[i]=dopolnitelenPin[i];
        }
        tmp[brojPin++]=pin;
        dopolnitelenPin=tmp;
        return *this;
    }
};
int SpecijalnaKarticka::p =4;

SpecijalnaKarticka::SpecijalnaKarticka(char *smetka, int pin, int *dopolnitelenPin, int brojPin) : Karticka(smetka,
                                                                                                            pin),
                                                                                                   dopolnitelenPin(
                                                                                                           dopolnitelenPin),
                                                                                                   brojPin(brojPin) {}

class Banka {
private:
    char naziv[30];
    Karticka *karticki[20];
    int broj;
    static int LIMIT;
public:
    Banka(char *naziv, Karticka** karticki,int broj ){
        strcpy(this->naziv,naziv);
        for (int i=0;i<broj;i++){
            //ako kartickata ima dopolnitelni pin kodovi
            if (karticki[i]->getDopolnitelenPin()){
                this->karticki[i]=new SpecijalnaKarticka(*dynamic_cast<SpecijalnaKarticka*>(karticki[i]));
            }
            else this->karticki[i]=new Karticka(*karticki[i]);
        }
        this->broj=broj;
    }
    ~Banka(){
        for (int i=0;i<broj;i++) delete karticki[i];
    }

    //да се дополни класата

};



int main(){

    Karticka **niza;
    int n,m,pin;
    char smetka[16];
    bool daliDopolnitelniPin;
    cin>>n;
    niza=new Karticka*[n];
    for (int i=0;i<n;i++){
        cin>>smetka;
        cin>>pin;
        cin>>daliDopolnitelniPin;
        if (!daliDopolnitelniPin)
            niza[i]=new Karticka(smetka,pin);
        else
            niza[i]=new SpecijalnaKarticka(smetka,pin);
    }

    Banka komercijalna("Komercijalna",niza,n);
    for (int i=0;i<n;i++) delete niza[i];
    delete [] niza;
    cin>>m;
    for (int i=0;i<m;i++){
        cin>>smetka>>pin;

        komercijalna.dodadiDopolnitelenPin(smetka,pin);

    }

    Banka::setLIMIT(5);

    komercijalna.pecatiKarticki();

}
