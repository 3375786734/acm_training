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
const int maxn=1e6+100;
//const double esp=1e-6
char str[maxn];
double solve(char *str,int ps,int r)
{
	if(ps>=r)return 0;
	int pos = ps;
	double ans =0;
	if(str[ps]=='(')
}
int main()
{
	while(gets(str)&&strcmp(str,"()")){
		printf("%.2f",solve(str,0,strlen(str)));
	}
}
