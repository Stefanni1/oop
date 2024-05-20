#include<iostream>
#include<cstring>
using namespace std;


class Trud {
private:
    char *tip;
    int god;
public:
    Trud(char * tip="", int god=0)  {
        strcpy(this->tip, tip);
        this->god=god;
    }

    Trud(const Trud &t){
        strcpy(this->tip,t.tip);
        this->god=t.god;
    }
    Trud &operator=(const Trud &t){
        if(this!=&t){
            strcpy(this->tip,t.tip);
            this->god=t.god;
        }
        return *this;
    }
    friend ostream &operator<<(ostream &out, const Trud &t){
        out<<t.tip<<" "<<t.god;
        return out;
    }

    char *getTip() const {
        return tip;
    }

    void setTip(char *tip) {
        Trud::tip = tip;
    }

    int getGod() const {
        return god;
    }

    void setGod(int god) {
        Trud::god = god;
    }
};
class Student{
protected:
    char ime[30];
    int indeks;
    int god;
    int * grades;
    int predmeti;
public:
    Student(char *ime="", int indeks=0, int god=0, int *grades= nullptr, int predmeti=0) :  indeks(indeks), god(god),
                                                                         predmeti(predmeti){
        strcpy(this->ime,ime);
        this->grades=new int[predmeti];
        for (int i = 0; i < predmeti; ++i) {
            this->grades[i]=grades[i];
        }
    }
    ~Student(){
        delete[]grades;
    }
    Student(const Student &s){
        strcpy(this->ime,s.ime);
        this->indeks=s.indeks;
        this->god=s.god;
        this->grades=new int[s.predmeti];
        for (int i = 0; i < s.predmeti; ++i) {
            this->grades[i]=s.grades[i];
        }
        this->predmeti=s.predmeti;
    }

    virtual double rang()const {
        double prosek = 0;
        for (int i = 0; i < predmeti; ++i) {
            prosek += grades[i];
        }
        return prosek / predmeti;
    }
    friend ostream &operator<<(ostream &out,Student &s){
        out<<s.indeks<<" "<<s.ime<<" "<<s.god<<" "<<s.rang()<<endl;
        return out;
    }

    const char *getIme() const {
        return ime;
    }

    int getIndeks() const {
        return indeks;
    }

    void setIndeks(int indeks) {
        Student::indeks = indeks;
    }

    int getGod() const {
        return god;
    }

    void setGod(int god) {
        Student::god = god;
    }

    int *getGrades() const {
        return grades;
    }

    void setGrades(int *grades) {
        Student::grades = grades;
    }

    int getPredmeti() const {
        return predmeti;
    }

    void setPredmeti(int predmeti) {
        Student::predmeti = predmeti;
    }


};
class Exception{
public:
    static void sendMessage(){
    cout<<"Ne moze da se vnese dadeniot trud"<<endl;
}
};
class PhDStudent : public Student{
    Trud * trudovi;
    int brojTrudovi;
public:
    PhDStudent(char *ime="", int indeks=0, int god=0, int *grades= nullptr, int predmeti=0, Trud * trudovi= nullptr, int brojTrudovi=0)
     : Student(ime,indeks,god,grades,predmeti), brojTrudovi(brojTrudovi){
        this->trudovi=new Trud[predmeti];
        for (int i = 0; i < predmeti; ++i) {
            trudovi[i]=trudovi[i];
        }
    }
    PhDStudent(const PhDStudent &p){
        this->trudovi=new Trud[p.predmeti];
        for (int i = 0; i < p.predmeti; ++i) {
            trudovi[i]=p.trudovi[i];
        }
        this->predmeti=p.predmeti;
    }
    PhDStudent &operator=(const PhDStudent &p){
        if(this!=&p){
            delete[]trudovi;
            this->trudovi=new Trud[p.predmeti];
            for (int i = 0; i < p.predmeti; ++i) {
                trudovi[i]=p.trudovi[i];
            }
            this->predmeti=p.predmeti;
        }
        return *this;
    }

    Trud *getTrudovi() const {
        return trudovi;
    }

    void setTrudovi(Trud *trudovi) {
        PhDStudent::trudovi = trudovi;
    }

    int getBrojTrudovi() const {
        return brojTrudovi;
    }

