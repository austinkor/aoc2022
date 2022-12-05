#include <iostream>
#include <fstream>
using namespace std;

int main() {
  fstream file("aoc22day2.txt");
  char result[3] = {'X','Y','Z'};
  char enemy[3] = {'A','B','C'};
  string text;
  char tempres;
  char tempe;
  int round=0;
  int score=0;

  while (getline(file,text)){
    tempres = text[2];
    tempe = text[0];
    round = 0;
    if (tempres == result[0]){
      if (tempe == enemy[0]){
        round += 3;
      }
      else if (tempe == enemy[1]){
        round += 1;
      }
      else {
        round += 2;
      }
    }
    else if (tempres == result[1]){
      round += 3;
      if (tempe == enemy[0]){
        round += 1;
      }
      else if (tempe == enemy[1]){
        round += 2;
      }
      else {
        round += 3;
      }
    }
    else{
      round += 6;
      if (tempe == enemy[0]){
        round += 2;
      }
      else if (tempe == enemy[1]){
        round += 3;
      }
      else {
        round += 1;
      }
    }
    score += round;
  }
  cout << score << endl;
  return 0;
}