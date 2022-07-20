//https://www.codingninjas.com/codestudio/problems/maximum-frequency-number_920319?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int ,int>m;
    int maxF=0;
    int ans=0;
    
    for(int i=0;i<n;i++){
        m[arr[i]]++;
        maxF=max(maxF , m[arr[i]]);
    }
    
    for(int i=0;i<n;i++){
        if(maxF==m[arr[i]]){
            ans=arr[i];
            break;
        }
    }
    return ans;
}
