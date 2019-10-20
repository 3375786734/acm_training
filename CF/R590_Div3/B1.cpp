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
//const int maxn=;
//const double esp=1e-6
const int maxn = 2e5+100; 
int a[maxn],ans[maxn];
queue<int> buffer;
set<int> num;
int main()
{
	int N,K;
	int cnt = 0;
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++)
	  scanf("%d",&a[i]);

	for(int i =0;i<N;i++){
		if(num.count(a[i]) == 0){
			if(num.size() == K){
				num.erase(buffer.front());buffer.pop();
			}
			num.insert(a[i]);buffer.push(a[i]);
		}
	}
	while(!buffer.empty()){
	   	ans[cnt++] = buffer.front();buffer.pop();
	}
	printf("%d\n",cnt);
	for(int i = cnt-1;i>=0;i--)
	  printf("%d%c",ans[i],i==0?'\n':' ');
}

