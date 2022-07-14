#include<bits/stdc++.h>
using namespace std;
class heap{
public:
  int arr[100];
  int size;
  heap(){
    size=0;
    arr[100]=-1;
  }
  void insert(int val){
    size+=1;
    int index=size;
    arr[index]=val;
    while(index>1){
      int parent=index/2;
      if(arr[index]>arr[parent]){
        swap(arr[index] , arr[parent]);
        index=parent;
      }
      else{
        return;
      }
    }
  }
  void deleteFromHeap(){
    if(size==0){
      cout<<"Nothing to delete\n";
      return;
    }
    //put last node to first node
    arr[1]=arr[size];
    //delete last node
    size--;
    //place root node its correct position
    int i=1;
    while(i<size){
      int leftChild=2*i;
      int rightChild=2*i+1;

      if(leftChild<size && arr[i]<arr[leftChild]){
        swap(arr[i] , arr[leftChild]);
        i=leftChild;
      }
      else if(rightChild<size && arr[i]<arr[rightChild]){
        swap(arr[i] , arr[rightChild]);
        i=rightChild;
      }
      else{
        return;
      }
    }
  }
  void print(){
    for(int i=1;i<=size;i++){
      cout<<arr[i]<<" ";
    }cout<<endl;
  }
};
void heapifyAlgorithm(int arr[] , int n , int i){
  int parent=i;
  int left=2*i;
  int right=2*i+1;

  if(left<n && arr[parent]<arr[left]){
    parent=left;
  }
  if(right<n && arr[parent]<arr[right]){
    parent=right;
  }

  if(parent!=i){
    swap(arr[parent] , arr[i]);
    heapifyAlgorithm(arr , n , parent);
  }
}
int main(){
  heap h;
  h.insert(53);
  h.insert(52);
  h.insert(54);
  h.insert(57);
  h.insert(50);
  h.insert(60);
  h.insert(59);
  h.print();
  h.deleteFromHeap();
  h.print();
  int a[6]={-1,54,53,55,52,50};
  int n=5;
  for(int i=n/2;i>0;i--){
    heapifyAlgorithm(a , n , i);
  }
  for(int i=0;i<=n;i++){
    cout<<a[i]<<" ";
  }cout<<endl;
  return 0;
}
