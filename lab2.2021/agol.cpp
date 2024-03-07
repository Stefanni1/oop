#include<iostream>
#include<cstring>
using namespace std;

class Agol{
private:
    int stepeni;
    int minuti;
    int sekundi;
public:
    Agol(int stepeni=0,int minuti=0,int sekundi=0){
        this->stepeni=stepeni;
        this->minuti=minuti;
        this->sekundi=sekundi;
    }
    Agol(const Agol &a){
        this->stepeni=a.stepeni;
        this->minuti=a.minuti;
        this->sekundi=a.sekundi;
    }
    ~Agol(){}


    void set_stepeni(int stepeni) {
        Agol::stepeni = stepeni;
    }

    void set_minuti(int minuti) {
        Agol::minuti = minuti;
    }

    void set_sekundi(int sekundi) {
        Agol::sekundi = sekundi;
    }

    int getStepeni() const {
        return stepeni;
    }

    int getMinuti() const {
        return minuti;
    }

    int getSekundi() const {
        return sekundi;
    }

    int to_sekundi(){
        int total=0;
        total=stepeni*3600+minuti*60+sekundi;
        return total;
    }
};
int proveri(int stepeni,int minuti,int sekundi) {
    if (stepeni > 360 || minuti >= 60 || minuti < 0 || sekundi >= 60 || sekundi < 0) {
        cout << "Nevalidni vrednosti za agol" << endl;
        return 0;
    } else {
        return 1;
    }
}
    bool changeOfSeconds(Agol a, int sekundi) {
        return a.getSekundi() != sekundi;
    }


int main() {
    Agol a1;

    //da se instancira objekt od klasata Agol
    int deg, min, sec;
    cin >> deg >> min >> sec;

    if (proveri(deg, min, sec)) {

        a1.set_stepeni(deg);
        a1.set_minuti(min);
        a1.set_sekundi(sec);
        cout << a1.to_sekundi();
        if (changeOfSeconds(a1,sec))
            cout << "Ne smeete da gi menuvate sekundite vo ramkite na klasata!" << endl;

    }

    return 0;
}
