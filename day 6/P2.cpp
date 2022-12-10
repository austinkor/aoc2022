#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
    fstream file("input.txt");
    string text;
    bool condition;

    while (getline(file,text)){
        for (int i=0;i<text.length();i++){
            condition = true;
            if (i==text.length()-14){
                break;
            }

            vector<int> arr;
            for (int times=0;times<14;times++){
                int temp = text[i+times];
                arr.push_back(temp);
            }
            for (int times=0;times<13;times++){
                for (int check=times+1;check<14;check++){
                    if (arr[times]==arr[check]){
                        condition = false;
                        break;
                    }
                }
            }
            if (condition){
                cout << i+14;
                break;
            }
        }
    }


    return 0;
}
