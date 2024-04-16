#include<iostream>
#include<cstring>
using namespace std;
class List{
private:
    int * broevi;
    int brBroevi;
public:
    List(int * broevi=0, int brBroevi=0) {
        this->broevi=new int[brBroevi];
        this->brBroevi=brBroevi;
    }
    List(const List &l){
        this->broevi=new int[l.brBroevi];
        this->brBroevi=l.brBroevi;
    }
    List &operator=(const List &l){
        if(this!=&l){
            delete[]broevi;
            this->broevi=new int[l.brBroevi];
            this->brBroevi=l.brBroevi;
        }
        return *this;
    }

    int *getBroevi() const {
        return broevi;
    }

    void setBroevi(int *broevi) {
        List::broevi = broevi;
    }

    int getBrBroevi() const {
        return brBroevi;
    }

    void setBrBroevi(int brBroevi) {
        List::brBroevi = brBroevi;
    }

    void pecati(){
        cout<<brBroevi<<": "<<sum()<<": "<<average()<<": "<<endl;
    }
    int sum(){
        int suma=0;
        for (int i = 0; i < brBroevi; ++i) {
            suma+=broevi[i];
        }
        return suma;
    }
    double average(){
        int total=sum();
        if(brBroevi !=0){
            return(double)total/brBroevi;
        }
        else{
            return 0;
        }
    }
};
class ListContainer{
private:
    List * list;
    int brElementi;
    int brObidi=0;
public:
    ListContainer(List * list=NULL, int brElementi=0,int brObidi=0){
        this->list=new List[brElementi];
        this->brElementi=brElementi;
        this->brObidi=brObidi;
    }
    ListContainer(const ListContainer &lc){
        this->list=new List[lc.brElementi];
        this->brElementi=lc.brElementi;
        this->brObidi=lc.brObidi;
        for (int i = 0; i < brElementi; ++i) {
            list[i]=lc.list[i];
        }
    }
    ListContainer &operator=(const ListContainer &lc){
        if(this!=&lc){
            delete[]list;
            this->list=new List[lc.brElementi];
            this->brElementi=lc.brElementi;
            this->brObidi=lc.brObidi;
            for (int i = 0; i < brElementi; ++i) {
                list[i]=lc.list[i];
            }
        }
        return *this;
    }
    void print(){
        if(brElementi==0){
            cout<<"The list is empty."<<endl;
            return;
        }
        for (int i = 0; i < brElementi; ++i) {
            cout<<"List number: "<<i+1<<"List info: ";
            list[i].pecati();
        }
        cout<<"Sum: "<<sum()<<" Average: "<<average()<<endl;
    }
    void addNewList(List &l){
        List * temp = new List[brElementi+1];
        for (int i = 0; i < brElementi; ++i) {
            temp[i]=list[i];
        }
        temp[brElementi]=l;
        delete[]list;
        list=temp;
        brElementi++;
    }
    int sum(){
        int suma=0;
        for (int i = 0; i < brElementi; ++i) {
            suma+=list[i].sum();
        }
        return suma;
    }

    double average(){
        int total=sum();
        if(brElementi !=0){
            return(double)total/brElementi;
        }
        else{
            return 0;
        }
    }

};



int main() {

    ListContainer lc;
    int N;
    cin>>N;

    for (int i=0;i<N;i++) {
        int n;
        int niza[100];

        cin>>n;

        for (int j=0;j<n;j++){
            cin>>niza[j];

        }

        List l=List(niza,n);

        lc.addNewList(l);
    }


    int testCase;
    cin>>testCase;

    if (testCase==1) {
        cout<<"Test case for operator ="<<endl;
        ListContainer lc1;
        lc1.print();
        cout<<lc1.sum()<<" "<<lc.sum()<<endl;
        lc1=lc;
        lc1.print();
        cout<<lc1.sum()<<" "<<lc.sum()<<endl;
        lc1.sum();
        lc1.average();

    }
    else {
        lc.print();
    }
}