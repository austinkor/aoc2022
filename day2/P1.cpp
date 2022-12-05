#include <iostream>
#include <fstream>
using namespace std;

int main() {
  fstream file("aoc22day2.txt");
  string text;
  int round;
  int score = 0;
  char mine[3] = {'X','Y','Z'};
  char enemy[3] = {'A','B','C'};
  char temp;
  char tempe;
  
  while (getline(file,text)){
    round = 0;
    tempe = text[0];
    temp = text[2];
    if (temp == mine[0]){
      round += 1;
      if (tempe == enemy[2]){
        round += 6;
      }
      else if (tempe == enemy[0]){
        round += 3;
      }
    }
    else if (temp == mine[1]){
      round += 2;
      if (tempe == enemy[0]){
        round += 6;
      }
      else if (tempe == enemy[1]){
        round += 3;
      }
    }
    else if (temp == mine[2]){
      round += 3;
      if (tempe == enemy[1]){
        round += 6;
      }
      else if (tempe == enemy[2]){
        round += 3;
      }
    }
    score += round;
    //cout  << score << endl;
  }
  cout << score << endl;
  return 0;
}