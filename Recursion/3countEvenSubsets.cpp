//https://practice.geeksforgeeks.org/problems/even-subsets/1
//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

/*Function to count subset with even sum
* arr : array input
* N : size of array
*/
class Solution{
    void solve(int arr[] , int n , int &cnt , int i , int sum){
        if(i>=n){
            if(sum%2==0 && sum!=0){
                cnt++;
            }
            return;
        }
        solve(arr , n , cnt , i+1 , sum+arr[i]);
        solve(arr , n , cnt , i+1 , sum);
    }
  public:
    int countSumSubsets(int arr[], int N){
        
        int count=0;
        int sum=0;
        solve(arr , N , count , 0 , sum);
        return count;
    }
};

//{ Driver Code Starts.

// Driver code to test columnWithMaxZeros function
int main() {
	
	int testcase;
	
	cin >> testcase;
	
	while(testcase--){
	    int N;
	    cin >> N;
	    
	    int arr[N];
	    
	    // Taking elements input into the matrix
	    for(int i = 0;i<N;i++){
	            cin >> arr[i];
	        }
	    Solution obj;
	    cout << obj.countSumSubsets(arr, N) << endl;
	}
	
	return 0;
}
// } Driver Code Ends
