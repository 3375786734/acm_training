#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn=1e6+100;
const int oo=1e9;
struct Eg{
	int u,v,w,c;
	bool operator<(const Eg &a)const {
		w<a.w;
	}
};
bool cmp(Eg a,Eg b)
{
	return a.w<b.w;
}
Eg e1[maxn],e2[maxn],tmp[maxn];
int fa[maxn],ans[maxn],c1,c2,c3,N,M;
int fd(int a)
{
	if(fa[a]==a)return fa[a];
	return fa[a]=fd(fa[a]);
}
void un(int a,int b)
{
	int ra=fd(a),rb=fd(b);
	if(ra==rb)return ;
	fa[ra]=rb;
}
void slove()
{
	int a1=0,a2=0,cnt=0;
	rep(i,1,N)fa[i]=i;
	c3=0;
	
	
	//here some edge in e2 also in e1 ,so it may get WA
	//for(int i=0;i<c2;i++)tmp[c3++]=e2[i];
	
	
	
	for(int i=0;i<c2;i++)if(e2[i].c==2)tmp[c3++]=e2[i];
	for(int i=0;i<c1;i++)
	{
		int ra=fd(e1[i].v),rb=fd(e1[i].u);
		if(ra!=rb){
			a1+=e1[i].w;cnt++;
			un(ra,rb);
		}
		else tmp[c3++]=e1[i];
	}
	if(cnt!=N-1)a1=oo;
	else{
		ans[N-1]=a1;
//		printf("now %d\n",a1);
		sort(tmp,tmp+c3,cmp);
		for(int i=0;i<=M-N;i++){
			ans[N+i]=tmp[i].w+a1;
			a1+=tmp[i].w;
//			printf("ans %d\n",ans[N+i]);
		}
	}

	rep(i,1,N)fa[i]=i;
	cnt=0;c3=0;
	for(int i=0;i<c1;i++)
		if(e1[i].c==0)tmp[c3++]=e1[i];

	for(int i=0;i<c2;i++)
	{
		int ra=fd(e2[i].v),rb=fd(e2[i].u);
		if(ra!=rb){
			a2+=e2[i].w;cnt++;
			un(ra,rb);
		}
		else tmp[c3++]=e2[i];
	}
	if(cnt!=N-1)a2=oo;
	//if we choose else here be careful that N...M can not be calculate
	else {
//		  printf("now %d\n",a2);
		  ans[N-1]=min(ans[N-1],a2);
          sort(tmp,tmp+c3,cmp);
          for(int i=0;i<=M-N;i++){
		      ans[N+i]=min(tmp[i].w+a2,ans[N+i]);
		  	  a2+=tmp[i].w;
//			  printf("now %d\n",tmp[i].w);
		  }
	}
}
int main()
{
	int T,cas=0;
//	freopen("t.in","r",stdin);
	scanf("%d",&T);
	int id[26];
	id['R'-'A']=0;id['G'-'A']=1;id['B'-'A']=2;
	while(T--)
	{
		c1=c2=0;
		scanf("%d%d",&N,&M);
		char str[20];
		int a,b,c;
		for(int i=1;i<=M;i++)ans[i]=oo;
		rep(i,1,M)
		{
			scanf("%d%d%d%s",&a,&b,&c,str);
			if(str[0]=='R'||str[0]=='G')e1[c1++]=(Eg){a,b,c,id[str[0]-'A']};
			if(str[0]=='B'||str[0]=='G')e2[c2++]=(Eg){a,b,c,id[str[0]-'A']};
		}
		sort(e1,e1+c1,cmp);
		sort(e2,e2+c2,cmp);
		/*
		for(int i=0;i<c2;i++)
			printf("now at%d %d %d\n",e2[i].v,e2[i].u,e2[i].w);
		*/
		printf("Case #%d:\n",++cas);
		slove();
		for(int i=1;i<=M;i++)
			if(i<N-1)printf("-1\n");
			else if(ans[i]==oo)printf("-1\n");
			else printf("%d\n",ans[i]);
	}
}
