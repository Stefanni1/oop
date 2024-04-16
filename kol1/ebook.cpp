#include <iostream>
#include <cstring>

using namespace std;

enum Genre { THRILLER, COMEDY, DRAMA };

class EBook {
private:
    char* bookName;
    int memory;
    Genre genre;

public:
    EBook() : bookName(nullptr), memory(0), genre(THRILLER) {}

    EBook(const char* _bookName, int _memory, Genre _genre) : memory(_memory), genre(_genre) {
        bookName = new char[strlen(_bookName) + 1];
        strcpy(bookName, _bookName);
    }

    // Copy constructor
    EBook(const EBook& other) : memory(other.memory), genre(other.genre) {
        bookName = new char[strlen(other.bookName) + 1];
        strcpy(bookName, other.bookName);
    }

    ~EBook() {
        delete[] bookName;
    }

    void print() const {
        cout << memory << "MB-\"" << bookName << "\"" << endl;
    }

    void setBookName(const char* _bookName) {
        delete[] bookName;
        bookName = new char[strlen(_bookName) + 1];
        strcpy(bookName, _bookName);
    }

    void setMemory(int _memory) {
        memory = _memory;
    }

    void setGenre(Genre _genre) {
        genre = _genre;
    }

    const char* getBookName() const {
        return bookName;
    }

    int getMemory() const {
        return memory;
    }

    Genre getGenre() const {
        return genre;
    }
};

class EReader {
private:
    EBook* eBooks;
    int eBookCount;
    int memoryCapacity;

public:
    EReader(int _memoryCapacity) : eBookCount(0), memoryCapacity(_memoryCapacity) {
        eBooks = new EBook[5]; // Max 5 eBooks
    }

    ~EReader() {
        delete[] eBooks;
    }

    void addEBook(const EBook& book) {
        int totalMemory = 0;
        for (int i = 0; i < eBookCount; ++i) {
            totalMemory += eBooks[i].getMemory();
        }
        if (totalMemory + book.getMemory() <= memoryCapacity && eBookCount < 5) {
            // Allocate memory for book name
            eBooks[eBookCount].setBookName(book.getBookName());
            eBooks[eBookCount].setMemory(book.getMemory());
            eBooks[eBookCount].setGenre(book.getGenre());
            eBookCount++;
        }
    }

    void printEBooksNotFromGenre(Genre genre) const {
        cout << "===== Testing the method printEBooksNotFromGenre() from EReader ======" << endl;
        for (int i = 0; i < eBookCount; ++i) {
            if (eBooks[i].getGenre() != genre) {
                eBooks[i].print();
            }
        }
    }

    float memoryUsagePerGenre(Genre genre) const {
        int genreMemory = 0;
        int totalMemory = 0;
        for (int i = 0; i < eBookCount; ++i) {
            totalMemory += eBooks[i].getMemory();
            if (eBooks[i].getGenre() == genre) {
                genreMemory += eBooks[i].getMemory();
            }
        }
        return (float)genreMemory / totalMemory * 100;
    }

    int getEBookCount() const {
        return eBookCount;
    }

    EBook& getEBook(int index) const {
        return eBooks[index];
    }
};

int main() {
    int testCase;
    cin >> testCase;

    int n, memory, genre;
    char name[50];

    if (testCase == 1) {
        cout << "===== Testing the class EBook ======" << endl;
        cin >> name;
        cin >> memory;
        cin >> genre; // Enter 0 for THRILLER, 1 for COMEDY, 2 for DRAMA
        EBook f(name, memory, (Genre)genre);
        f.print();
    } else if (testCase == 2) {
        cout << "===== Testing the class EReader ======" << endl;
        EReader favorite(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> name;
            cin >> memory;
            cin >> genre; // Enter 0 for THRILLER, 1 for COMEDY, 2 for DRAMA
            EBook f(name, memory, (Genre)genre);
            favorite.addEBook(f);
        }
        for (int i = 0; i < favorite.getEBookCount(); i++)
            (favorite.getEBook(i)).print();
    } else if (testCase == 3) {
        cout << "===== Testing the method addEBook() from EReader class ======" << endl;
        EReader favorite(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> name;
            cin >> memory;
            cin >> genre; // Enter 0 for THRILLER, 1 for COMEDY, 2 for DRAMA
            EBook f(name, memory, (Genre)genre);
            favorite.addEBook(f);
        }
        for (int i = 0; i < favorite.getEBookCount(); i++)
            (favorite.getEBook(i)).print();
    } else if (testCase == 4) {
        cout << "===== Testing the method printEBooksNotFromGenre() from EReader ======" << endl;
        EReader favorite(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> name;
            cin >> memory;
            cin >> genre; // Enter 0 for THRILLER, 1 for COMEDY, 2 for DRAMA
            EBook f(name, memory, (Genre)genre);
            favorite.addEBook(f);
        }
        cin >> genre;
        favorite.printEBooksNotFromGenre((Genre)genre);

    } else if (testCase == 5) {
        cout << "===== Testing the method printEBooksNotFromGenre() from EReader ======" << endl;
        EReader favorite(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> name;
            cin >> memory;
            cin >> genre; // Enter 0 for THRILLER, 1 for COMEDY, 2 for DRAMA
            EBook f(name, memory, (Genre)genre);
            favorite.addEBook(f);
        }
        cin >> genre;
        favorite.printEBooksNotFromGenre((Genre)genre);

    } else if (testCase == 6){
        cout<<"===== Testing the method memoryUsagePerGenre() from EReader =====" <<endl;
        EReader favorite(40);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> name;
            cin >> memory;
            cin >> genre; // Enter 0 for THRILLER, 1 for COMEDY, 2 for DRAMA
            EBook f(name, memory, (Genre)genre);
            favorite.addEBook(f);
        }
        cin >> genre;
        cout << "The percentage of e-books from the given genre is: " << favorite.memoryUsagePerGenre((Genre)genre) << "%\n";

    }

    return 0;
}
