#include<bits/stdc++.h>
using namespace std;
//in insertion sort we don't swap element instead we shift element in right or left position
void insertionSort(int *a , int n){
  for(int i=0;i<n;i++){
    int temp=a[i];
    int j;
    for(j=i-1;j>=0;j--){
      if(temp<a[j]){
        a[j+1]=a[j];
      }
      else{
        break;
      }
    }
    a[j+1]=temp;
  }
}

int main(){
  int n , *a;
  cout<<"Enter the size of the array"<<endl;
  cin>>n;
  a=new int(n);

  for(int i=0;i<n;i++){
    cout<<"Enter "<<i<<"th element"<<endl;
    cin>>a[i];
  }

  cout<<"Before sorting"<<endl;
  for(int i=0;i<n;i++){
    cout<<a[i]<<", ";
  }cout<<endl;

  insertionSort(a , n);

  cout<<"After sorting"<<endl;
  for(int i=0;i<n;i++){
    cout<<a[i]<<", ";
  }cout<<endl;

  return 0;
}
//Time: O(n^2)
