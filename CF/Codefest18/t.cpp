#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> PP;
set<PP> ss;
int main()
{
	ss.insert(PP(1,2));
	ss.insert(PP(3,2));
	ss.insert(PP(2,1));
	for(set<PP>::iterator it=ss.begin();it!=ss.end();it++)
		printf("%d %d \n",it->first,it->second);
}
