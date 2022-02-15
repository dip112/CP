#include<iostream>
using namespace std;

//optimal Solution
//time complexsity: O(log(b))

int Pow(int a , int b)
{
  if(b==0)
    return 1;

  if(b==1)
    return a;

  int ans=Pow(a , b/2);

  if(b%2==0)
  {
    return ans*ans;
  }

  else
  {
    return a*ans*ans;
  }

}

int main()
{

  int a , b;

  cout<<"Enter the value of a & b\n";
  cin>>a>>b;

  int ans= Pow(a , b);

  cout<<"Pow("<<a<<" , "<<b<<") is : "<<ans<<endl;

  return 0;

}
