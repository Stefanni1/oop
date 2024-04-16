#include<iostream>
#include<cstring>
using namespace std;
class HotelReservation{
protected:
    int days;
    int guests;
    char  name[50];
public:
    HotelReservation(char * name="",int days=0,int guests=0){
        this->days=days;
        this->guests=guests;
        strcpy(this->name,name);
    }
    HotelReservation(const HotelReservation &hr){
        this->days=hr.days;
        this->guests=hr.guests;
        strcpy(this->name,hr.name);
    }
    ~HotelReservation(){}

    int getDays() const {
        return days;
    }
    double price(){
        return guests * days * 25;
    }
    double price(double deposit){
        return deposit - price();

    }
};
class HalfBoardHotelReservation : HotelReservation {
public:
    HalfBoardHotelReservation(char *name, int days, int guests) : HotelReservation(name, days, guests) {}
    double returnPrice(double deposit){
        return deposit * returnPrice() * 0.5;
    }
};


int main() {
    Hotel hotel("FINKI hotel", 0);

    int n; //broj na rezervacii
    cin >> n;

    HotelReservation **reservations = new HotelReservation *[n];

    for (int i = 0; i < n; i++) {
        int type; //1 = obicna, 2 = polupansion
        char name[30];
        int days, guests;
        double deposit;
        cin >> type >> name >> days >> guests >> deposit;
        if (type == 1) {
            reservations[i] = new HotelReservation(name, days, guests);
        } else {
            reservations[i] = new HalfBoardHotelReservation(name, days, guests);
        }
        cout << name << " Days: " << days << " Guests: " << guests << " Price: " << reservations[i]->price();
        cout << "Change from payment: " << hotel.depositReservation(reservations[i], deposit);
    }

    cout << "Hotel state after all the reservations were payed" << endl;
    cout << hotel;

    return 0;

}