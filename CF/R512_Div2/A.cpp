#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn=2e5;
int l[maxn],r[maxn];
int main()
{
	int N,L,a;
	scanf("%d%d%d",&N,&L,&a);	
	int b;
	rep(i,1,N){
		scanf("%d%d",&l[i],&b);
		r[i]=l[i]+b;
	}
	int cnt=0;
	rep(i,0,N-1){
		int tmp=r[i];
		while(tmp+a<=l[i+1]&&tmp+a<=L){
			cnt++;
			tmp+=a;
		}
	}
	int tmp=r[N];
	while(tmp+a<=L){
		cnt++;
		tmp+=a;
	}
	printf("%d\n",cnt);
}
