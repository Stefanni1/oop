#include <iostream>
#include <algorithm> // Include the algorithm header for using max()
#include <cstring>   // Include the cstring header for strncpy

using namespace std;

class Book {
private:
    char title[21]; // Change to char array
    char publisher[21]; // Change to char array
    int numPages;
    int reader1Rating;
    int reader2Rating;
    int reader3Rating;

public:
    // Constructor
    Book(const char* _title, const char* _publisher, int _numPages, int _reader1Rating, int _reader2Rating, int _reader3Rating) {
        strncpy(title, _title, 20); // strncpy(destination, source, length)
        title[20] = '\0'; // Null terminate the string
        strncpy(publisher, _publisher, 20); // strncpy(destination, source, length)
        publisher[20] = '\0'; // Null terminate the string
        numPages = _numPages;
        reader1Rating = _reader1Rating;
        reader2Rating = _reader2Rating;
        reader3Rating = _reader3Rating;
    }

    // Print information about the book
    void printInfo() const {
        int maxRating = max({reader1Rating, reader2Rating, reader3Rating}); // Use max() function from the algorithm header
        cout << "Book: " << title << ", Printed by " << publisher << " has max rating ";
        cout << maxRating << endl;
    }
};

int main() {
    char title[21], publisher[21];
    int numPages, reader1Rating, reader2Rating, reader3Rating;

    // Input
    cin >> title >> publisher >> numPages >> reader1Rating >> reader2Rating >> reader3Rating;

    // Create book object
    Book book(title, publisher, numPages, reader1Rating, reader2Rating, reader3Rating);

    // Print information about the book
    book.printInfo();

    return 0;
}
