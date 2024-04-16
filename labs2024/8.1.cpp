#include<iostream>
#include<cstring>
using namespace std;
class Hero{
protected:
    char name[40];
    float attackDamage;
    float attackSpeed;
    float abilityPower;
public:
    Hero(char * name="", float attackDamage=0.0, float attackSpeed=0.0,float abilityPower=0.0){
        strcpy(this->name,name);
        this->attackDamage=attackDamage;
        this->attackSpeed=attackSpeed;
        this->abilityPower=abilityPower;
    }
    virtual void displayInfo() const=0;
    virtual float power() const=0;
    ~Hero(){}
};
class LegendaryHero : virtual public Hero {
private:
    int hiddenPowers;
public:
    LegendaryHero(char * name="", float attackDamage=0.0, float attackSpeed=0.0,float abilityPower=0.0,int hiddenPowers=0) : Hero(name, attackDamage, abilityPower, attackSpeed), hiddenPowers(hiddenPowers){
        this->hiddenPowers=hiddenPowers;
    }
    float power()const override{
       return (0.4*attackDamage*hiddenPowers)+(0.25*attackSpeed*hiddenPowers)+(0.35*abilityPower*hiddenPowers);
    }
    void displayInfo() const override{
        cout<<"LegendaryHero: "<<name<<endl;
        cout<<"Number of hidden powers: "<<hiddenPowers<<endl;
        cout<<"Attack damage: "<<attackDamage<<endl;
        cout<<"Attack speed: "<<attackSpeed<<endl;
        cout<<"Ability power: "<<abilityPower<<endl;
        cout<<"Power: "<<power()<<endl;
    }
    ~LegendaryHero(){}
};
class SuperHero : virtual public Hero{
private:
    bool isShapeshifter;
public:
    SuperHero(char * name="", float attackDamage=0.0, float attackSpeed=0.0,float abilityPower=0.0,bool isShapeshifter=true) : Hero(name,attackDamage,attackSpeed,abilityPower), isShapeshifter(isShapeshifter){
        this->isShapeshifter=isShapeshifter;
    }
    float power()const override{
      float basePower = attackDamage+attackSpeed+abilityPower;
      return isShapeshifter ? basePower * 2 : basePower;
    }
    void displayInfo()const override{
        cout<<"LegendaryHero: "<<name<<endl;
        cout<<"Attack damage: "<<attackDamage<<endl;
        cout<<"Attack speed: "<<attackSpeed<<endl;
        cout<<"Ability power: "<<abilityPower<<endl;
        cout<<"Power: "<<power()<<endl;
    }
};
class LegendarySuperHero : public LegendaryHero, public SuperHero{
public:
    LegendarySuperHero(const char* name = "", float attackDamage = 0, float attackSpeed = 0, float abilityPower = 0, int hiddenPowers = 0, bool isShapeshifter = false)
            : Hero(name, attackDamage, attackSpeed, abilityPower),
              LegendaryHero(name, attackDamage, attackSpeed, abilityPower, hiddenPowers),
              SuperHero(name, attackDamage, attackSpeed, abilityPower, isShapeshifter) {}
};


int main() {
    char name[50];
    double attackDamage;
    double attackSpeed;
    double abilityPower;
    int hiddenPowers;
    bool isShapeshifter;
    int n;
    int choice;

    cin>>choice;
    if(choice==1)
    {
        cin>>name;
        LegendarySuperHero legendarySuperHero(name, 55, 43, 70, 2, true);
        legendarySuperHero.displayInfo();
    }
    else {

        cin >> n;

        Hero **h = new Hero *[n];
        for (int i = 0; i < n; i++) {
            cin >> choice;
            if (choice == 1) {
                cin >> name >> attackDamage >> attackSpeed >> abilityPower >> hiddenPowers;

                h[i] = new LegendaryHero(name, attackDamage, attackSpeed, abilityPower, hiddenPowers);
            } else {
                cin >> name >> attackDamage >> attackSpeed >> abilityPower >> isShapeshifter;

                h[i] = new SuperHero(name, attackDamage, attackSpeed, abilityPower, isShapeshifter);
            }

        }

        mostPowerfulLegendaryHero(h,n)->displayInfo();

    }


    return 0;
}