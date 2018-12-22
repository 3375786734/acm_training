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
const int maxn = 20000;
int N;
string str[maxn];
struct Node{
	string ss;
	int id ;
	bool operator<(const Node &a)const{
		return ss.length()<a.ss.length();
	}
};
Node nn[maxn];
int main()
{
	scanf("%d",&N);
	N= 2*(N-1);
	for(int i=0;i<N;i++){
		cin>>str[i];
		nn[i] = (Node){str[i],i};
	}
	sort(nn,nn+N);
	int vis[maxn];
	MEM(vis,0);
	vis[nn[0].id] = 1;
	for(int i=0;i<N;i++){
		if(vis[nn[i].id]==0)continue;
		for(int j= i+1;j<N;j++)
			if(vis[nn[j].id]==0&&i!=j&&nn[j].ss.length()==nn[i].ss.length()+1){
				int ok = 1;
				for(int k =0;k<nn[i].ss.length();k++)
					if(nn[i].ss[k]!=nn[j].ss[k]){
						ok = 0;
						break;
					}
				if(ok  == 1){
					vis[nn[j].id]  = 1;
					break;
				}
			}
	}
	int sum = 0;
	for(int i=0;i<N;i++)
		sum+= vis[i];
	if(sum != N/2){
		printf("href\n");
		MEM(vis,0);
		vis[nn[1].id] = 1;
		for(int i=0;i<N;i++){
			if(vis[nn[i].id]==0)continue;
		for(int j= i+1;j<N;j++)
			if(vis[nn[j].id]==0&&i!=j&&nn[j].ss.length()==nn[i].ss.length()+1){
				int ok = 1;
				for(int k =0;k<nn[i].ss.length();k++)
					if(nn[i].ss[k]!=nn[j].ss[k]){
						ok = 0;
						break;
					}
				if(ok  == 1){
					vis[nn[j].id]  = 1;
					break;
				}
			}
	}
	}
	for(int i=0;i<N;i++)
		if(vis[i]==0)printf("S");
		else printf("P");
	printf("\n");
}

