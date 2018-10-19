#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> vv;
	vv.push_back(1);
	vv.push_back(2);
	for(auto vi:vv)
		cout<<vi<<endl;
	vv.pop_back();
	for(auto vi:vv)
		cout<<vi<<endl;
}
