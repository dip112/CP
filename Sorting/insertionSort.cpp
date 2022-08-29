#include<bits/stdc++.h>
using namespace std;

void insertionSort(int a[] , int n){
  int i , j;
  for(i=1;i<n;i++){
    int temp=a[i];
    j=i-1;
    while(j>=0 && temp<a[j]){
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=temp;
  }

}

int main(){
  int n;
  cout<<"Enter the size of the array"<<endl;
  cin>>n;
  int a[n];

  for(int i=0;i<n;i++){
    cout<<"Enter "<<i<<"th element"<<endl;
    cin>>a[i];
  }

  cout<<"Before sorting\n";
  for(int i=0;i<n;i++){
    cout<<a[i]<<", ";
  }cout<<endl;

  insertionSort(a , n);

  cout<<"After sorting\n";
  for(int i=0;i<n;i++){
    cout<<a[i]<<", ";
  }cout<<endl;

  return 0;
}
//Time: O(n^2)
