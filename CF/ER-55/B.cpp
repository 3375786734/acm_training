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
const int maxn = 1e5+100;
int l[maxn],r[maxn];
char str[maxn];
int main()
{
	int N;
	scanf("%d",&N);
		scanf("%s",str+1);
	int sz= 0,flag = 0;
	for(int i=1;i<=N;i++){
		if(str[i]=='G'&&flag==0){
			flag = 1;
			l[++sz] = i;
		}
		if(str[i]=='S'&&flag == 1){
			flag = 0;
			r[sz] = i;
		}
	}
	if(flag == 1)r[sz] = N+1;
	int ans = 0;
	if(sz >= 3){
		for(int i=2;i<=sz;i++)
			if(l[i]==r[i-1]+1)ans = max(ans,r[i]-l[i]+1+r[i-1]-l[i-1]);
	}
	else if(sz==1)ans = r[1] -l[1];
	else if(sz == 2){
		if(l[2]==r[1]+1)ans = r[2]-l[2]+r[1]-l[1];
		else ans = max(r[2]-l[2],r[1]-l[1]);
	}
	printf("%d\n",ans);
}

