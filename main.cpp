// COMSC-200 | Lab 15
#include <iostream>
#include <string>
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
    return 0;
}
