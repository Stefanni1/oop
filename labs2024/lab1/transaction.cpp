#include<iostream>
using namespace std;
struct Transaction{
    int id_broj;
    int sum;
    int prov;
    int WithCredit;
};
typedef struct Transaction Transaction;

int main() {
    int n;
    cin>>n;
    int flagForCredit=1;
    Transaction transaction[100];
    for(int i=0; i<n; i++){

        cin >> transaction[i].id_broj >> transaction[i].sum >> transaction[i].prov >> transaction[i].WithCredit;

        if (transaction[i].WithCredit == 1)
        {
            flagForCredit = 0;

            cout << transaction[i].id_broj <<" "<< transaction[i].sum + transaction[i].prov<<endl;
        }
    }
    if(flagForCredit)
        cout<<"No credit card transaction";
    return 0;
}