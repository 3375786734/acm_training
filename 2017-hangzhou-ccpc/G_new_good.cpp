/*  -*- coding: utf-8 -*- */
/*
 *注意这里MEM失效了,原因是..
 *注意一个有趣的条件  sum(a)<1e5 意味着这里可以使用启发式合并
 *

 *trick 启发式合并使用优先队列完成,使用每个母函数的size进行排序,同时size动态分配空间防止MLE
 */
#include <bits/stdc++.h>
#define MEM(a,num) (a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define pb push_back
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> PP;
const int maxn=1e5+100;
const int mod=998244353;
const double pi = acos(-1.0);
//const double esp=1e-6
ll a[maxn],b[maxn];
ll fac[maxn],inv[maxn],f[maxn];
int N;
class Cn{
	double re,im;
	Cn(double re=0,double im =0 ):re(re),im(im){}
	Cn operator + (const Cn &a)const{return Cn(re+a.re,im+a.im);}
	Cn operator - (const Cn &a)const{return Cn(re-a.re,im-a.im);}
	Cn operator * (const Cn &a)const{return Cn(re*a.re-im*a.im,re*a.im+im*a.re);}
};
struct Node{
	vecor<ll> para;
	bool operator< (const Node &a)const{
		return para.size()>a.para.size();
	}
};
Cn aa[maxn],bb[maxn],cc[maxn];
ll qpow(ll a,ll n){
	ll ans=1;
	while(n){
		if(n&1) ans = ans*a%mod;
		a = a*a%mod,n>>=1;
	}
	return ans;
}
void ntt(vector<Cn> *a,int len,int op)
{
	if(len<=1)return ;
	vector<Cn> A0(l);
	int sz=0;
	for(int i=0;i<len;i+=2){
		A0[sz] = a[i];A1[sz++] = a[i+1];
	}

	ntt(A0,len>>1,op);ntt(A1,len>>1,op);
	
	Cn e=Cn(cos(2*pi/len),op*sin(2*pi/len)),w=Cn(1,0);
	for(int i=0;i<len;i++,w=w*e)
		a[i] = A0[i%sz] + w*A1[i%sz];
}
void init()
{
	int maxx = 1e5+5;
	f[0] = f[1] = inv[0] = inv[1] =fac[0] =fac[1] =1;
	for(int i=2;i<=maxx;i++){
		fac[i] = fac[i-1]*i%mod;
		f[i] = (mod-mod/i)*f[mod/i]%mod;
		inv[i] = inv[i-1] *f[i]%mod;
	}
}
ll C(ll n,ll m){
	if(m>n)return 0;
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
vector<ll> solve()
{
	for(int i=1;i<=N;i++){
		int maxx = min(a[i],b[i])+1;
		Node tmp;
		tmp.para.resize(maxx);
		for(int k=0;k<maxx;k++)
			tmp.para.pb(C(a[i],k)*C(b[i],k)%mod*fac[k]);
		q.push(tmp);
	}
	while(!q.empty()){
		vector<Cn> a1 = q.top().para;q.pop();
		if(!q.empty()){
			vector<Cn> a2 = q.top().para;q.pop();
			Node tmp ;
			int sz= 1,l1=a2.size()+1,l2=a1.size()+1;
			while((l1+l2)>=sz)sz<<=1;
			ntt(a1.para,sz,1);ntt(a2.para,sz,1);
			for(int i=0;i<a2.para.size();i++){
				tmp.par()
			}
			q.push();
		}
		else return a1;
	}
}
int main()
{
	int T,cas=1;
	scanf("%d",&T);
	init();
	while(T--)
	{
		scanf("%d",&N);
		rep(i,0,N-1)
			scanf("%lld%lld",&a[i],&b[i]);
		Node ans = solve();
		ntt(ans.para,-1);
		for(auto num : ans.para){
			sum  += 
		}
		printf("Case #%d: %lld\n",cas++,((ans-res)/2+mod)%mod);
	}
}
