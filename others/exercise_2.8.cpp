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
class Parse{
public:
	
};
char str[maxn];
vector<string> vec,vv;
void slove()
{
	for(string vi:vv){
	}
}
void init()
{
	string tmp ;
	int sz=0;
	for(int i=0;i<strlen(str);i++){
		if(str[i] == ' '){
			vec.pb(tmp);
			tmp.clear();sz= 0;
		}
		else tmp[sz++] = str[i];
	}
	for(string si:vec)
		vv.pb(mm[si]);
}
int main()
{
	
	scanf("%s",str);
	init();
}
