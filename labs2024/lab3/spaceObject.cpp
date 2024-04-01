#include<iostream>
#include<cstring>
using namespace std;
class SpaceObject{
private:
    char name[100];
    char type[100];
    int distanceFromEarth;
public:
    SpaceObject(char *name="", char *type="", int distanceFromEarth=0){
        strcpy(this->name,name);
        strcpy(this->type,type);
        this->distanceFromEarth=distanceFromEarth;
    }
    SpaceObject(const SpaceObject &so){
        strcpy(this->name,so.name);
        strcpy(this->type,so.type);
        this->distanceFromEarth=so.distanceFromEarth;
    }

    const char *getName() const {
        return name;
    }

    const char *getType() const {
        return type;
    }

    int getDistanceFromEarth() const {
        return distanceFromEarth;
    }

    void setDistanceFromEarth(int distanceFromEarth) {
        SpaceObject::distanceFromEarth = distanceFromEarth;
    }

    void print(){
        cout<<name<<" "<<type<<" "<<"-"<<distanceFromEarth<<": "<<"light years away from Earth"<<endl;
    }
};
class Alien{
private:
    char name[100];
    int age;
    char homePlanet[100];
    int numObj;
    SpaceObject so[100];
public:
    Alien(){}
    Alien(char *name, int age,char *homePlanet,int numObj, SpaceObject *objects){
        strcpy(this->name,name);
        strcpy(this->homePlanet,homePlanet);
        this->age=age;
        this->numObj=numObj;
        for(int i=0;i<numObj;i++)
        {
            this->so[i]=objects[i];
        }
    }
    Alien(const Alien &a){
        strcpy(this->name,a.name);
        strcpy(this->homePlanet,a.homePlanet);
        this->age=a.age;
        this->numObj=a.numObj;
        for(int i=0;i<a.numObj;i++)
        {
            this->so[i]=a.so[i];
        }
    }

    const char *getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    void setAge(int age) {
        Alien::age = age;
    }

    const char *getHomePlanet() const {
        return homePlanet;
    }

    int getNumObj() const {
        return numObj;
    }

    void setNumObj(int numObj) {
        Alien::numObj = numObj;
    }

    const SpaceObject *getSo() const {
        return so;
    }


    SpaceObject getObjectClosestToEarth(){
        int minDistance=999999999, idx=0;

        for(int i=0;i<numObj;i++)
        {
            if(so[i].getDistanceFromEarth()<minDistance)
            {
                minDistance=so[i].getDistanceFromEarth();
                idx=i;
            }
        }
        return so[idx];
    }
    ~Alien(){}
    void print(){
        cout<<"Alien name: "<<name<<endl;
        cout<<"Alien age: "<<age<<endl;
        cout<<"Alien home planet: "<<homePlanet<<endl;
        cout<<"Favourite space object closest to earth: ";
        getObjectClosestToEarth().print();
    }

};
int main()
{
    char name[100], homePlanet[100];
    int age, numObj;
    cin>>name>>age>>homePlanet>>numObj;
    //Testing default constructor for SpaceObject
    SpaceObject spaceObjects[numObj];
    for(int i=0; i<numObj; i++)
    {
        char spaceObjectName[100], spaceObjectType[100];
        int distanceFromEarth;
        cin>>spaceObjectName>>spaceObjectType>>distanceFromEarth;
        //Testing constructor with arguments for SpaceObject
        spaceObjects[i]=SpaceObject(spaceObjectName, spaceObjectType, distanceFromEarth);
    }
    //Testing default constructor for Alien
    Alien alien;
    //Testing constructor with arguments for Alien and copy constructor for Alien
    alien=Alien(name, age, homePlanet, numObj, spaceObjects);
    Alien alien2 = Alien(alien);

    alien2.print();
    return 0;
}
