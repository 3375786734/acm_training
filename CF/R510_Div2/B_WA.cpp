#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef vector<int >::iterator VI;
typedef set<int>::iterator SI;
const int maxn=10000;
const int inf=1e8;
int c[maxn];
set<int> ss[7];
bool in(char *str,char p){
	rep(i,0,1)
		if(str[i]==p)return true;
	return false;
}
int main()
{
	int N;
	char str[10];
	scanf("%d",&N);
	rep(i,0,6)ss[i].insert(inf);
	rep(i,1,N){
		scanf("%d%s",&c[i],str);
		int len=strlen(str);
		if(len==1)
			ss[str[0]-'A'].insert(c[i]);
		if(len==2){
			if(in(str,'A')&&in(str,'B'))ss[3].insert(c[i]);
			if(in(str,'A')&&in(str,'C'))ss[4].insert(c[i]);
			if(in(str,'B')&&in(str,'C'))ss[5].insert(c[i]);
		}
		if(len==3)ss[6].insert(c[i]);
	}
	int n1=*ss[3].begin(),n2=*ss[4].begin(),n3=*ss[5].begin(),ans=0;
	rep(i,0,2) ans+=*ss[i].begin();
	ans=min(ans,*ss[6].begin());
	ans=min(ans,n1+n2);
	ans=min(ans,n1+n3);
	ans=min(ans,n2+n3);
	ans=min(ans,n1+*ss[2].begin());
	ans=min(ans,n2+*ss[1].begin());
	ans=min(ans,n3+*ss[0].begin());
	if(0<=ans&&ans<inf)printf("%d\n",ans);
	else printf("-1\n");
}
