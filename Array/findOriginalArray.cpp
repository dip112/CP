//https://leetcode.com/problems/find-original-array-from-doubled-array/
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int>ans;
        
        int n=changed.size();
        if(n%2==1){
            return ans;
        }
        
        sort(changed.begin() , changed.end());
        unordered_map<int , int>m;
        
        for(int i=0;i<n;i++){
            m[changed[i]]++;
        }
        
        for(int i=0;i<n;i++){
            if(m[changed[i]]==0){
                continue;
            }
            if(m[changed[i]*2]==0){
                return {};
            }
            ans.push_back(changed[i]);
            m[changed[i]]--;
            m[changed[i]*2]--;
        }
        return ans;
    }
};
//Time: O(N*longN)
//Space: O(N)
