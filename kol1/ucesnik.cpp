#include<iostream>
#include<cstring>

using namespace std;

class Ucesnik {
private:
    char *name;
    bool gender;
    int age;
public:
    Ucesnik(char *name = "", bool gender = 0, int age = 0) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->gender = gender;
        this->age = age;
    }

    Ucesnik(const Ucesnik &u) {
        this->name = new char[strlen(u.name) + 1];
        strcpy(this->name, u.name);
        this->gender = u.gender;
        this->age = u.age;
    }

    int getAge() const {
        return age;
    }

    ~Ucesnik() {
        delete[]name;
    }

    bool operator>(const Ucesnik &u) {
        return age > u.age;
    }

    friend ostream &operator<<(ostream &os, const Ucesnik &ucesnik) {
        os << "name: " << ucesnik.name << endl;
        os << " gender: " << (ucesnik.gender ? "mashki" : "zhenski") << endl;
        os << " age: " << ucesnik.age << endl;
        return os;
    }
};

class Maraton {
private:
    char location[100];
    Ucesnik *u;
    int num;
public:
    Maraton(char *location = "", Ucesnik *u = nullptr, int num = 0) : num(num){
        strcpy(this->location, location);
        this->u = new Ucesnik[num];
    }

    Maraton(const Maraton &m) : num(num){
        strcpy(this->location, m.location);
        this->num=m.num;
        this->u = new Ucesnik[m.num];
        for (int i = 0; i < m.num; ++i) {
            this->u[i] = m.u[i];
        }
    }

    const char *getLocation() const {
        return location;
    }

    int getNum() const {
        return num;
    }

    ~Maraton() {
        delete[]u;
        u= nullptr;
    }

    Maraton &operator+=(const Ucesnik &newUcesnik) {

        Ucesnik *tmp = new Ucesnik[num + 1];
        for (int i = 0; i < num; ++i) {
            tmp[i] = u[i];
        }
        delete[]u;
        tmp[num] = newUcesnik;
        u = tmp;
        num++;
        return *this;
    }
    double pecatiPomladi(const Ucesnik &lastUcesnik) {
        if (num == 0) {
            return 0;
        }
        for (int i = 0; i < num; ++i) {
            if (u[i].getAge() < lastUcesnik.getAge()) {
                cout << u[i];
            }
        }

}
    double prosecnoVozrast(){
            if (num == 0) {
                return 0;
            }
            double totalAge = 0.0;
            for (int i = 0; i < num; ++i) {
                totalAge += u[i].getAge();
            }
            return totalAge / num;


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
    Ucesnik **u = new Ucesnik *[n];
    for (int i = 0; i < n; ++i) {
        cin >> ime >> maski >> vozrast;
        u[i] = new Ucesnik(ime, maski, vozrast);
        m += *u[i];
    }
    m.pecatiPomladi(*u[n - 1]);
    cout << m.prosecnoVozrast() << endl;
    for (int i = 0; i < n; ++i) {
        delete u[i];
    }
    delete[] u;
    return 0;
}