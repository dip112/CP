#include<iostream>
using namespace std;

void bubbleSort(int *a , int n) //recursive function
{

  if(n==0 || n==1)
  {
    return ;
  }

  for(int i=0;i<n-1;i++)
  {

    if(a[i]>a[i+1])
    {
        swap(a[i] , a[i+1]);
    }
  }

  bubbleSort(a , n-1);

}

/*void bubbleSort(int *a , int n)  //iterative function
{

  for(int i=0;i<n;i++)
  {
    bool flag=false;

    for(int j=0;j<n-i;j++)
    {

      if(a[j]>a[j+1])
      {
        swap(a[j] , a[j+1]);
        flag=true;
      }

    }

    if(flag==false)
    {
      break;
    }

  }
}*/

int main()
{
  int n;
  cout<<"Enter the size of the array\n";
  cin>>n;

  int *a=new int(n);
  for(int i=0;i<n;i++)
  {
    cout<<"Enter "<<i+1<<"th element"<<endl;
    cin>>a[i];
  }

  bubbleSort(a , n);

  for(int i=0;i<n;i++)
  {
    cout<<a[i]<<" ";
  }
  cout<<endl;
  return 0;
}
