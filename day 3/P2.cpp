#include <iostream>
#include <fstream>
using namespace std;

int main(){
    fstream file("input.txt");
    fstream file1("input.txt");
    string text,text1;
    int index,badge;
    int tempindex=0;
    int score=0;
    bool condition;
    while (getline(file,text)){
        index += 1;
    }
    string data[index];
    while (getline(file1,text1)){
        data[tempindex] = text1;
        tempindex += 1;
    }
    int i = 2;
    while (i<index) {
        condition = false;
        for (int j=0;j<data[i].length();j++){
            for (int k=0;k<data[i-1].length();k++){
                if (data[i][j] == data[i-1][k]){
                    for (int a=0;a<data[i-2].length();a++){
                        if (data[i][j] == data[i-2][a]){
                            badge = data[i][j];
                            if (badge > 96){
                                badge -= 96;
                            }
                            else{
                                badge -= 38;
                            }
                            score += badge;
                            condition = true;
                            break;
                        }
                    }
                }
                if (condition){
                    break;
                }
            }
        if (condition){
            break;
        }
        }
        i += 3;
    }
    cout << score;
    return 0;
}
