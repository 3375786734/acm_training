/*  -*- coding: utf-8 -*- */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define pb push_back
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> PP;
//const double esp=1e-6
const int maxn = 1e5;
char str[maxn];
int now;
double get_num()
{
	int flag = 1,sz=0,tmp[maxn];
	double ans = 0;
	if(str[now]=='-')now++,flag=-1;
	while(str[now]>='0'&&str[now]<='9')
		tmp[sz++]  = str[now++]-'0';
	for(int i=0;i<sz;i++)
		ans += tmp[i]*pow(10,sz-1-i);
	if(str[now]=='.'){
		now++;sz = 0;
		while(str[now]>='0'&&str[now]<='9')
			tmp[sz++] = str[now++]-'0';
		for(int i = 0;i<sz;i++)
			ans += tmp[i]*pow(10,-i-1);
	}
	return ans*flag;
}
int gettoken(double &value)
{
	while(str[now] ==' ')now++;
	if(str[now]=='('){
		now++;
		return 0;
	}
	else if(str[now]==')'){
		now++;
		return 1;
	}
	else if((str[now]>='0'&&str[now]<='9')||str[now] == '-'||str[now]=='.'){
		value=get_num();
		return 2;
	}
}
//分析语法
double expr()
{
	double value = 0;
	int flag = gettoken(value);
	if(flag == 0){
		double p =0;
		gettoken(value);
		p = value;
		//printf("here %lf\n",p);
		double x = expr(); //这里是expr级的
		double y = expr();
		//printf("%lf %lf \n",x,y);
		gettoken(value);
		return p*(x+y)+(1-p)*(x-y);
	}
	else return value;
}
int main()
{
	while(fgets(str,sizeof(char)*maxn-1,stdin)){
		if(str[0]=='('&&str[1]==')')return 0;
		now = 0;
		printf("%.2lf\n",expr());
	}
}

