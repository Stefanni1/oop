#include<iostream>
#include<cstring>
using namespace std;
class Athlete{
protected:
    char name[20];
    int age;
public:
    Athlete(const char *name="", int age=0){
        strcpy(this->name,name);
        this->age=age;
    }
    virtual void displayInfo()const{
        cout<<"Athlete: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
    }
    virtual double getValue() const =0;
    virtual ~Athlete(){}
};
class Runner : virtual public Athlete{
protected:
    double speed;
public:
    Runner(const char *name="", int age=0,double speed=0.0) : Athlete (name,age), speed(speed){}
    void displayInfo()const override{
        cout<<"Athlete: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Speed: "<<speed<<" mph "<<endl;
    }
    double getValue() const override{
        return speed;
    }
};
class Jumper : virtual public Athlete{
protected:
    double height;
public:
    Jumper(const char *name="", int age=0,double height=0.0) : Athlete(name,age), height(height){}
    void displayInfo()const override{
        cout<<"Athlete: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Height: "<<height<<"m"<<endl;
    }
    double getValue() const override{
        return height;
    }
};
class AllRoundAthlete : public Runner, public Jumper {
private:
    int stamina;
public:
    AllRoundAthlete(const char *name = "", int age = 0, double speed = 0.0, double height = 0.0, int stamina = 0)
            : Athlete(name, age), Runner(name, age, speed), Jumper(name, age, height), stamina(stamina) {}

    void displayInfo() const override {
        cout << "AllRoundAthlete: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Speed: " << speed <<" mph"<<endl;
        cout << "Height: " << height <<"m"<<endl;
        cout << "Stamina: " << stamina << endl;
    }

    double getValue() const override {
        return (speed + height) / 2;
    }
};
    Athlete* findAthleteWithMaxValue(Athlete** athletes, int n) {
        if (n == 0) return nullptr;

        Athlete* maxAthlete = athletes[0];
        for (int i = 1; i < n; i++) {
            if (athletes[i]->getValue() > maxAthlete->getValue()) {
                maxAthlete = athletes[i];
            }
        }
        return maxAthlete;
    }



int main() {
    char name[50];
    int age;
    double speed;
    double height;
    int n;
    int choice;

    cin>>choice;
    if(choice==1)
    {
        cin>>name;
        cin>>age;
        AllRoundAthlete allRoundAthlete(name, age, 13.6, 1.80, 6);
        allRoundAthlete.displayInfo();
    }
    else {

        cin >> n;

        Athlete **athletes = new Athlete *[n];
        for (int i = 0; i < n; i++) {
            cin >> choice;
            if (choice == 1) {
                cin >> name >> age >> speed;

                athletes[i] = new Runner(name, age, speed);
            } else {
                cin >> name >> age >> height;

                athletes[i] = new Jumper(name, age, height);
            }

        }

        findAthleteWithMaxValue(athletes, n)->displayInfo();

    }


    return 0;
}