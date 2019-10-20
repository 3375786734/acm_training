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

const int maxn = 2e5+100;
int a[2][maxn];
int ok[2][maxn];

int main()
{
	int Q,N;
	scanf("%d",&Q);
	while(Q--){
		scanf("%d",&N);
		MEM(a,0);MEM(ok,0);
		char str[maxn];
		scanf("%s",str);
		for(int i=0;i<N;i++)
		  a[0][i] = str[i] -'0';
		scanf("%s",str);
		for(int i=0;i<N;i++)
		  a[1][i] = str[i] - '0';
		
		if(a[0][0]<3 )ok[0][0] = 1;
		if((a[1][0]>=3 &&a[0][0]>=3))ok[1][0] = 1;
		for(int i=1;i<N;i++){
			if((ok[0][i-1] == ok[1][i-1]) && (ok[0][i-1] == 0))break;
			if(((ok[0][i-1] == 1) &&a[0][i] <3) || ((ok[1][i-1] ==1) && a[0][i]>=3 && a[1][i]>= 3)) ok[0][i] = 1;
			if(((ok[1][i-1] == 1) &&a[1][i]<3) || ((ok[0][i-1] == 1) && a[1][i]>=3 &&a[0][i] >=3)) ok[1][i] = 1;
		}
		printf("%s\n",(ok[1][N-1] == 1)?"YES":"NO");
	}
}

