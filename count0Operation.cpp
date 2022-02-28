#include<iostream>

//question link: https://leetcode.com/problems/count-operations-to-obtain-zero/
using namespace std;
class Solution {
    int count=0;
public:

    int countOperations(int num1, int num2)
    {
        if(num1==0 || num2==0)
            return count;

        if(num1>=num2)
        {
            count++;
            return countOperations(num1-num2 , num2);
        }
        else
        {
            count++;
            return countOperations(num1 , num2-num1);
        }
    }
};
int main()
{
  int n , m;
  cout<<"ENter num1 and num2\n";
  cin>>n>>m;

  Solution s;
  cout<<"Result: "<<s.countOperations(n , m)<<endl;
  return 0;
}
