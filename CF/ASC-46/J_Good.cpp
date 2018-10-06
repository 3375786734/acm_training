/*
 *solutin1:brute force  .enumerate the alphabet
 *十分精妙的暴力方法:固定右端点,那么左边由于形成的字母集最大是26,我们考虑离散化.每个字母中,离当前第一个不相同的字母之间的距离即我们需要求的距离,即pos[alpha].注意到我们对26个字母进行状态压缩的话数组存不下,可以使用hash映射一下即可.hash的容量注意到每个元素位置最多可以产生26种新的状态,因此最多26*1e5种.
 *
 *solution2:RMQ+二分
 */
#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
using namespace std;
const int maxn=3e6;
typedef long long ll;
struct Node{
	int pos,id;	
};
bool cmp(Node a,Node b){
	return a.pos<b.pos;
}
Node cc[50];
map<int,int> mm;
int ps[50],vis[50];
ll ans[maxn];
int slen[maxn];
int main()
{
	freopen("jingles.in","r",stdin);
	freopen("jingles.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		mm.clear();
		memset(vis,0,sizeof(vis));
		char str[maxn];
		int hval=0;
		
		scanf("%s",str);
		int len=strlen(str);
		
		for(int i=0;i<=len*26;i++)slen[i]=0;

		for(int i=0;i<len;i++)
		{
			int num = str[i]-'a'+1,sz=0;
			ps[num] = i;vis[num]=1;
			cc[sz++] = (Node){-1,-1};
			for(int j = 1;j <= 26;j++)if(vis[j])cc[sz++] = (Node){ps[j],j};
			sort(cc,cc+sz,cmp);
			int state = (1<<num);
			for(int j = sz-1;j >= 1;j--){
				int c = cc[j].id;
				state |= (1<<c);
				if(!mm.count(state))mm[state] = hval++;
				int iid = mm[state],anum=__builtin_popcount(state);
				slen[iid] = max(slen[iid],i-cc[j-1].pos);
				ans[iid] = 1ll*slen[iid]*anum;
				//printf("i %d slen %d anum %d cc[%d]: %d id %d\n",i,slen[iid],anum,j,cc[j].pos,cc[j-1].id);
			}
		}
		ll sum=0;
		for(auto u:mm)
			sum+=ans[u.second];
		printf("%d %lld\n",hval,sum);
	}
}
