#include <bits/stdc++.h>
using namespace std;

void dfs(int now,vector<int> &vv)
{
	vv.push_back(now);
	if(now==4)return;
	dfs(now+1,vv);
}
int main()
{
	vector<int> vv;
	dfs(1,vv);
	for(int vi : vv)
		printf("%d\n",vi);
}
