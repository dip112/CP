//https://leetcode.com/contest/biweekly-contest-73/problems/most-frequent-number-following-key-in-an-array/
#include<iostream>
#include<vector>
#include<map>
using namespace std;
int mostFrequent(vector<int>& nums, int key)
{
  map<int , int>m;
  vector<pair<int , int>>v;
  for(int i=0;i<nums.size()-1;i++)
  {
    v.push_back( make_pair(nums[i],nums[i+1]) );
  }
  int target=INT_MIN;
  for(int i=0;i<v.size();i++)
  {
    if(v[i].first==key)
    {
      m[v[i].second]++;
    }
  }
  int res=0;
	for(auto it:m)
  {
		if(target==INT_MIN)
    {
			target = it.second;
      res=it.first;
			continue;
		}
	  if(it.second>=target)
    {
			target = it.second;
      res=it.first;
		}
	 }
   return res;
}
int main()
{
  vector<int>v;
  int key;
  cin>>key;
  v.push_back(2);
  v.push_back(2);
  v.push_back(2);
  v.push_back(2);
  v.push_back(3);
  cout<<"result "<<mostFrequent(v , key)<<endl;
  return 0;
}
