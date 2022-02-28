class Solution {
public:
    bool judgeCircle(string moves) 
    {
        map<char , int>m;
        
        for(auto c:moves)
        {
            m[c]++;
        }
        if(m['U']==m['D'] && m['L']==m['R'])
            return 1;
        else
            return 0;
    }
};
