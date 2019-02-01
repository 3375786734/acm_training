/*  -*- coding: utf-8 -*- */
#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define pb push_back
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> PP;
const int maxn =200 ;
int a[maxn],vis[maxn];
int n,k,ca,cb;
int Abs(int a){return a>0?a:-a;}
int cnt(int pos,int k)
{
	for(int i=pos;i<=n;i+=k){
		vis[i] =1;
		if(a[i]==-1)cb--;
		else ca--;
	}
	return Abs(ca-cb);
}
int main()
{
	int MM=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		if(a[i]==1)ca++;
		else cb++;
	int ta =ca,tb =cb;
	for(int i=1;i<=n;i++){
		if(vis[i] ==1) continue;
		int ans  = cnt(i,k);
		if(ans>MM)MM = ans;
		ca =ta ,cb =tb;
	}
	printf("%d\n",MM);
}

