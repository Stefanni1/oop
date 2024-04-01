#include<iostream>
#include<cstring>
using namespace std;
class Array{
private:
    int *content;
    int size;
    int capacity;
public:
    Array(int capacity=10){
        this->capacity=capacity;
        size=0;
        content = new int[capacity];
    }
    friend ostream & operator << (ostream &out, const Array &a){
        out<<"Capacity: "<<a.capacity<<endl;
        out<<"Size: "<<a.size<<endl;
        for (int i = 0; i < a.size; ++i) {
            out<<a.content[i]<<" ";
        }
        return out;

    }
    operator += (int number)


};
int main(){
    Array a;
    cout<<a;
    return 0;
}