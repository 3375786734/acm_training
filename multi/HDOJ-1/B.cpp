/*注意到:真正关键的不是str的形式,而是其中包含的(的个数a  )的个数b
 */
#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn=1e5+100;
int N;
char str[maxn];
char ss[maxn];
struct Node{
		int l,r;
};
Node nn[maxn];
bool cmp(Node a,Node b){
	if(a.r>a.l&&b.r<=b.l)
		return false;
	else if(a.r>a.l&&b.r>b.l)
		return a.r<b.r;
	else if(a.r<=a.l&&b.r<=b.l)
		return a.l>b.l;
	else 
		return true;
}
void slove()
{
	scanf("%d",&N);
	int ans=0;MEM(nn,0);
	rep(i,1,N){
		scanf("%s",str);
		int len=strlen(str);
		int top=0,base=0;
		MEM(ss,0);
		for(int j=0;j<len;j++){
			if(top>base&&ss[top-1]=='('&&str[i]==')')
				top--;
			else ss[top++]=str[i];
		}
		while(top>base){
			if(ss[top-1]=='(')nn[i].l++;
			else nn[i].r++;
		}
		ans+=len-nn[i].r-nn[i].l;
	}
	sort(nn+1,nn+1+N,cmp);
	int rl=0,rr=0;
	rep(i,1,N){
		ans+=min(rl,nn[i].r);
		rl=max(rl-nn[i].r,0);
		rl+=nn[i].l;
	}
	printf("%d\n",ans);
}
int main()
{
	int T;
	freopen("t.in","r",stdin);
	scanf("%d",&T);
	while(T--){
		slove();
	}
}
