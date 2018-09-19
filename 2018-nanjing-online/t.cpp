#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define mp make_pair
typedef map<int,int> MI;
typedef pair<int,int> PP;
typedef MI::iterator MII;
typedef long long LL;
MI lhall,rhall;
bool cmp(const PP &a,const PP &b,const PP &c)
{return (LL)(b.f-a.f)*(c.s-b.s)-(LL)(b.s-a.s)*(c.f-b.f)>=0;}
bool ask(MI &hh,const PP &pi)
{
	MII it=hh.lower_bound(pi.f);
	if(it==hh.end()){return false;}
	if(it->f==pi.f){return pi.s<=it->s;}
	if(it==hh.begin()){return false;}
	MII j=it--;
	return cmp(*it,pi,*j);
}

void add(MI &hh,const PP &pi)
{
	hh[pi.f]=pi.s;
	MII it=hh.lower_bound(pi.f),cur=it;
	if(it!=hh.end())
		for(MII ii=it++;it!=hh.end();ii=it++)
		{
			if(cmp(*ii,*it,pi))hh.erase(ii);
			else break;
		}
	it=cur;
	if(it!=hh.begin())
	{
		MII ii=--it;
		for(;ii!=hh.begin();)
		{
			it=ii--;
			if(cmp(*ii,*it,pi))hh.erase(it);
			else break;
		}
	}
}

int main()
{
//	freopen("t.in","r",stdin);
	int Q,a,b,c;
	scanf("%d",&Q);
	for(int i=0;i<Q;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		bool fl=ask(lhall,mp(b,c)),fr=ask(rhall,mp(b,-c));
		if(a==1)
		{
			if(!fl){add(lhall,mp(b,c));}
			if(!fr){add(rhall,mp(b,-c));}
		}
		else 
			printf("%s\n",fl&&fr?"YES":"NO");
	}
}
