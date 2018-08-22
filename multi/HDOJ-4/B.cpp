#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn=1e5+10;
const int mod= 1000000007;
typedef long long ll;
ll mm[maxn],inv[maxn],nnn;
int Be[maxn],unit,MAX;
struct Mo{
	int l,r,id;
	ll ans;
};
bool cmp(Mo a,Mo b){
	Be[a.l]==Be[b.l]?a.r<b.r:a.l<b.l;
}
bool CMP(Mo a,Mo b){
	return a.id<b.id;
}
Mo q[maxn];
ll qpow(ll n,ll p)
{
	ll ans=1,base=n;
	while(p)
	{
		if(p&1)ans=ans*base%mod;
		n=1ll*base*base%mod;
		p>>=1;
	}
	return ans;
}
void init()
{
	mm[0]=1;
	for(int i=1;i<maxn;i++)
		mm[i]=(ll)(1ll*mm[i-1]*i)%mod;
	inv[maxn-1]=qpow(mm[maxn-1],mod-2);
	for(int i=maxn-2;i>=0;i--)
		inv[i]=(inv[i+1]*1ll*(i+1))%mod;
}
ll C(int n,int m){
//	if(n<m||n<=0||m<0)return 0;
//	if(m==0||n==m)return 1;
	return 1ll*mm[n]*inv[m]%mod*inv[n-m]%mod;
}
void revise(int cl,int cr,int op1,int op2)
{
	if(op2==0&&op1==1)
		nnn=(2*nnn%mod-C(cr-1,cl)+mod)%mod;
	if(op2==0&&op1==-1)
		nnn=inv[2]*(nnn+C(cr-1,cl))%mod;
	if(op2==1&&op1==1)
		nnn=(nnn-C(cr,cl)+mod)%mod;
	if(op2==1&&op1==-1)
		nnn=(nnn+C(cr,cl))%mod;
}
int main()
{
	int T;
	freopen("t.in","r",stdin);
	scanf("%d",&T);
	init();
	for(int i=1;i<=T;i++)
	{
		scanf("%d%d",&q[i].r,&q[i].l);q[i].id=i;
		MAX=max(MAX,q[i].r);
	}
	unit=sqrt(1.0*(maxn));
	for(int i=0;i<maxn;i++)Be[i]=i/unit+1;

	sort(q+1,q+T+1,cmp);
	int l=1,r=1;
	nnn=2;
	for(int i=1;i<=T;i++)
	{
		while(l<q[i].l)revise(++l,r,-1,1);
		while(l>q[i].l)revise(l--,r,1,1);
		while(r<q[i].r)revise(l,++r,1,0);
		while(r>q[i].r)revise(l,r--,-1,0);
		q[i].ans=nnn;
	}
	sort(q+1,q+T+1,CMP);
	for(int i=1;i<=T;i++)printf("%lld\n",q[i].ans);
}
