#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef vector<int >::iterator VI;
typedef set<int>::iterator SI;


int main()
{
	int n,m,a[1000];
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",&a[i]);
	int MM=0,res=0,ans=0;
	rep(i,1,n)
		MM=max(a[i],MM);
	rep(i,1,n)res+=MM-a[i];
	if(res>=m)ans=MM;
	else{
		if((m-res)/n*n==(m-res))ans=MM+(m-res)/n;
		else ans=MM+(m-res)/n+1;
	}
	printf("%d %d\n",ans,MM+m);
}
