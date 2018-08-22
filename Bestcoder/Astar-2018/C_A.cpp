#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+100;
int N,K;
char str[maxn];
//int cost[maxn][2],ps[maxn],len[maxn];
struct Node{
	int cost[2],ps,len;
	/*
	bool operator<(const Node &a)const{
		if(len!=a.len)len>a.len;
		else return cost[0]+cost[1]<a.cost[0]+a.cost[1];
	}*/
};
bool cmp(Node a,Node b)
{
	if(a.len!=b.len)return a.len>b.len;
	else return a.cost[0]+a.cost[1]<b.cost[0]+b.cost[1];
}
Node n[maxn];
int main()
{
	while(~scanf("%d%d",&N,&K))
	{
		memset(str,0,sizeof(str));
		scanf("%s",str);str[N]='0';
		char pre='0';
		int cnt=0;
		for(int i=0;i<=N;i++){
			if(pre=='0'&&str[i]=='1'){
				n[cnt].ps=i;
				n[cnt].cost[0]=1;
				if(i==0)n[cnt].cost[0]=0;
			}
			if(pre=='1'&&str[i]=='0'){
				n[cnt].len=i-n[cnt].ps;
				n[cnt++].cost[1]=1;
				if(i==N)n[cnt-1].cost[1]=0;
			}
			pre=str[i];
		}
		sort(n,n+cnt,cmp);

		int ans=0,flag=1,cc=0;
		for(int i=0;i<cnt;i++){
//			printf("%d %d %d %d\n",n[i].ps,n[i].len,n[i].cost[0],n[i].cost[1]);
			if(n[i].cost[0]+n[i].cost[1]+cc<K+1){
				ans+=n[i].len;
				cc+=n[i].cost[0]+n[i].cost[1];
			}
			else if(flag==1&&n[i].cost[0]+cc<K+1){
//				printf("current %d %d\n",cc,n[i].cost[0]);
				ans+=n[i].len;
				cc+=n[i].cost[0];
				flag==0;
			}
		}
		printf("%d\n",ans);
	}
}
