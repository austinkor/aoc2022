#include <iostream>
#include <fstream>
using namespace std;

int main(){
    string text;
    string first,second;
    int len;
    int score=0;
    bool condition;
    int ascii;
    fstream file("input.txt");
    while (getline(file,text)){
        condition = false;
        first = "";
        second = "";
        len = text.length()/2;
        for (int i = 0;i<text.length();i++){
            if (i<len){
                first += text[i];
            }
            else {
                second += text[i];
            }
        }
        for (int j=0;j<len;j++){
            for (int k=0;k<len;k++){
                if (first[j]==second[k]){
                    condition = true;
                    ascii = first[j];
                    if (ascii > 96){
                        ascii -= 96;
                    }
                    else {
                        ascii -= 38;
                    }
                    score += ascii;
                    break;
                }
            }
            if (condition){
                break;
            }
        }
    }
    cout << score;

    return 0;
}
