#include <bits/stdc++.h> 
using namespace std;

void solve(string str,int n,int idx,vector<string> &ans,string sub){
	if(idx >= n){
		if(sub.length() > 0)
			ans.push_back(sub);
		return;
	}
	// pick
	solve(str,n,idx+1,ans,sub + str[idx]);
	// not pick
	solve(str,n,idx+1,ans,sub);
}
vector<string> subsequences(string str){
	int n = str.length();
	vector<string> ans;
	int idx = 0;
	solve(str,n,idx,ans,"");
	return ans;
}
