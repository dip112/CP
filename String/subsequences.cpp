//https://www.codingninjas.com/codestudio/problems/subsequences-of-string_985087?leftPanelTab=0
void solve(string str , string output , int index , vector<string>&ans)
{
    if(index==str.size()){
        if(output.size()>0)
            ans.push_back(output);
        return;
    }
    //include
    solve(str, output+str[index], index+1, ans);
    //exclude
    solve(str, output, index+1, ans);
}

vector<string> subsequences(string str)
{
	vector<string>ans;
    string output="";
    int index=0;
    
    solve(str , output , index , ans);
    return ans;
}
