#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long ll;
const int maxn=300;
int a[maxn][maxn],S[maxn],T[maxn],Lx[maxn],Ly[maxn],linker[maxn];
int slack[maxn],N;
bool match(int now){
//	printf("now at %d\n",now);
	S[now]=1;
	rep(i,1,N){
		int res=Lx[now]+Ly[i]-a[now][i];
		if(T[i]==1)continue;
		if(res==0){
			T[i]=1;
			if(linker[i]==-1||match(linker[i])){
				linker[i]=now;
				return true;
			}
		}
		else// if(!T[i])
			slack[i]=min(slack[i],res);
	}
	return false;
}
void input()
{
	scanf("%d",&N);
	rep(i,1,N)
		rep(j,1,N){
			scanf("%d",&a[i][j]);
//			a[i][j]=-a[i][j];
		}
}
void KM()
{
		//注意这里的初始化
		rep(i,1,N){
            Lx[i]=-1e9-10;Ly[i]=0;
            rep(j,1,N)Lx[i]=max(Lx[i],a[i][j]);
		}
//		printf("%d %d\n",Lx[1],Lx[2]);
		MEM(linker,-1);
        rep(i,1,N){
			MEM(slack,0x3f3f3f);
            while(1){
                MEM(S,0);MEM(T,0);
                if(match(i))break;
                int d=1e9+100;
                rep(j,1,N)
					if(!T[j])d=min(slack[j],d);
//				printf("d %d\n",d);
                rep(j,1,N){
                    if(S[j])Lx[j]-=d;
                    if(T[j])Ly[j]+=d;
                    else slack[j]-=d;
                }
            }
        }
}
void getans(int cas)
{
	 ll ans=0;
     rep(i,1,N)
         if(linker[i]!=-1)ans+=a[linker[i]][i];
     printf("Case #%d: %lld\n",cas,ans);
}
int main()
{
	int T,cas=0;
//	freopen("t.in","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		input();
		KM();
		getans(++cas);
	}
}
