//https://practice.geeksforgeeks.org/problems/subsets-1587115621/1
//https://leetcode.com/problems/subsets-ii/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    void solve(vector<int>nums , vector<int>output , int index , set<vector<int>>&s , int n)
    {
        if(index>=n)
        {
            sort(output.begin() , output.end());
            s.insert(output);
            return ;
        }
        //exclude
        solve(nums , output , index+1 , s , n);
        //include
        output.push_back(nums[index]);
        solve(nums , output , index+1 , s , n);
    }
    public:
    //Function to find all possible unique subsets.
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        vector<vector<int>>ans;
        vector<int>output;
        set<vector<int>>s;
        int index=0;
        solve(arr , output , index , s , n);
        for(auto it:s){
            ans.push_back(it);
        }
        return ans; 
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   



// } Driver Code Ends
