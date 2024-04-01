#include<iostream>
#include <cstring>
using namespace std;
struct FootballPlayer{
    char name[50];
    int jerseyNumber;
    int scoredGoals;
};
struct FootballTeam{
    char name[50];
    FootballPlayer players[11];
};
void bestTeam(FootballTeam *teams,int n){
    int maxGoals=0;
    int bestTeam=0;

    for (int i = 0; i < n; ++i) {
        int goals=0;
        for (int j = 0; j < 11; ++j) {
            goals+=teams[i].players[j].scoredGoals;
        }
        if(goals > maxGoals){
            maxGoals = goals;
            bestTeam=i;
        }
    }
    cout<<"Najdobar tim e: "<<teams[bestTeam].name<<endl;
}
int main(){
    int n;
    cin>>n;
    FootballTeam teams[n];
    for (int i = 0; i < n; ++i) {
    cin>>teams[i].name;
        for (int j = 0; j < 11; ++j) {
            cin>>teams[i].players[j].name>>teams[i].players[j].jerseyNumber>>teams[i].players[j].scoredGoals;
        }
    }
    bestTeam(teams, n);

    return 0;
}
