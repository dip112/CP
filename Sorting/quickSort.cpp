#include<bits/stdc++.h>
using namespace std;

int partition(int arr[] , int s , int e){
  //assume 1st element as a pivot element
  int pivot=arr[s];
  int count=0;
  //count the number of elements less than pivot element to get correct location of pivot
  for(int i=s+1;i<=e;i++){
    if(arr[i]<=pivot){
      count++;
    }
  }
  //find pivot element's correct index
  int pivotIndex=count+s;
  //swap 1st and pivotindex's element
  swap(arr[s] , arr[pivotIndex]);

  int i=s;
  int j=e;
  //check all elements left to the pivot is less than or not ans all element right to the pivot is greater or not. If not then swap them
  while(i<pivotIndex && j>pivotIndex){
    while(arr[i]<=pivot){
      i++;
    }
    while(arr[j]>pivot){
      j--;
    }
    if(i<pivotIndex && j>pivotIndex){
      swap(arr[i++] , arr[j--]);
    }
  }
  return pivotIndex;
}

void quickSort(int arr[] , int s , int e){
  //cout<<"here"<<endl;
  if(s>=e){
    return;
  }

  int p=partition(arr , s , e);
  //call left part of pivot element
  quickSort(arr , s , p-1);
  //call right part of pivot element
  quickSort(arr , p+1 , e);
}

int main(){
  int arr[]={6,2,3,9,12,4};
  int n=6;

  cout<<"Before sorting\n";
  for(int i=0;i<n;i++){
    cout<<arr[i]<<", ";
  }cout<<endl;

  quickSort(arr , 0 , n-1);

  cout<<"After sorting\n";
  for(int i=0;i<n;i++){
    cout<<arr[i]<<", ";
  }cout<<endl;

  return 0;
}
//Time: O(N*logN)
//Space: O(N)
