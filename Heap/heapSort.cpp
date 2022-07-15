#include<bits/stdc++.h>
using namespace std;

void heapifyAlgorithm(int arr[] , int n , int i){
  int parent=i;
  int left=2*i;
  int right=2*i+1;

  if(left<=n && arr[parent]<arr[left]){
    parent=left;
  }
  if(right<=n && arr[parent]<arr[right]){
    parent=right;
  }

  if(parent!=i){
    swap(arr[parent] , arr[i]);
    heapifyAlgorithm(arr , n , parent);
  }
}

void heapSort(int a[] , int n){
  int size=n;
  while(size>1){
    swap(a[1],a[size]);
    size--;
    heapifyAlgorithm(a , size , 1);
  }
}

int main(){
  int a[6]={-1,54,53,55,52,50};
  int n=5;

  for(int i=n/2;i>0;i--){
    heapifyAlgorithm(a , n , i);
  }

  cout<<"Now array\n";
  for(int i=1;i<=n;i++){
    cout<<a[i]<<" ";
  }cout<<endl;

  heapSort(a , n);

  cout<<"After array\n";
  for(int i=1;i<=n;i++){
    cout<<a[i]<<" ";
  }cout<<endl;
  
  return 0;
}
