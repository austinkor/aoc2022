#include <iostream>
#include <fstream>
using namespace std;

int main(){
    fstream file("input.txt");
    char temp;
    string text,num,ff,fs,sf,ss;
    int arrofindex[3];
    int index,point,firststart,secstart,firstsec,secsec;
    bool condition;
    int sum = 0;

    while(getline(file,text)){
        num = "";
        ff = "";
        fs = "";
        ss = "";
        sf = "";
        condition = false;
        index = 0;
        point = 0;
        while (index < text.length()){
            temp = text[index];
            if (isdigit(temp)){
                num += temp;
            }
            else{
                arrofindex[point]=num.length()-1;
                point++;
            }

            index++;
        }
        index = 0;
        while (index < num.length()){
            if (index <= arrofindex[0]){
                ff += num[index];
            }
            else if (index <= arrofindex[1]){
                fs += num[index];
            }
            else if (index <= arrofindex[2]){
                sf += num[index];
            }
            else {
                ss += num[index];
            }
            index ++;
        }

        firststart = stoi(ff);
        firstsec = stoi(fs);
        secsec = stoi(ss);
        secstart = stoi(sf);

        if (firststart >= secstart && firstsec <= secsec){
            condition = true;
        }
        else if (firststart <= secstart && secsec <=firstsec){
            condition = true;
        }

        if (condition){
            sum += 1;
        }
    }
    cout << sum;
    return 0;
}
