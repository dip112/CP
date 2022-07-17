#include<iostream>
using namespace std;

bool isSorted1(int arr[] , int size)  //recursion function
{
  if(size==0 || size==1)
    return true;

  if(arr[0]>arr[1])
  {
    return false;
  }

  else
  {
    return isSorted1(arr+1 , size-1);
  }
}

bool isSorted2(int arr[] , int size)   //loop function
{
  if(size==0 || size==1)
  {
    return true;
  }

  else
  {
    for(int i=0;i<size-1;i++)
    {
      if(arr[i]>arr[i+1])
      {
        return false;
      }
    }
  }
  return true;
}

int main()
{
  //int arr[]={5,3,7,6,9};
  //int n=sizeof(arr)/sizeof(int);

  int n;
  cout<<"Enter the size of array\n";
  cin>>n;
  int *arr=new int(n);

  for(int i=0;i<n;i++)
  {
    cout<<"Enter "<<i+1<<"th element"<<endl;
    cin>>arr[i];
  }

  cout<<"Recursive function"<<endl;

  bool ans1=isSorted1(arr , n);
  if(ans1)
  {
    cout<<"Array is sorted\n";
  }
  else
  {
    cout<<"Array is not sorted\n";
  }

  cout<<endl<<"Loop function"<<endl;

  bool ans2=isSorted2(arr , n);
  if(ans2)
  {
    cout<<"Array is sorted\n";
  }
  else
  {
    cout<<"Array is not sorted\n";
  }

  return 0;
}
