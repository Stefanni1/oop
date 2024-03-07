//
// Created by Stefanija on 07.3.2024.
//
#include<iostream>
#include<cmath>
using namespace std;
class Triangle{
private:
    int a,b,c;
public:
    Triangle(int a=0, int b=0, int c=0){
        this->a=a;
        this->b=b;
        this->c=c;
    }
    Triangle(const Triangle &t){
        this->a=t.a;
        this->b=t.b;
        this->c=t.c;
    }
    double area(){
        float s = (a + b + c) / 2;
        return sqrt(s*(s-a)*(s-b)*(s-c));
    }
    double perimeter(){
        return a+b+c;
    }

    ~Triangle(){}

};



int main() {
    int a, b, c;
    cin >> a >> b >> c;
    Triangle t(a, b, c);
    cout << "Area: " << t.area() << endl;
    cout << "Permeter: " << t.perimeter() << endl;
    return 0;
}