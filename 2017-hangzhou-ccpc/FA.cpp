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
const int maxn=1e3+100;
const int maxc=300;
//const double esp=1e-6
int tf[maxn][maxc];
void get_TF(char *pat)
{
	 int len = strlen(pat),lsp=0;
	 MEM(tf[0],0);//惰性更新,防止爆内存,超时
	 tf[0][pat[0]]=1;
	 for(int i=1;i<len;i++){
		for(int  j =0;j<maxc;j++)
			tf[i][j] = tf[lsp][j];

		tf[i][pat[i]] = i+1;
		//更新失配指针,最后一个字符没有失配指针
		if(i<len-1)lsp = tf[lsp][pat[i]];
	 }
}
void match(char *pat,char *txt)
{
	int len =strlen(txt),ps=0;
	int end = strlen(pat)-1;
	for(int i=0;i<len;i++)
	{
	   	ps = tf[ps][txt[id]];
		if(ps==end)printf("get it at ps %d\n",ps);
	}
}
int main()
{
	char pat[10] = "GEEK";
	char txt[1000]= "GEEKS FOR GEEKS";
	get_TF(pat);
	match(pat,txt);
}

