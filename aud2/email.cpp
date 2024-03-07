#include<iostream>
#include<cstring>
using namespace std;
class Email{
private:
    char sender[30];
    char receiver[30];
    char subject[50];
    char body[1000];
public:

    Email(char* sender="Stefanija", char* receiver="Boris",char* subject="Love",char* body="Love u"){
        strcpy(this->sender,sender);
        strcpy(this->receiver,receiver);
        strcpy(this->subject,subject);
        strcpy(this->body,body);
    }
    Email(const Email &e){
        strcpy(this->sender,e.sender);
        strcpy(this->receiver,e.receiver);
        strcpy(this->subject,e.subject);
        strcpy(this->body,e.body);
    }
    void print(){
        cout << "From          :\t " << sender << endl;
        cout << "To            :\t " << receiver << endl;
        cout << "----------------------------"<<endl;
        cout << "Subject       :\t " << subject << endl;
        cout <<"-----------------------------"<<endl;
        cout << "Body: " << body << endl;
        cout<<"ENDS";
    }

};
bool checkEmail(char *address);

int main() {
    char to[100], from[100], subject[200], body[1000];
    cout << "To: " << endl;
    cin >> to;
    if (checkEmail(to)) {
        cout << "From: " << endl;
        cin >> from;
        cout << "Subject: " << endl;
        cin >> subject;
        cout << "Body: " << endl;
        cin >> body;
        Email poraka(from, to, subject, body);
        cout << "Sent:" << endl;
        poraka.print();
    } else {
        cout << "Invalid email address!" << endl;
    }
    return 0;
}

bool checkEmail(char *address) {
    int count = 0;
    while (*address != 0)
        if ('@' == *address++)
            count++;
    return (1 == count);
}