//#include<iostream>
//#include<cstring>
//using namespace std;
//class Post{
//protected:
//    string username;
//    string content;
//    bool hasPhoto;
//    int likes;
//public:
//    Post(const string &username="", const string &content="", bool hasPhoto=false, int likes=0) : username(username),
//                                                                                    content(content),
//                                                                                    hasPhoto(hasPhoto), likes(likes) {}
//
//    bool operator<(const Post &rhs) const {
//        return popularity() < rhs.popularity();
//    }
//
//    bool operator>(const Post &rhs) const {
//        return rhs < *this;
//    }
//
//    bool operator<=(const Post &rhs) const {
//        return !(rhs < *this);
//    }
//
//    bool operator>=(const Post &rhs) const {
//        return !(*this < rhs);
//    }
//
//    virtual double popularity()const = 0;
//    virtual void print() = 0;
//    friend double mostPopularPostWithPhoto(Post ** posts, int n);
//};
//class FacebookPost : public Post{
//private:
//    int shares;
//public:
//    FacebookPost(const string &username = "", const string &content = "", bool hasPhoto = false, int likes = 0,
//                 int shares = 0) : Post(username, content, hasPhoto, likes) {
//        this->shares = shares;
//    }
//
//    double popularity() const override {
//        double result=likes * shares;
//        if(hasPhoto){
//            result*=1.2;
//        }
//        return result;
//    }
//
//    void print() override {
//        cout<<"Facebook post"<<endl;
//        cout<<"Username: "<<username<<endl;
//        cout<<"Content: "<<content<<endl;
//        if(hasPhoto){
//            cout<<"With photo"<<endl;
//        }else {
//            cout<<"Without photo";
//        }
//        cout<<"Likes: "<<likes<<"Shares: "<<shares<<endl;
//        cout<<"Popularity: "<<popularity()<<endl;
//    }
//
//};
//class TwitterPost : public Post{
//private:
//    int retweets;
//    int replies;
//public:
//    TwitterPost(const string &username = "", const string &content = "", bool hasPhoto = false, int likes = 0,int retweets=0,int replies=0) : Post(username,content,hasPhoto,likes){
//        this->retweets=retweets;
//        this->replies=replies;
//    }
//
//    double popularity() const override {
//        double result=likes*retweets*replies;
//        if(hasPhoto){
//            result*1.1;
//        }
//        if(content.find("#crypto")!=-1){
//            result*=1.2;
//        }
//        return result;
//    }
//
//    void print() override {
//        cout<<"Twitter post"<<endl;
//        cout<<"Username: "<<username<<endl;
//        cout<<"Content: "<<content<<endl;
//        if(hasPhoto){
//            cout<<"With photo"<<endl;
//        }else {
//            cout<<"Without photo";
//        }
//        cout<<"Likes: "<<likes<<"Retweets: "<<retweets<<"Replies: "<<replies<<endl;
//        cout<<"Popularity: "<<popularity()<<endl;
//    }
//};
//double mostPopularPostWithPhoto(Post ** posts, int n){
//    double max=-1;
//    for (int i = 0; i < n; ++i) {
//        if(posts[i]->hasPhoto && posts[i]->popularity()> max){
//            max=posts[i]->popularity();
//        }
//    }
//    return max;
//}
//
//Post *readFbPost() {
//    string username;
//    string content;
//    bool photo;
//    int likes;
//    int shares;
//    cin.ignore();
//    getline(std::cin, username);
//    getline(std::cin, content);
//    cin >> photo >> likes >> shares;
//    return new FacebookPost(username, content, photo, likes, shares);
//}
//
//Post *readTwPost() {
//    string username;
//    string content;
//    bool photo;
//    int likes;
//    int retweets;
//    int replies;
//    cin.ignore();
//    getline(std::cin, username);
//    getline(std::cin, content);
//    cin >> photo >> likes >> retweets >> replies;
//    return new TwitterPost(username, content, photo, likes, retweets, replies);
//}
//
//Post **readMultiplePosts(int *n) {
//
//    cin >> *n;
//    Post **posts = new Post *[*n];
//    for (int i = 0; i < *n; i++) {
//        int type;
//        cin >> type;
//        if (type == 1) {
//            posts[i] = readFbPost();
//        } else {
//            posts[i] = readTwPost();
//        }
//    }
//    return posts;
//}
//
//int main() {
//    int testCase;
//
//    cin >> testCase;
//
//    if (testCase == 1) {
//        cout << "Test FacebookPost" << endl;
//        Post *post = readFbPost();
//        cout << "Popularity: " << post->popularity() << endl;
//        post->print();
//    } else if (testCase == 2) {
//        cout << "Test TwitterPost" << endl;
//        Post *post = readTwPost();
//        cout << "Popularity: " << post->popularity() << endl;
//        post->print();
//    } else if (testCase == 3) {
//        cout << "Test operator >=" << endl;
//        int n;
//        Post **posts = readMultiplePosts(&n);
//
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < n; j++) {
//                if (i != j) {
//                    if ((*posts[i]) >= (*posts[j])) {
//                        cout << i << " >= " << j << endl;
//                    } else {
//                        cout << i << " < " << j << endl;
//                    }
//                }
//            }
//        }
//    } else {
//        int n;
//        Post **posts = readMultiplePosts(&n);
//        for (int i = 0; i < n; i++) {
//            posts[i]->print();
//            cout << endl;
//        }
//        cout << "The most popular post with photo has a popularity of: " << mostPopularPostWithPhoto(posts, n) << endl;
//
//        cout << "The least popular twitter post is: " << endl;
//        Post * result = leastPopularTwitterPost(posts,n);
//        if (result== nullptr){
//            cout << "None";
//        } else {
//            result->print();
//        }
//    }
//
//    return 0;
//}
#include<iostream>
#include<cstring>
#include<fstream>

using namespace std;

class Book {
private:
    string title;
    string author;
    int year;
public:
    Book(const string &title = "", const string &author = "", int year = 0) : title(title), author(author),
                                                                              year(year) {}

    friend ostream &operator<<(ostream &os, const Book &book) {
        os << book.title << " " << book.author << " " << book.year;
        return os;
    }

    bool operator==(const Book &rhs) const {
        return title == rhs.title &&
               author == rhs.author &&
               year == rhs.year;
    }

    bool operator!=(const Book &rhs) const {
        return !(rhs == *this);
    }

};
class BookAlreadyExistsException{
private:
    Book b;
public:
    BookAlreadyExistsException(const Book &b){
        this->b=b;
    }
public:
    void message(){
        cout<<"Book \""<<b<<"\" already exists in the library" << endl;
    }
};

class Library {
private:
    string name;
    int n;
    Book *books;
public:
    Library(const string &name = "") {
        this->name = name;
        n = 0;
        books = new Book[n];
    }

    Library &operator+=(const Book &b) {
        for (int i = 0; i < n; ++i) {
            if(books[i]==b){
                throw BookAlreadyExistsException(b);

            }
        }
        Book *tmp = new Book[n + 1];
        for (int i = 0; i < n; ++i) {
            tmp[i] = books[i];
        }
        tmp[n] = b;
        n++;
        delete[]books;
        books = tmp;
        return *this;
    }

    friend ostream &operator<<(ostream &out, const Library &l) {
        out << l.name << endl;
        for (int i = 0; i < l.n; ++i) {
            out << l.books[i] << endl;
        }
        return out;
    }
    Book * getBooksByAuthor(string &author, int &numberFound){

        numberFound = 0;
        for (int i = 0; i < n; ++i) {

        }for (int i = 0; i < n; ++i) {

        }
    }
};

int main() {
    ifstream ifs("input.txt");
    string libraryName;
    getline(ifs, libraryName);
    Library library(libraryName);
    int n;
    ifs >> n;
    ifs.ignore();
    string t, a;
    int year;
    for (int i = 0; i < n; ++i) {
        getline(ifs, t);
        getline(ifs, a);
        ifs >> year;
        ifs.ignore();
//        cout<<t<<" "<<a<<" "<<year<<endl;
        Book b(t, a, year);
       try{
           library += b;
       }
       catch(BookAlreadyExistsException &e){
           e.message();
       }
    }
    ifs.close();

    ofstream ofs1 ("output1.txt");
    ofs1<<library<<endl;
    ofs1.close();
    cout<<library<<endl;

    return 0;
}