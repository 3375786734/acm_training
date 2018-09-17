/*
 *题意:给一个算法生成图,现在要求通过最终的图,看是否能重构出算法的每一步取的点
 *算法步骤是:
     1.先划分联通快
	 2.从所有点中,取出一些点(或者不取为空),这些点要求没有任意两个属于同一个联通块的
	 3.新加入一个点,将这个点和S2取的点所在的联通块所在的点全部相连
 *
 *
 *idea:容易发现,若加入一个点P之后,他的度数是最大的,因为他和每个子联通块的每一个点都相连,删掉这个点后,性质保持,因为每个剩下的点公平的都度数-1;
 *remark:逆向操作减小了复杂度,因为我们删点和边都只有一次,复杂度O(M+N)
 */
#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define mp make_pair
using namespace std;
const int maxn=2e5+10;
typedef pair<int ,int > PP;
typedef set<PP>::iterator SI;
typedef vector<int>::iterator VI;
int fa[maxn],d[maxn],sz[maxn],N,M,vis[maxn];
set <PP> ss;
vector<int> v[maxn],ans[maxn];
int fd(int a){
	if(fa[a]==a)return fa[a];
	else return fd(fa[a]);
}
/*
void un(int a,int b){
	int ra=fd(a),rb=fd(b);
	if(ra==rb)return ;
}
*/
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		MEM(d,0);MEM(vis,0);
		scanf("%d%d",&N,&M);
		rep(i,1,N){
			fa[i]=i;
			sz[i]=1;
		}
		rep(i,1,N){
            v[i].clear();
            ans[i].clear();
        }
		ss.clear();
		int a,b;
		rep(i,1,M){
			scanf("%d%d",&a,&b);
			v[a].push_back(b);
			v[b].push_back(a);
			d[a]++;d[b]++;
		}
		rep(i,1,N)ss.insert(mp(d[i],i));
		int ok=1;
		//O(2*(M+N))
		for(SI si=ss.begin();si!=ss.end();si++){
			int id=si->second,cdeg=1;
			vis[id]=1;
			for(VI vi=v[id].begin();vi!=v[id].end();vi++){
				if(vis[*vi]==0)continue;
				int rt=fd(*vi);
				fa[rt]=id;
				cdeg++;
				//不能一个联通块重复计数,使用union set 维护
				if(rt==id)continue;
				ans[id].push_back(rt);
				sz[id]+=sz[rt];
			}
			if(cdeg!=sz[id])ok=0;
		}
		if(ok){
			printf("Yes\n");
			for(SI si=ss.begin();si!=ss.end();si++){
				int id=si->second;
				printf("%d %d",id,ans[id].size());
				for(VI vi= ans[id].begin();vi!=ans[id].end();vi++)
					printf(" %d",*vi);
				printf("\n");
			}
		}
		else printf("No\n");
	}
}
