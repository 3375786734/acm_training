#include <bits/stdc++.h>
using namespace std;

int main()
{
	map<int,int> mm;
	mm[1]++;
	printf("%d\n",(mm.begin())->first);
	mm[1]--;
	auto mi = mm.begin();
	printf("%d %d %d\n",mi->first,mm.size(),mm[1]);
	mm.erase(1);
	printf("%d\n",mm.size());
}