    void setBrojTrudovi(int brojTrudovi) {
        PhDStudent::brojTrudovi = brojTrudovi;
    }


    PhDStudent &operator+=(const Trud &t) {
        for (int i = 0; i < predmeti; ++i) {
            try {
                trudovi[i].getGod() < god ? throw Exception() : this->trudovi[i] = trudovi[i];
            } catch (Exception &e) {
                e.sendMessage();
            }
        }
        return *this;
    }
    ~PhDStudent(){
        delete[]trudovi;
    }
    double rang()const override{
        double prosek = rang();
        int bodovi=0;
        for (int i = 0; i < brojTrudovi; ++i) {
            if(trudovi[i].getGod()>=god){
                if(trudovi[i].getTip()[0]=='c')bodovi+=1;
                else if(trudovi[i].getTip()[0]=='j')bodovi+=3;
            }
        }
        return prosek + bodovi;
    }
    friend ostream& operator<<(ostream& out, const PhDStudent& phd) {
        // Print student information (from the base class)
        out << "Student: " << phd.ime << " " << phd.indeks << " " << phd.god << " " << phd.rang() << endl;

        // Print the publications (truds)
        out << "Publications: ";
        for (int i = 0; i < phd.brojTrudovi; ++i) {
            out << "(" << phd.trudovi[i].getTip() << ", " << phd.trudovi[i].getGod() << ") ";
        }
        out << endl;

        return out;
    }

};
    int main(){
        int testCase;
        cin >> testCase;

        int god, indeks, n, god_tr, m, n_tr;
        int izbor; //0 za Student, 1 za PhDStudent
        char ime[30];
        int oceni[50];
        char tip;
        Trud trud[50];

        if (testCase == 1){
            cout << "===== Testiranje na klasite ======" << endl;
            cin >> ime;
            cin >> indeks;
            cin >> god;
            cin >> n;
            for (int j = 0; j < n; j++)
                cin >> oceni[j];
            Student s(ime, indeks, god, oceni, n);
            cout << s;

            cin >> ime;
            cin >> indeks;
            cin >> god;
            cin >> n;
            for (int j = 0; j < n; j++)
                cin >> oceni[j];
            cin >> n_tr;
            for (int j = 0; j < n_tr; j++){
                cin >> tip;
                cin >> god_tr;
                Trud t(tip, god_tr);
                trud[j] = t;
            }
            PhDStudent phd(ime, indeks, god, oceni, n, trud, n_tr);
            cout << phd;
        }
        if (testCase == 2){
            cout << "===== Testiranje na operatorot += ======" << endl;
            Student **niza;
            cin >> m;
            niza = new Student *[m];
            for (int i = 0; i<m; i++){
                cin >> izbor;
                cin >> ime;
                cin >> indeks;
                cin >> god;
                cin >> n;
                for (int j = 0; j < n; j++)
                    cin >> oceni[j];

                if (izbor == 0){
                    niza[i] = new Student(ime, indeks, god, oceni, n);
                }
                else{
                    cin >> n_tr;
                    for (int j = 0; j < n_tr; j++){
                        cin >> tip;
                        cin >> god_tr;
                        Trud t(tip, god_tr);
                        trud[j] = t;
                    }
                    niza[i] = new PhDStudent(ime, indeks, god, oceni, n, trud, n_tr);
                }
            }
            // pecatenje na site studenti
            cout << "\nLista na site studenti:\n";
            for (int i = 0; i < m; i++)
                cout << *niza[i];

            // dodavanje nov trud za PhD student spored indeks
            Trud t;
            cin >> indeks;
            cin >> t;

            // vmetnete go kodot za dodavanje nov trud so pomos na operatorot +=

            // pecatenje na site studenti
            cout << "\nLista na site studenti:\n";
            for (int i = 0; i < m; i++)
                cout << *niza[i];
        }
        if (testCase == 3){
            cout << "===== Testiranje na operatorot += ======" << endl;
            Student **niza;
            cin >> m;
            niza = new Student *[m];
            for (int i = 0; i<m; i++){
                cin >> izbor;
                cin >> ime;
                cin >> indeks;
                cin >> god;
                cin >> n;
                for (int j = 0; j < n; j++)
                    cin >> oceni[j];

                if (izbor == 0){
                    niza[i] = new Student(ime, indeks, god, oceni, n);
                }
                else{
                    cin >> n_tr;
                    for (int j = 0; j < n_tr; j++){
                        cin >> tip;
                        cin >> god_tr;
                        Trud t(tip, god_tr);
                        trud[j] = t;
                    }
                    niza[i] = new PhDStudent(ime, indeks, god, oceni, n, trud, n_tr);
                }
            }
            // pecatenje na site studenti
            cout << "\nLista na site studenti:\n";
            for (int i = 0; i < m; i++)
                cout << *niza[i];

            // dodavanje nov trud za PhD student spored indeks
            Trud t;
            cin >> indeks;
            cin >> t;

            // vmetnete go kodot za dodavanje nov trud so pomos na operatorot += od Testcase 2


            // pecatenje na site studenti
            cout << "\nLista na site studenti:\n";
            for (int i = 0; i < m; i++)
                cout << *niza[i];
        }
        if (testCase == 4){
            cout << "===== Testiranje na isklucoci ======" << endl;
            cin >> ime;
            cin >> indeks;
            cin >> god;
            cin >> n;
            for (int j = 0; j < n; j++)
                cin >> oceni[j];
            cin >> n_tr;
            for (int j = 0; j < n_tr; j++){
                cin >> tip;
                cin >> god_tr;
                Trud t(tip, god_tr);
                trud[j] = t;
            }
            PhDStudent phd(ime, indeks, god, oceni, n, trud, n_tr);
            cout << phd;
        }
        if (testCase == 5){
            cout << "===== Testiranje na isklucoci ======" << endl;
            Student **niza;
            cin >> m;
            niza = new Student *[m];
            for (int i = 0; i<m; i++){
                cin >> izbor;
                cin >> ime;
                cin >> indeks;
                cin >> god;
                cin >> n;
                for (int j = 0; j < n; j++)
                    cin >> oceni[j];

                if (izbor == 0){
                    niza[i] = new Student(ime, indeks, god, oceni, n);
                }
                else{
                    cin >> n_tr;
                    for (int j = 0; j < n_tr; j++){
                        cin >> tip;
                        cin >> god_tr;
                        Trud t(tip, god_tr);
                        trud[j] = t;
                    }
                    niza[i] = new PhDStudent(ime, indeks, god, oceni, n, trud, n_tr);
                }
            }
            // pecatenje na site studenti
            cout << "\nLista na site studenti:\n";
            for (int i = 0; i < m; i++)
                cout << *niza[i];

            // dodavanje nov trud za PhD student spored indeks
            Trud t;
            cin >> indeks;
            cin >> t;

            // vmetnete go kodot za dodavanje nov trud so pomos na operatorot += i spravete se so isklucokot

            // pecatenje na site studenti
            cout << "\nLista na site studenti:\n";
            for (int i = 0; i < m; i++)
                cout << *niza[i];
        }
        if (testCase == 6){
            cout << "===== Testiranje na static clenovi ======" << endl;
            Student **niza;
            cin >> m;
            niza = new Student *[m];
            for (int i = 0; i<m; i++){
                cin >> izbor;
                cin >> ime;
                cin >> indeks;
                cin >> god;
                cin >> n;
                for (int j = 0; j < n; j++)
                    cin >> oceni[j];

                if (izbor == 0){
                    niza[i] = new Student(ime, indeks, god, oceni, n);
                }
                else{
                    cin >> n_tr;
                    for (int j = 0; j < n_tr; j++){
                        cin >> tip;
                        cin >> god_tr;
                        Trud t(tip, god_tr);
                        trud[j] = t;
                    }
                    niza[i] = new PhDStudent(ime, indeks, god, oceni, n, trud, n_tr);
                }
            }
            // pecatenje na site studenti
            cout << "\nLista na site studenti:\n";
            for (int i = 0; i < m; i++)
                cout << *niza[i];

            int conf, journal;
            cin >> conf;
            cin >> journal;

            //postavete gi soodvetnite vrednosti za statickite promenlivi

            // pecatenje na site studenti
            cout << "\nLista na site studenti:\n";
            for (int i = 0; i < m; i++)
                cout << *niza[i];
        }

        return 0;
    }