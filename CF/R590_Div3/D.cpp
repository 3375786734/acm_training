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
//const double esp=1e-6
const int maxn =  1e5+100;
int bit[27][maxn];
char str[maxn];
int N,Q;
int lowbit(int a)
{return a&(-a);}
void add(int idx,int x,int y){
	for(int i=x;i<=N;i+=lowbit(i))
	bit[idx][i]+=y;
}
int get_sum(int idx,int x){
	int ans=0;
	for(int i=x;i>0;i-=lowbit(i))ans+=bit[idx][i];
	return ans;
}
int main()
{
	char str[maxn];
	scanf("%s",str);N = strlen(str);
	for(int i= 0;i<N;i++)
	  add(str[i]-'a',i+1,1);
	scanf("%d",&Q);
	while(Q--){
		int op;
		scanf("%d",&op);
		if(op == 1){
			int pos;
			char c[2];
			scanf("%d",&pos);
			scanf("%s",c);
			add(c[0]-'a',pos,1);
			add(str[pos-1]-'a',pos,-1);
			str[pos-1] = c[0];
		}
		else{
			int cnt= 0;
			int l,r;
			scanf("%d%d",&l,&r);
			for(int i = 0;i<26;i++)
			  if(get_sum(i,r)-get_sum(i,l-1) >0)cnt++;
			printf("%d\n",cnt);
		}
	}
}

