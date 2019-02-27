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
int x[3][2],f[2][2];
int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<3;i++)
		scanf("%d%d",&x[i][0],&x[i][1]);
	int ok =1;
	for(int i=0;i<2;i++){
		for(int j =1;j<=2;j++){
			if(x[0][i]<x[j][i])f[j][i] = 1;
			else if(x[0][i]>x[j][i])f[j][i]=0;
			else {
				ok = 0;
			}
		}
	}
	if(ok==1&&(!(f[1][0]^f[2][0]))&&(!(f[1][1]^f[2][1])))ok =1;
	else ok = 0;
	for(int i=-1;i<2;i++)
		for(int j=-1;j<2;j++)
			for(int k=1;k<=2;k++)
				if(x[0][0]+i==x[k][0]&&x[0][1]+j==x[k][1]){
					ok =0;
				}
	printf("%s",ok?"YES":"NO");
}
