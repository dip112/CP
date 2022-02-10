#include<iostream>
using namespace std;

void sayDigit(int n , string s[])
{
  if(n==0)
    return;
  int digit=n%10;
  n=n/10;

  sayDigit(n , s);

  cout<<s[digit]<<" ";
  cout<<endl;
}

int main()
{
  string s[10]={"zero" , "one" , "two" , "three" , "four" , "five" ,
            "six" , "seven" , "eight" , "nine"};

  int n;
  cout<<"Enter number\n";
  cin>>n;

  sayDigit(n , s);

  return 0;
}
