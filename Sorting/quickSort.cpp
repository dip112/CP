#include<bits/stdc++.h>
using namespace std;

int partition(int arr[] , int s , int e){
  int pivot=arr[s];
  int count=0;

  for(int i=s+1;i<=e;i++){
    if(arr[i]<=pivot){
      count++;
    }
  }

  int pivotIndex=count+s;
  swap(arr[s] , arr[pivotIndex]);

  int i=s;
  int j=e;

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

  quickSort(arr , s , p-1);
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
