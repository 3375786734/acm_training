/*  -*- coding: utf-8 -*- */
/* exercise-1:
 * We need to write a program to generate the parse tree of string:
 * " the girl touches the boy with the flower "
 *
 * IDEA-1:brute force. top down  ,  bottum up.
 * 
 * exercise-2:
 * count how many string the CFG can genrate
 *
 */
#include <bits/stdc++.h>
#include <sstream>
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
string str;
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
	if(!str.empty())str.erase(0,str.find_first_not_of(" "));
	istringstream inn(str);
	while(inn>>tmp)
		vec.pb(tmp);
	for(string si:vec)cout<<si<<endl;
}
int main()
{
	freopen("t.in","r",stdin);
	getline(cin,str);
	init();
	string tmp;
	while(getline(cin,tmp)){
		cout<<tmp<<endl;
	}
}
