#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
set<pair<int,pair<int,int>>> ss;
int main()
{
	ss.insert(mp(2,mp(1,3)));
	ss.insert(mp(1,mp(2,3)));
	printf("%d\n",ss.begin()->first);
}
