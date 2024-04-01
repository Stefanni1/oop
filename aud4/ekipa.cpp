#include<iostream>
#include<cstring>

using namespace std;

class Team {
private:
    char name[50];
    int year;
    char city[50];
public:
    Team(char *name = "", int year = 0, char *city = "") {
        strcpy(this->name, name);
        strcpy(this->city, city);
        this->year = year;
    }

    Team(const Team &t) {
        strcpy(this->name, t.name);
        strcpy(this->city, t.city);
        this->year = t.year;
    }

    void print() {
        cout << name << " - " << city << "(" << year << ")" << endl;
    }

    const char *getName() const {
        return name;
    }

    int getYear() const {
        return year;
    }

    const char *getCity() const {
        return city;
    }
    friend class Game;
};

class Game{
private:
    Team home;
    Team away;
    int homeGoals;
    int awayGoals;
public:
    Game(const Team &home, const Team &away, int homeGoals, int awayGoals) : home(home), away(away),
                                                                             homeGoals(homeGoals),
                                                                             awayGoals(awayGoals) {}
    void print(){
        cout<<"Home team: ";
        home.print();
        cout<<"Away team: ";
        away.print();
        cout<<"Result --> "<<homeGoals<<":"<<awayGoals;
    }
    friend void rematch(Game &firstGame, Game &secondGame);
};
void rematch(Game &firstGame, Game &secondGame) {
    if (strcmp(firstGame.home.getName(), secondGame.away.getName()) == 0
        && strcmp(firstGame.away.getName(), secondGame.home.getName()) == 0) {
        cout << "REMATCH" << endl;
        int team1Goals = firstGame.homeGoals + secondGame.awayGoals;
        int team2Goals = firstGame.awayGoals + secondGame.homeGoals;
        if (team1Goals > team2Goals) {
            cout << "WINNER" << endl;
            firstGame.home.print();
            cout << team1Goals << " total goals" << endl;
//secondGame.away.print();
        } else if (team1Goals < team2Goals) {
            cout << "WINNER" << endl;
            firstGame.away.print();
            cout << team2Goals << " total goals" << endl;
//            secondGame.home.print();
        } else {
            cout << "DRAW" << endl;
        }
    } else {
        cout << "NOT A REMATCH" << endl;
    }
}


int main() {
//    Team team;
//    Team team2("Barca");
//    Team team3("Barca", 1890);
    Team team4("Barca", 1890, "Barcelona");

    //eksplicitno
//    Team team5(team4);
//    Team team6 = team3;


//    team.print();
//    team2.print();
//    team3.print();
//    team4.print();
//    team5.print();
//    team6.print();

    Team rm("Real Madrid", 1902, "Madrid");

    Game game(team4, rm, 2, 4);

    Game game2(rm, team4, 3, 1);

//    game.print();

    rematch(game, game2);


    return 0;
}
