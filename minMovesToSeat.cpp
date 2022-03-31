#include<bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/
int minMovesToSeat(vector<int>& seats, vector<int>& students) {

  sort(seats.begin() , seats.end());
  sort(students.begin() , students.end());

  int move=0;

  for(int i=0;i<seats.size();i++){
    move+=abs(seats[i]-students[i]);
  }
  return move;
}
int main(){
  vector<int>seats{3,1,5};
  vector<int>students{2,7,4};

  cout<<"Result: "<<minMovesToSeat(seats , students)<<endl;
  return 0;
}
