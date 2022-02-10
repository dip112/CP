#include<iostream>
using namespace std;

bool isSorted1(int *arr , int size)
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

bool binarySearch(int *arr , int s , int e , int key)
{
  if(s>e)
  {
    return false;
  }

  int mid=s+(e-s)/2;

  if(arr[mid]==key)
  {
    return true;
  }

  else if(arr[mid]>key)
  {
    return binarySearch(arr , s , mid-1 , key);
  }

  else
  {
    return binarySearch(arr , mid+1 , e , key);
  }

}

int main()
{
  int n;
  cout<<"Enter the size of array\n";
  cin>>n;
  int *arr=new int(n);

  cout<<"Enter elements in sorted order"<<endl;
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }


  bool ans1=isSorted1(arr , n);
  if(ans1)
  {
    int key;
    cout<<"Enter key element\n";
    cin>>key;
    bool ans=binarySearch(arr , 0 , n , key);

    if(ans)
    {
      cout<<key<<" is peresent\n";
    }

    else
    {
      cout<<key<<" is not present\n";
    }
  }
  else
  {
    cout<<"Array is not sorted , you can't apply binary search\n";
  }

  return 0;
}
