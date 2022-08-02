//https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
//approach1
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n=matrix.size();
        
        vector<int>temp(n*n);
        int index=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp[index++]=(matrix[i][j]);
            }
        }
        
        sort(temp.begin() , temp.end());
        
        return temp[k-1];
    }
};
//Time: O(nlogn)
//Space: O(n^2)

//approach2
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int>pq;
        
        for(auto row:matrix){
            for(auto col:row){
                
                pq.push(col);
                
                if(pq.size()>k){
                    pq.pop();
                }
            }
        }
        return pq.top();
    }
};
//Time: O(nlogk)
//Space: O(k)
