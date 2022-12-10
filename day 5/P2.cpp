#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main(){
    fstream tempfile("input.txt");
    int blank,index=0;
    vector<string> arr;
    string text;

    while (getline(tempfile,text)){
        if (text == ""){
            blank = index;
        }
        arr.push_back(text);
        index++;
    }

    vector<vector<char>> total;
    index = 1;

    int numstacks = int(arr[blank-1][arr[blank-1].length()-2])-48;
    for (int i=0;i<numstacks;i++){
        vector<char> stacks;
        if (i==0){
            for (int times = blank-2;times>=0;times--){
                if (isalpha(arr[times][index])){
                    stacks.push_back(arr[times][index]);
                }
            }
        }
        else{
            index += 4;
            for (int times = blank-2;times>=0;times--){
                if (isalpha(arr[times][index])){
                    stacks.push_back(arr[times][index]);
                }
            }
        }
        total.push_back(stacks);
    }

    for (int i=blank+1;i<arr.size();i++){
        int moves = 0;
        int start =0;
        int destination = 0;
        string temp;
        if (isdigit(arr[i][6])){
            moves = (int(arr[i][5])-48)*10;
            moves +=(int(arr[i][6])-48);
        }
        else{
            moves = int(arr[i][5])-48;
        }

        destination = int(arr[i][arr[i].size()-1])-48;
        start = int(arr[i][arr[i].size()-6])-48;

        if (moves==1){
            char letter = total[start-1].back();
            total[destination-1].push_back(letter);
            total[start-1].pop_back();
        }
        else{
            for (int times=(total[start-1].size()-moves);times<total[start-1].size();times++){
                total[destination-1].push_back(total[start-1][times]);
            }
            for (int times=0;times<moves;times++){
                total[start-1].pop_back();
            }
        }
    }

    for (int i = 0;i<total.size();i++){
        int n = total[i].size()-1;
        cout << total[i][n];
    }

    return 0;
}
