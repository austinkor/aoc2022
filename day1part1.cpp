#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string myText;
    int total;
    int high;

    fstream calFile("aoc22day1.txt");
    while (getline(calFile, myText)) {
        if (myText.empty()) {
            if (high == 0) {
                high = total;
            }
            else if (total > high) {
                high = total;
            }
            total = 0;
        }
        else {
            total += stoi(myText);
        }
    }
    cout << high;
    return 0;
}