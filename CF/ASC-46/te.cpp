#include <bits/stdc++.h>
using namespace std;

int main()
{
	printf("%d\n",__builtin_popcount(3));
	map<int,int> mm;
	vector<int> vv;
	mm[2]=1;mm[1]=2;
	vv.push_back(1);vv.push_back(2);
	for(auto u:mm){
		printf("%d\n",u.first);
	}
	for(auto v:vv)
		printf("%d\n",v);
}
