//https://leetcode.com/problems/boats-to-save-people/
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
        int noOfBoat=0;
        
        sort(people.begin() , people.end());
        
        int i=0 , j=people.size()-1 ;
        
        while(i<=j)
        {
            if(people[i]+people[j]<=limit)
            {
                i++;
                j--;
            }
            
            else
            {
                j--;
            }
            
            noOfBoat++;
        }
        return noOfBoat;
    }
};
