#include<iostream>
#include<cstring>
using namespace std;
class Fraction{
private:
    int numerator;
    int denominator;
public:
    Fraction(int numerator=1, int denominator=0) : numerator(numerator), denominator(denominator) {}
    Fraction operator + (Fraction &other){
        return Fraction(this->numerator * other.denominator + other.numerator * this->denominator,
                        this->denominator * other.denominator);
    }
    Fraction operator-(Fraction &other){
            return Fraction(this->numerator * other.denominator - other.numerator * this->denominator,
                            this->denominator * other.denominator);
    }
    Fraction operator*(Fraction &other){
        return Fraction(this->numerator * other.numerator,
                        this->denominator * other.denominator);
    }
    friend ostream & operator << (ostream &out, const Fraction &f){
        out<<f.numerator<<"/"<<f.denominator<<endl;
        return out;
    }
    friend istream & operator >> (istream &in, Fraction &f){
        in>>f.numerator>>f.denominator;
    }

};
int main(){
    Fraction f1,f2,f3;
    cin>>f1>>f2>>f3;
    cout<<f1<<f2<<f3;
    return 0;
}
