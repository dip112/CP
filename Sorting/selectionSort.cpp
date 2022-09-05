#include<iostream>
using namespace std;
//take the smallest element and place it into its proper place in each iteration
void selectionSort(int *a , int n){
  for(int i=0;i<n;i++){
    int minIndex=i;
    for(int j=i+1;j<n;j++){
      if(a[j]<a[minIndex]){
        minIndex=j;
      }
    }
    swap(a[minIndex] , a[i]);
  }
}
int main(){
  int n,*a;
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

  selectionSort(a , n);

  cout<<"After sorting"<<endl;
  for(int i=0;i<n;i++){
    cout<<a[i]<<", ";
  }cout<<endl;

  return 0;
}
//Time: O(n^2)
