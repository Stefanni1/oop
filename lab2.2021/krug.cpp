#include<iostream>
#include<cstring>
using namespace std;
class krug{
private:
    float radius;
    float pi;
public:
    krug(float radius=0.0,float p=3.14){
        this->radius=radius;
        this->pi=3.14;
    }
    float plostina(){
        return radius*radius*pi;
    };
    float perimetar(){
        return 2*radius*pi;
    }
    void ednakvi(){
        if(plostina()==perimetar()){
            cout<<"1";
        }
        else {
            cout<<"0";
        }
    }
};


int main() {
    float r;
    cin >> r;
    krug k(r);
    //instanciraj objekt od klasata Krug cij radius e vrednosta procitana od tastatura
    cout << k.perimetar() << endl;
    cout << k.plostina() << endl;
    k.ednakvi();
    //instanciraj objekt od klasata Krug cij radius ne e definiran
    return 0;
}