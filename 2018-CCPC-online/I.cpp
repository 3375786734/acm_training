/*问题的关键是求任意两点之间的树上路径长度和即可.
 * ans=L*2*(n-1)!
 *
 */
#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dep(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int mod=1e9+7;
const int N=1e5+200;
typedef long long ll;
struct node {
    int v, l;
    node() {};
    node(int _v, int _l): v(_v), l(_l) {};
};
vector<node> g[N];
int n, k, size, s[N], f[N], root, d[N], K;
ll ans,fac[N];
vector<ll> dep;
bool done[N];
void getroot(int now, int fa) {
    int u;
    s[now] = 1; f[now] = 0;
    for (int i=0; i<g[now].size(); i++)
        if ((u = g[now][i].v) != fa && !done[u]) {
            getroot(u, now);
            s[now] += s[u];
            f[now] = max(f[now], s[u]);
        }
    f[now] = max(f[now], size-s[now]);
    if (f[now] < f[root]) root = now;
}
void getdep(int now, int fa) {
    int u;
    dep.push_back(d[now]);
    s[now] = 1;
    for (int i=0; i<g[now].size(); i++)
        if ((u = g[now][i].v) != fa && !done[u]) {
            d[u] = d[now] + g[now][i].l;
            getdep(u, now);
            s[now] += s[u];
        }
}
int calc(int now, int init) {
//	printf("now at %d\n",now);
    dep.clear(); d[now] = init;
    getdep(now, 0);
//	printf("now at %d\n",now);
//  sort(dep.begin(), dep.end());
    ll ret = 0;
    for (int l=0, r=dep.size()-1; l<r; ){
		if(dep[l]+dep[r] <= 1e9+10) {ret +=dep[l]+dep[r];l++;}
		else r--;
		printf("dep %lld %lld\n",dep[l],dep[r]);
//        ret=(ret+dep[l]+dep[r])%mod;
	}
	printf("now at %d %lld\n",now,ret);
	return ret%mod;
}
void work(int now) {
    int u;
	ans =(ans+ calc(now, 0))%mod;
    done[now] = true;
//	printf("now %d\n",now);
    for (int i=0; i<g[now].size(); i++){
//		printf("here\n");
		if (!done[u = g[now][i].v]) {
//			printf("now at%d\n",i);
            ans -= calc(u, g[now][i].l);
			ans=(ans+mod)%mod;
			f[0] = size = s[u];
            getroot(u, root=0);
            work(root);
        }
	}
}
int main()
{
	int T;
	freopen("t.in","r",stdin);
	while(~scanf("%d",&n)){
	fac[0]=1;
	for(int i=1;i<=1e5+100;i++)fac[i]=(1ll*fac[i-1]*i)%mod;
		k=1e9+10;
		int a,b,c;
        for (int i=0; i<=n; i++) g[i].clear();
        memset(done, false, sizeof(done));
        int u, v, l;
        for (int i=1; i<n; i++) {
            scanf("%d%d%d", &u, &v, &l);
            g[u].push_back(node(v, l));
            g[v].push_back(node(u, l));
        }
		f[0] = size = n;
        getroot(1, root=0);
        ans = 0;
//      printf("here %d\n",root);
		work(root);
        printf("%lld\n",ans%mod);
	}
}
