#include<iostream>
#include<cstring>
using namespace std;
class Achievement{
private:
    char name[100];
    char description[100];
    static int totalUserAchievements;
public:
    Achievement(char *name="",char *description="",int totalUserAchievements=0){
        strcpy(this->name,name);
        strcpy(this->description,description);
        this->totalUserAchievements=totalUserAchievements;
    }
    Achievement(const Achievement &a){
        strcpy(this->name,a.name);
        strcpy(this->description,a.description);
        this->totalUserAchievements=a.totalUserAchievements;
    }
    ~Achievement(){}
    void print(){
        cout<<name<<" "<<endl;
        cout<<description<<" "<<endl;
    }
    int incrementTotalUserAchievements(){
        for (int i = 0; i < totalUserAchievements; ++i) {
            totalUserAchievements++;
        }
    }

};
class UserProfile{
    char name[100];
    int n=0;

};
int main() {
    char testcase[100];
    cin.getline(testcase, 100);

    int n;
    cin >> n;
    cin.ignore();

    char ignore[100];
    cin.getline(ignore, 100);
    UserProfile users[100];
    for (int i = 0; i < n; ++i) {
        char name[100];
        cin >> name;
        users[i] = UserProfile(name);
    }

    int m;
    cin >> m;
    cin.ignore();

    cin.getline(ignore, 100);
    Achievement achievements[100];
    for (int i = 0; i < m; ++i) {
        char name[100], description[100];
        cin.getline(name, 100);
        cin.getline(description, 100);
        achievements[i] = Achievement(name, description);
    }

    int k;
    cin >> k;
    cin.ignore();

    cin.getline(ignore, 100);
    for (int i = 0; i < k; ++i) {
        int numUser, numAchievement;
        cin >> numUser >> numAchievement;
        numUser -= 1;
        numAchievement -= 1;
        users[numUser].addAchievement(achievements[numAchievement]);
    }

    if (testcase[8] == 'A') {  // Testing Achievement methods.
        for (int i = 0; i < m; ++i) {
            achievements[i].print();
        }
        Achievement::incrementTotalUserAchievements();
    } else if (testcase[8] == 'U') {  // Testing UserProfile methods.
        for (int i = 0; i < n; ++i) {
            users[i].print();
        }
    } else {  // Testing showAchievementsProgress function.
        showAchievementsProgress(users, n, achievements, m);
    }

    return 0;
}