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
const int maxn =1e5+100;
int a[maxn];
int N;
int main()
{
	scanf("%d",&N);
	rep(i,1,N){
		scanf("%d",&a[i]);
	}
	printf("%d\n",N+1);
	printf("%d %d %d\n",2,N,1);
	printf("%d %d %d\n",1,N,N+1);
	int flag =1;
		for(int i=N-1;i>=1;i--){
			if(a[i]!=0||flag ==0)printf("%d %d %d\n",2,i,i);
			else {
				printf("%d %d %d\n",1,i,i);
				flag =0;
			}
		}	
}
