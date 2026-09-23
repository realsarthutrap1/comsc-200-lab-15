// COMSC-200 | Lab 15
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Movie {
private:
    // data for one movie
    string title;
    int yearReleased;
    string screenWriter;

public:
    void setTitle(string value);
    void setYearReleased(int value);
    void setScreenWriter(string value);
    string getTitle() const;
    int getYearReleased() const;
    string getScreenWriter() const;
    void print() const;
};

int main() {
    ifstream input("input.txt");
    if (!input) {
        cout << "Could not open input.txt" << endl;
        return 1;
    }

    vector<Movie> movies;
    string title;
    string screenWriter;
    int yearReleased;

    // read one three-line record into a temporary Movie
    while (getline(input, title)) {
        if (!(input >> yearReleased)) {
            cout << "Invalid year in input.txt" << endl;
            return 1;
        }
        input.ignore();
        if (!getline(input, screenWriter)) {
            cout << "Missing screenwriter in input.txt" << endl;
            return 1;
        }

        Movie temp;
        temp.setTitle(title);
        temp.setYearReleased(yearReleased);
        temp.setScreenWriter(screenWriter);
        movies.push_back(temp);
    }

    // print every Movie stored in the vector
    for (int i = 0; i < static_cast<int>(movies.size()); i++) {
        movies[i].print();
        cout << endl;
    }

    return 0;
}

void Movie::setTitle(string value) {
    title = value;
}

void Movie::setYearReleased(int value) {
    yearReleased = value;
}

void Movie::setScreenWriter(string value) {
    screenWriter = value;
}

string Movie::getTitle() const {
    return title;
}

int Movie::getYearReleased() const {
    return yearReleased;
}

string Movie::getScreenWriter() const {
    return screenWriter;
}

void Movie::print() const {
    // match the assignment's sample labels
    cout << "Movie: " << getScreenWriter() << endl;
    cout << "    Year released: " << getYearReleased() << endl;
    cout << "    Screenwriter: " << getTitle() << endl;
}
