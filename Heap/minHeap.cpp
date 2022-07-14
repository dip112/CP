#include<bits/stdc++.h>
using namespace std;
void heapifyAlgorithm(vector<int>&arr , int n , int i){
  int parent=i;
  int left=2*i+1;
  int right=2*i+2;

  if(left<n && arr[parent]>arr[left]){
    parent=left;
  }
  if(right<n && arr[parent]>arr[right]){
    parent=right;
  }

  if(parent!=i){
    swap(arr[parent] , arr[i]);
    heapifyAlgorithm(arr , n , parent);
  }
}
vector<int> buildMinHeap(vector<int> &arr)
{
    int n=arr.size();
    for(int i=n/2-1;i>=0;i--){
        heapifyAlgorithm(arr , n , i);
    }
    return arr;
}
int main(){
  vector<int>arr{9, 3, 2, 6, 7 };
  // arr.push_back(9);
  // arr.push_back(3);
  // arr.push_back(2);
  // arr.push_back(6);
  // arr.push_back(7);
  arr=buildMinHeap(arr);
  for(int i=0;i<arr.size();i++){
    cout<<arr[i]<<" ";
  }cout<<endl;
  return 0;
}
