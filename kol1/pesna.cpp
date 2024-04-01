#include<iostream>
#include<cstring>
using namespace std;
enum tip{
    POP,
    RAP,
    ROCK
};
class Pesna{
private:
    char *name[50];
    double time;
    tip songTip;
public:
    Pesna(const char *name="", double time=0.0, tip songTip = POP) :  time(time), songTip(songTip) {
        strcpy(this->name,name);
    }
    void pecati(){
        cout<<'"' << name << '"'<< " - " << time <<"min"<<endl;
    }
    double getTime() const {
        return time;
    }

    tip getTip() const {
        return songTip;
    }

};
class CD{
private:
    Pesna pesni[10];
    int broj;
    double max;
public:
    CD(Pesna *pesni, int broj, double max) : broj(0), max(max) {
        strcpy(this->pesni,pesni);
    }

    CD(const CD &omileno){
        this->broj=omileno.broj;
        this->min=omileno.min;
        for (int i = 0; i < broj && i < 10; ++i) {
            pesni[i]=omileno.pesni[i];
        }

    }

    const Pesna *getPesni() const {
        return pesni;
    }
    void dodadiPesna(const Pesna &p){
        if(broj < 10 && (getVkupnoVreme() + p.getTime() <= max)){
            pesni[broj++]=p;
        }

    }

    double getVkupnoVreme() const{
        double vkupnoVreme=0;
        for (int i = 0; i < broj; ++i) {
            vkupnoVreme+=pesni[i].getTime();
        }
        return vkupnoVreme;
    }

    void pecatiPesniPoTip(tip t) {
        for (int i = 0; i < broj; ++i) {
            if(pesni[i].getTip()==t){
                pesni[i].pecati();
            }
        }
    }

    int getBroj() const {
        return broj;
    }

    double getMax() const {
        return max;
    }
    const Pesna &getPesna(int index)const{
        return pesni[index];
    }


};








int main() {
    // se testira zadacata modularno
    int testCase;
    cin >> testCase;

    int n, minuti, kojtip;
    char ime[50];

    if(testCase == 1) {
        cout << "===== Testiranje na klasata Pesna ======" << endl;
        cin >> ime;
        cin >> minuti;
        cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
        Pesna p(ime,minuti,(tip)kojtip);
        p.pecati();
    } else if(testCase == 2) {
        cout << "===== Testiranje na klasata CD ======" << endl;
        CD omileno(20);
        cin>>n;
        for (int i=0;i<n;i++){
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime,minuti,(tip)kojtip);
            omileno.dodadiPesna(p);
        }
        for (int i=0; i<n; i++)
            (omileno.getPesna(i)).pecati();
    }
    else if(testCase == 3) {
        cout << "===== Testiranje na metodot dodadiPesna() od klasata CD ======" << endl;
        CD omileno(20);
        cin>>n;
        for (int i=0;i<n;i++){
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime,minuti,(tip)kojtip);
            omileno.dodadiPesna(p);
        }
        for (int i=0; i<omileno.getBroj(); i++)
            (omileno.getPesna(i)).pecati();
    }
    else if(testCase == 4) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
        CD omileno(20);
        cin>>n;
        for (int i=0;i<n;i++){
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime,minuti,(tip)kojtip);
            omileno.dodadiPesna(p);
        }
        cin>>kojtip;
        omileno.pecatiPesniPoTip((tip)kojtip);

    }
    else if(testCase == 5) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
        CD omileno(20);
        cin>>n;
        for (int i=0;i<n;i++){
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime,minuti,(tip)kojtip);
            omileno.dodadiPesna(p);
        }
        cin>>kojtip;
        omileno.pecatiPesniPoTip((tip)kojtip);

    }

    return 0;
}