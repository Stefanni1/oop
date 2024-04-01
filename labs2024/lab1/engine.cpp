#include<iostream>
#include<cstring>
using namespace std;
struct Engine{
    int horsepower;
    int torque;
};
struct Car{
    char name[50];
    int year;
    Engine engine;
};
void printCars(Car cars[], int n){
    int min1=cars[0].engine.horsepower;
    int min2=cars[0].engine.horsepower;
    int idx1=0, idx2=0;
    for (int i = 0; i < n; ++i) {
        if (cars[i].engine.horsepower < min1) {
            min1 = cars[i].engine.horsepower;
            idx1 = i;
        }
    }
    for (int i = 0; i < n; ++i) {
        if(cars[i].engine.horsepower < min2 && i!=idx1){
            min2=cars[i].engine.horsepower;
            idx2=i;
    }
        }
    if(cars[idx1].engine.torque > cars[idx2].engine.torque){
        cout << "Manufacturer: " << cars[idx1].name << endl;
        cout<<"Horsepower: "<<cars[idx1].engine.horsepower<<endl;
        cout<<"Torque: "<<cars[idx1].engine.torque<<endl;
    }
    else{
        cout << "Manufacturer: " << cars[idx2].name << endl;
        cout<<"Horsepower: "<<cars[idx2].engine.horsepower<<endl;
        cout<<"Torque: "<<cars[idx2].engine.torque<<endl;
    }
}
int main() {
    int n;
    cin >> n;
    Car cars[n];

    for (int i = 0; i < n; ++i) {
        cin >> cars[i].name;
        cin >> cars[i].year;
        cin >> cars[i].engine.horsepower;
        cin >> cars[i].engine.torque;
    }
    printCars(cars, n);

    return 0;
}
