#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dep(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef long long ll;
typedef vector<int> VV;
typedef pair<int,int> PP;
const int maxn=2e5+100;
int h[maxn];
int main()
{
	int N,K;
	scanf("%d%d",&N,&K);
	for(int i=1;i<=N;i++)
		scanf("%d",&h[i]);
	sort(h+1,h+1+N);
	int minx=h[1],maxh=h[N];
	int pos=N,ans=0;
	ll sum=0;
	while(pos>=1&&h[pos]>minx){
		sum=0;ans++;
		int pre=pos;
		while(pre>=1&&sum<=K){
			pos=pre;
			while(pre>=1&&h[pre]==h[pos])pre--;
			sum+=(N-pre)*(h[pos]-h[pre]);
		}
		//if(pos!=pre)pos--;
	}
	printf("%d\n",ans);
}
