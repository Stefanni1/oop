#include<iostream>
#include<cstring>
using namespace std;

class Koncert{
private:
    char naziv[20];
    char lokacija[20];
    float cenaBilet, sezonskiPopust;
public:
    Koncert(char *naziv="", char *lokacija="", float cenaBilet=0.0, float sezonskiPopust=0.0) :
                                                                                  cenaBilet(cenaBilet),
                                                                                  sezonskiPopust(sezonskiPopust) {
        strcpy(this->naziv,naziv);
        strcpy(this->lokacija,lokacija);
    }
    float sezonski(){
        sezonskiPopust=20;
        float popust = sezonskiPopust * 0.01;
        return cenaBilet * (1-popust);
    }
    virtual float cena(){
        return sezonski();
    }

    float getCenaBilet() const {
        return cenaBilet;
    }

    const char *getNaziv() const {
        return naziv;
    }

    float getSezonskiPopust() const {
        return sezonskiPopust;
    }

    void setSezonskiPopust(float sezonskiPopust) {
        Koncert::sezonskiPopust = sezonskiPopust;
    }
    virtual bool isElektronski()const{
        return false;
    }

    ~Koncert(){}
};
class ElektronskiKoncert : public Koncert {
private:
    string name;
    float vremetraenje;
    bool isDayParty;
public:
    ElektronskiKoncert(char *naziv = "", char *lokacija = "", float cenaBilet = 0.0,
                       const string &name = "", float vremetraenje = 0.0, bool isDayParty = false) : Koncert(naziv,
                                                                                                             lokacija,
                                                                                                             cenaBilet),
                                                                                                     name(name),
                                                                                                     vremetraenje(
                                                                                                             vremetraenje),
                                                                                                     isDayParty(
                                                                                                             isDayParty) {}

bool isElektronski()const override{
        return true;
    }
    float cena() override {
        float finalnaCena = sezonski();
        if (vremetraenje > 5) {
            finalnaCena += 150;
        } else if (vremetraenje > 7) {
            finalnaCena += 360;
        }
        if (isDayParty) {
            finalnaCena -= 50;
        } else {
            finalnaCena += 100;
        }
        return finalnaCena;
    }

};
void najskapKoncert(Koncert ** koncerti, int n){
    Koncert * najskap = koncerti[0];
    int brojElektronski = 0;
    for (int i = 0; i < n; ++i) {
        if(koncerti[i]->cena() > najskap->cena()){
            najskap = koncerti[i];
        }
        if(koncerti[i]->isElektronski()){
            brojElektronski++;
        }
    }
    cout << "Najskap koncert: " << najskap->getNaziv() << " " << najskap->cena() << endl;
    cout << "Elektronski koncerti: " << brojElektronski << " od vkupno " << n << endl;
}

bool prebarajKoncert(Koncert ** koncerti, int n,char * naziv, bool elektronski){
    bool found=false;
    for (int i = 0; i < n; ++i) {
        if(strcmp(koncerti[i]->getNaziv(),naziv)==0 && (elektronski && koncerti[i]->isElektronski()|| !elektronski)){
            cout<<"Koncert: "<<koncerti[i]->getNaziv()<<"Cena; "<<koncerti[i]->cena()<<endl;
       found = true;
        }
    }
return found;
}


int main(){

    int tip,n,novaCena;
    char naziv[100], lokacija[100], imeDJ[40];
    bool dnevna;
    float cenaBilet, novPopust;
    float casovi;

    cin>>tip;
    if (tip==1){//Koncert
        cin>>naziv>>lokacija>>cenaBilet;
        Koncert k1(naziv,lokacija,cenaBilet);
        cout<<"Kreiran e koncert so naziv: "<<k1.getNaziv()<<endl;
    }
    else if (tip==2){//cena - Koncert
        cin>>naziv>>lokacija>>cenaBilet;
        Koncert k1(naziv,lokacija,cenaBilet);
        cout<<"Osnovna cena na koncertot so naziv "<<k1.getNaziv()<< " e: " <<k1.cena()<<endl;
    }
    else if (tip==3){//ElektronskiKoncert
        cin>>naziv>>lokacija>>cenaBilet>>imeDJ>>casovi>>dnevna;
        ElektronskiKoncert s(naziv,lokacija,cenaBilet,imeDJ,casovi,dnevna);
        cout<<"Kreiran e elektronski koncert so naziv "<<s.getNaziv()<<" i sezonskiPopust "<<s.getSezonskiPopust()<<endl;
    }
    else if (tip==4){//cena - ElektronskiKoncert
        cin>>naziv>>lokacija>>cenaBilet>>imeDJ>>casovi>>dnevna;
        ElektronskiKoncert s(naziv,lokacija,cenaBilet,imeDJ,casovi,dnevna);
        cout<<"Cenata na elektronskiot koncert so naziv "<<s.getNaziv()<<" e: "<<s.cena()<<endl;
    }
    else if (tip==5) {//najskapKoncert

    }
    else if (tip==6) {//prebarajKoncert
        Koncert ** koncerti = new Koncert *[5];
        int n;
        koncerti[0] = new Koncert("Area","BorisTrajkovski",350);
        koncerti[1] = new ElektronskiKoncert("TomorrowLand","Belgium",8000,"Afrojack",7.5,false);
        koncerti[2] = new ElektronskiKoncert("SeaDance","Budva",9100,"Tiesto",5,true);
        koncerti[3] = new Koncert("Superhiks","PlatoUkim",100);
        koncerti[4] = new ElektronskiKoncert("CavoParadiso","Mykonos",8800,"Guetta",3,true);
        char naziv[100];
        najskapKoncert(koncerti,5);
    }
    else if (tip==7){//prebaraj
        Koncert ** koncerti = new Koncert *[5];
        int n;
        koncerti[0] = new Koncert("Area","BorisTrajkovski",350);
        koncerti[1] = new ElektronskiKoncert("TomorrowLand","Belgium",8000,"Afrojack",7.5,false);
        koncerti[2] = new ElektronskiKoncert("SeaDance","Budva",9100,"Tiesto",5,true);
        koncerti[3] = new Koncert("Superhiks","PlatoUkim",100);
        koncerti[4] = new ElektronskiKoncert("CavoParadiso","Mykonos",8800,"Guetta",3,true);
        char naziv[100];
        bool elektronski;
        cin>>elektronski;
        if(prebarajKoncert(koncerti,5, "Area",elektronski))
            cout<<"Pronajden"<<endl;
        else cout<<"Ne e pronajden"<<endl;

        if(prebarajKoncert(koncerti,5, "Area",!elektronski))
            cout<<"Pronajden"<<endl;
        else cout<<"Ne e pronajden"<<endl;

    }
    else if (tip==8){//smeni cena
        Koncert ** koncerti = new Koncert *[5];
        int n;
        koncerti[0] = new Koncert("Area","BorisTrajkovski",350);
        koncerti[1] = new ElektronskiKoncert("TomorrowLand","Belgium",8000,"Afrojack",7.5,false);
        koncerti[2] = new ElektronskiKoncert("SeaDance","Budva",9100,"Tiesto",5,true);
        koncerti[3] = new Koncert("Superhiks","PlatoUkim",100);
        koncerti[2] -> setSezonskiPopust(0.9);
        najskapKoncert(koncerti,4);
    }

    return 0;
}
