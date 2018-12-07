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

int main()
{
	int N;
	scanf("%d",&N);
	int ans =-1,flag= 0;
	for(int i=1;i<=N;i++){
		for(int j=i;j<=N;j++){
			if(j%i==0&&(i*j)>N&&(j/i<N)){
				printf("%d %d\n",j,i);
				flag =1;
				break;
			}
		}
		if(flag == 1)break;
	}
	if(flag == 0)printf("-1\n");
}

