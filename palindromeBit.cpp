//question link: https://www.codingninjas.com/codestudio/problems/check-palindrome_920555?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_13
bool checkPalindrome(long long N)
{
	vector<int>v;
    while(N!=0)
    {
        if(N&1==1)
        {
            v.push_back(1);
        }
        else
            v.push_back(0);
        N=N>>1;
    }
    int i=0 , j=v.size()-1;
    while(i<j)
    {
        if(v[i]==v[j])
        {
            i++;
            j--;
        }
        else
        {
            return false;
        }
    }
    return true;
}
