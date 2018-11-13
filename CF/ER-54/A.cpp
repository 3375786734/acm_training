/*  -*- coding: utf-8 -*- */
#include <bits/stdc++.h>
#define MEM(a,num) (a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define pb push_back
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> PP;
//const double esp=1e-6
const int maxn = 3e5;
char str[maxn];
int main()
{
	int N;
	scanf("%d",&N);
	scanf("%s",str);
	char Max = 'a'-1;
	int ps = -1;
	for(int i=0;i<N-1;i++){
		if(str[i]>str[i+1]){
			ps =i ;	
			break;
		}
	}
	if(ps == -1) ps = N-1 ;
	for(int i=0;i<N;i++)
		if(i!=ps)printf("%c",str[i]);
	printf("\n");
}

