//https://leetcode.com/problems/k-th-symbol-in-grammar/
class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1){
            return 0;
        }
        
        int parent;
        
        if(k&1){    //odd case
            parent = kthGrammar(n-1 , (k/2)+1);
        }
        else{
            parent = kthGrammar(n-1 , (k/2));
        }
        
        if(parent==0){
            if(k&1){
                return 0;
            }
            else{
                return 1;
            }
        }
        else{
            if(k&1){
                return 1;
            }
            else{
                return 0;
            }
        }
    }
};
