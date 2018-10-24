#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
using namespace std;
const int maxn=100;
struct P{
	int x,y;
};
bool cmp(P &a,P &b){
	return a.x>b.x;
}
int main()
{
	P p[5];
	p[0] = (P){2,2};
	p[1] = (P){1,1};
	sort(p,p+2,cmp);//[&](P a,P b){return a.x<b.x;});
	printf("%d %d\n",p[0].x,p[1].x);
}
