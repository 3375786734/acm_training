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
const int maxn=1e5+100;
const int mod=  998244353;
const double pi = acos(-1.0);
//const double esp=1e-6
struct Cn{
	double im,re;
	Cn(double re=0,double im=0):re(re),im(im){}
	Cn operator+(const Cn&a)const{return Cn(re+a.re,im+a.im);}
	Cn operator-(const Cn&a)const{return Cn(re-a.re,im-a.im);}
	Cn operator*(const Cn&a)const{return Cn(re*a.re-im*a.im,re*a.im+im*a.re);}
};
typedef vector<Cn> VV;
VV vv[maxn];
ll fac[maxn],f[maxn],inv[maxn];
ll a[maxn],b[maxn];
int N;
struct Node{
	VV vv;
	bool operator<(const Node &a) const{
		return vv.size()> a.vv.size();
	}	
};
ll qpow(ll a,ll n){
	ll ans=1;
	while(n){
		if(n&1)ans = ans*a%mod;
		a = a*a %mod  , n>>=1;
	}
	return ans;
}
void init()
{
	int maxx = maxn-5;
	printf("here\n");
	f[0] = f[1] =fac[0] =fac[1] =inv[0] = inv[1] =1;
	for(int i=2;i<=maxx;i++){
		fac[i]=fac[i-1]*i%mod;
		//计算逆元
		f[i]=(mod-mod/i)*f[mod%i]%mod;
		//计算阶乘的逆元
		inv[i]=inv[i-1]*f[i]%mod;
	}
}
ll C(ll n,ll m){
	if(m>n)return 0;
	return fac[n]*inv[m]%mod*inv[n-m];
}
void ntt(VV &a,int len,int op)
{
	if(len<=1)return;
	VV A0,A1;
	int sz = (len>>1);
	for(int i=0;i<len;i+=2){
		A0.pb(a[i]);A1.pb(a[i+1]);
	}
	Cn e=Cn(cos(2*pi/len),sin(2*pi/len)) , w = Cn(1,0);
	for(int i=0;i<len;i++,w=w*e)
		a[i] = A0[i%sz] + w*A1[i%sz];
}
VV solve()
{
	priority_queue<Node> q;
	for(int i=1;i<=N;i++){
		int len =min(a[i],b[i])+1;
		Node tmp ;
		tmp.vv.resize(len);
		for(int k =0;k<len;k++)
			tmp.vv[k] = Cn(C(a[i],k)*C(b[i],k)%mod*fac[k]%mod,0);
		q.push(tmp);
	}
	printf("here\n");
	while(!q.empty())
	{
		VV now = q.top().vv;q.pop();
		if(!q.empty()){
			VV nxt = q.top().vv; q.pop();
			int len =1,l1 = now.size()+1,l2 =nxt.size()+1;
			while((l1+l2)>=len) len<<=1;
			now.resize(len);nxt.resize(len);
			ntt(now,len,1);ntt(nxt,len,1);
			Node tmp;
			tmp.vv.resize(len);
			for(int i=0;i<len;i++)
				tmp.vv[i] = nxt[i] *now[i];
			printf("here\n");
			q.push(tmp);
		}
		else{
			printf("here at\n");
			ntt(now,now.size(),-1);
			for(auto vi :now)
				printf("%d\n",(int)(vi.re/4+0.5));
			return now;
		}
	}
}
int main()
{
	int T,cas=1;
	freopen("t.in","r",stdin);
	scanf("%d",&T);
	init();
	while(T--)
	{
		scanf("%d",&N);
		rep(i,1,N)scanf("%lld%lld",&a[i],&b[i]);
		VV ans = solve();
		ll sum= 0;
		int len = ans.size();
		for(int i=0;i<len;i++){
			ll vvv = (ll)(ans[i].re/len+0.5);
			if(i%2==0)sum = (sum+vvv*fac[N-i]%mod)%mod;
			else sum = (sum - vvv*fac[N-i]%mod+mod )%mod;
		}
		printf("Case #%d: %lld\n",cas++,sum);
	}
}

