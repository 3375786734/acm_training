#include<bits/stdc++.h>

using namespace std;

const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;

#define LL long long
#define IN freopen("jingles.in", "r", stdin)
#define OUT freopen("jingles.out", "w", stdout)
#define scan(x) scanf("%d", &x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))
#define fi first
#define se second
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;

int T,mod=4000007;
char s[100005];
int h[4000008];
int a[27],v[27];
LL ans[4000008];
int fl[4000008],nu[4000008],pos[27];
int n;
pii c[27];
int fk[4000008],cc;

int has(int x)
{
    int now=x%mod;
    while(h[now]!=x && fl[now]==T+1)now=(now+1)%mod;
    h[now]=x;
    if(fl[now]!=T+1)
    {
        nu[now]=0;ans[now]=0;
        fk[++cc]=now;
        fl[now]=T+1;
    }
    return now;
}

int main()
{
    //IN;OUT;
    scanf("%d",&T);
    c[0]=mp(0,0);
    while(T--)
    {
        scanf("%s",s+1);
        n=strlen(s+1);
        cc=0;
        for(int i=1;i<=26;i++)v[i]=rand()%1000+1,pos[i]=0;
        for(int i=1;i<=n;i++)
        {
            int x=s[i]-96;
            pos[x]=i;
            for(int i=1;i<=26;i++)c[i]=mp(pos[i],i);
            sort(c+1,c+27);
            int now=0;
            for(int j=26;j>=1;j--)
            {
                if(c[j].fi<=0)break;
                now|=1<<(c[j].se-1);
                int u=has(now);
                nu[u]=max(nu[u],i-c[j-1].fi);
				printf("now nu %d \n",nu[u]);
                ans[u]=1ll*nu[u]*(26-j+1);
				printf("ans %d \n",ans[u]);
            }
        }
        LL sum=0;
        for(int i=1;i<=cc;i++)sum+=ans[fk[i]];
        printf("%d %lld\n",cc,sum);
    }
    return 0;
}
