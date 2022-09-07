#include<bits/stdc++.h>
using namespace std;
//conqure
void merge(int a[] , int s , int mid , int e){
  int n1=mid-s+1;
  int n2=e-mid;

  int *a1=new int[n1];
  int *a2=new int[n2];

  int i=0;
  for(int index=s ; index<=mid ; index++){
    a1[i]=a[index];
    i++;
  }

  int j=0;
  for(int index=mid+1 ; index<=e ; index++){
    a2[j]=a[index];
    j++;
  }

  int index1=0;
  int index2=0;
  int index=s;

  while(index1 < n1 && index2 < n2){
    if(a1[index1] < a2[index2]){
      a[index]= a1[index1];
      index++;
      index1++;
    }
    else{
      a[index]=a2[index2];
      index++;
      index2++;
    }
  }

  while(index1<n1){
    a[index]=a1[index1];
    index++;
    index1++;
  }
  while(index2<n2){
    a[index]=a2[index2];
    index++;
    index2++;
  }

  delete [] a1;
  delete [] a2;
}

//divide
void mergeSort(int a[] , int s , int e){
  if(s>=e){
    return;
  }
  int mid=s+(e-s)/2;
  mergeSort(a , s , mid);
  mergeSort(a , mid+1 , e);
  merge(a , s , mid , e);
}

int main(){
  int a[]={12,8,4,36,9,2,7};
  int n=7;
  cout<<"Before sorting\n";
  for(int i=0;i<n;i++){
    cout<<a[i]<<", ";
  }cout<<endl;

  mergeSort(a , 0 , n-1);

  cout<<"After sorting\n";
  for(int i=0;i<n;i++){
    cout<<a[i]<<", ";
  }cout<<endl;

  return 0;
}
