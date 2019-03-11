/*  -*- coding: utf-8 -*- */
/*
 *IDEA: why don't you consider a case such that m is a function of n,and n*m+1 can be factorize?
  This is m = n-2
 */
#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define pb push_back
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> PP;
const int maxn =1010;

int main()
{
	int N;
	scanf("%d",&N);
	if(N==1)printf("8\n");
	else if(N==2)printf("4\n");
	else printf("%d\n",N-2);

}

