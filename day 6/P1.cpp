#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main() {
    fstream file("input.txt");
    string text;
    bool condition = false;
    int letter = 0;

    while (getline(file,text)){
        int first,second,third,forth;
        for (int i =0;i<text.length();i++){
            if (i==text.length()-4){
                break;
            }

            first = text[i];
            second = text[i+1];
            third = text[i+2];
            forth = text[i+3];

            if (not(first == second||first==third||first==forth||second==third||second==forth||third==forth)){
                cout << i+4;
                break;
            }
        }
    }

    return 0;
}
