#include<iostream>
#include<cstring>
using namespace std;
class Transport{
protected:
    char * destinacija;
    int cena,km;

public:
    Transport(char * destinacija="", int cena=0,int km=0){
        strcpy(destinacija,destinacija);
        this->cena=cena;
        this->km=km;
    }
    virtual double cenaTransport() {
        return cena;
    };
    virtual void pecati(){
        cout<<destinacija<<" "<<km<<" "<<endl;
    }
    ~Transport(){}

    char *getDestinacija() const {
        return destinacija;
    }

    void setDestinacija(char *destinacija) {
        Transport::destinacija = destinacija;
    }

    int getCena() const {
        return cena;
    }

    void setCena(int cena) {
        Transport::cena = cena;
    }

    int getKm() const {
        return km;
    }

    void setKm(int km) {
        Transport::km = km;
    }
};
class AvtomobilTransport : public Transport{
private:
    bool shofer=true;

    double cenaTransport()override{
        return ((shofer) ? cena*0.2 : cena);
    }

public:
    AvtomobilTransport(char * destinacija="", int cena=0,int km=0,bool shofer=true) : Transport(destinacija,cena,km), shofer(shofer){}
};
class KombeTransport : public Transport{
private:
    int lugje;

    double cenaTransport()override{
        double c= cena - lugje * 200;
        if(c<0)return 0;
        else return c;
    }
    bool operator<(const Transport &other){
        return this->km < other.getKm();
    }

public:
    KombeTransport(char * destinacija="", int cena=0,int km=0,int lugje=0) : Transport(destinacija,cena,km), lugje(lugje){}
};
void pecatiPoloshiPonudi(Transport** ponudi, int n, const Transport& T){
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (ponudi[i]->cenaTransport() > ponudi[j]->cenaTransport()) {
                swap(ponudi[i], ponudi[j]);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if(ponudi[i]->cenaTransport()>T.getCena())
            ponudi[i]->pecati();
    }
}

int main(){

    char destinacija[20];
    int tip,cena,rastojanie,lugje;
    bool shofer;
    int n;
    cin>>n;
    Transport  **ponudi;
    ponudi=new Transport *[n];

    for (int i=0;i<n;i++){

        cin>>tip>>destinacija>>cena>>rastojanie;
        if (tip==1) {
            cin>>shofer;
            ponudi[i]=new AvtomobilTransport(destinacija,cena,rastojanie,shofer);

        }
        else {
            cin>>lugje;
            ponudi[i]=new KombeTransport(destinacija,cena,rastojanie,lugje);
        }


    }

    AvtomobilTransport nov("Ohrid",2000,600,false);
    pecatiPoloshiPonudi(ponudi,n,nov);

    for (int i=0;i<n;i++) delete ponudi[i];
    delete [] ponudi;
    return 0;
}
