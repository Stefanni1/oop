#include<iostream>
#include<cstring>
#define MAX 25
using namespace std;
class List{
private:
    int * niza;
    int len;
public:
    List(int *niza,int len) {
        this->len=len;
        this->niza=new int[len];
        for (int i = 0; i < len; ++i) {
            this->niza[i]=niza[i];
        }
    }
    List(const List &l){
        this->niza= new int[l.len];
        for (int i = 0; i < l.len; ++i) {
            this->niza[i]=l.niza[i];
        }
        this->len=l.len;
    }
    List &operator=(const List &l) {
        if(this==&l) {
            return *this;
        }
            delete[]this->niza;
            this->niza = new int[l.len];
            for (int i = 0; i < l.len; ++i) {
                this->niza[i] = l.niza[i];
            }
            this->len = l.len;
            return *this;
        }

    int getLen() {
        return len;
    }
    void pecati(){
        cout<<len<<": ";
        for (int i = 0; i < len; ++i) {
            cout<<niza[i]<<" ";
        }
        cout<<"sum: "<<sum()<<"average: "<<average()<<endl;
    }
    int sum(){
        int s=0;
        for (int i = 0; i < len; ++i) {
            s+=niza[i];
        }
        return s;
    }
    double average(){
        return (double)sum()/len;
    }
    ~List(){
        delete[]niza;
    }



};
class ListContainer{
private:
    List* list;
    int len;
    int capacity;
    int obid=0;
public:
    ListContainer(){
        capacity=MAX;
        this->list=new List[capacity];
        this->len=this->obid=0;
    }
    ListContainer(const ListContainer &lc){
        this->list = new List[MAX];
        for(int i = 0; i < lc.len; i++)
            this->list[i] = lc.list[i];
        this->len = lc.len;
        this->obid = lc.obid;
    }
    ListContainer &operator=(const ListContainer &lc){
        if(this==&lc){
            return *this;
        }
        delete[]list;
        this->list = new List[MAX];
        for(int i = 0; i < lc.len; i++)
            this->list[i] = lc.list[i];
        this->len = lc.len;
        this->obid = lc.obid;
        return *this;
    }
    void print(){
        if(len<=0){
            cout<<"The list is empty"<<endl;
            return;
        }
        for (int i = 0; i < len; ++i) {
            cout<<"List number: "<<(i+1)<<"List info: ";
            list[i].pecati();
        }
        cout<<"sum: "<<sum()<<"average: "<<average()<<endl;
        cout<<"Successful attemts: "<<len<<"Failed attempts: "<<(obid-len)<<endl;

    }
    void addNewList(List l){
        obid++;
        for (int i = 0; i < len; ++i) {
            if(list[i].sum()==l.sum()){
                return;
            }
        }
        list[len++]=l;
    }
    int sum(){
        int s=0;
        for (int i = 0; i < len; ++i) {
            s+=list[i].sum();
        }
        return s;
    }
    double average(){
        int av=0;
        for (int i = 0; i < len; ++i) {
            av+=list[i].getLen();
        }
        return (double)sum()/av;
    }
    ~ListContainer(){
        delete[]list;
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