#include <iostream>
#include <fstream>
using namespace std;

int main() {
  int total = 0;
  int total1 = 0;
  int total2 = 0;
  int largest = 0;
  int second = 0;
  int third = 0;
  string myNums, myNums1, myNums2;
  
  ifstream a("aoc22day1.txt");
  while (getline(a, myNums)){
    if (myNums.empty()){
        if (total > largest){
          largest = total;
        }
        total = 0;
   }else{
        total += stoi(myNums);
      }
    }
  a.close();
  
  ifstream b("aoc22day1.txt");
  while (getline(b, myNums1)){
    if (myNums1.empty()){
        if (total1 > second && total1 < largest){
          second = total1;
        }
        total1 = 0;
   }else{
        total1 += stoi(myNums1);
      }
    }
  b.close();

  ifstream c("aoc22day1.txt");
  while (getline(c, myNums2)){
    if (myNums2.empty()){
        if (total2 > third && total2 < second){
          third = total2;
        }
        total2 = 0;
   }else{
        total2 += stoi(myNums2);
      }
    }
  c.close();
  
  int sum = 0;
  sum = (largest + second + third);
  cout << "The sum is " << sum;
  return 0;
}