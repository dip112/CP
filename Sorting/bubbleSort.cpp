#include<bits/stdc++.h>
using namespace std;
//in ith round we placed ith largest element in its proper place
void bubbleSort(int *a , int n){
  for(int i=1;i<n;i++){
    bool isSwapped=false;
    for(int j=0;j<n-i;j++){
      if(a[j]>a[j+1]){
        swap(a[j] , a[j+1]);
        isSwapped=true;
      }
    }
    if(isSwapped==false){
      break;
    }
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

  bubbleSort(a , n);

  cout<<"After sorting"<<endl;
  for(int i=0;i<n;i++){
    cout<<a[i]<<", ";
  }cout<<endl;

  return 0;
}
//Time: O(n^2)
