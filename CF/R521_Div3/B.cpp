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
const int maxn= 1e5;
int a[maxn];
int main()
{
	int N,cnt=0,flag = 0;
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=N-2;i++){
		if(flag == 0&&a[i]==1&&a[i+1]==0&&a[i+2]==1){
			i++;
			flag =1;
			cnt++;
		}
		else if(flag == 1&&a[i]==1&&a[i+1]==0&&a[i+2]==1){
			flag = 0;
			i++;
		}
		else if(flag == 1){
			flag = 0;
		}
	}
	printf("%d\n",cnt);
}

