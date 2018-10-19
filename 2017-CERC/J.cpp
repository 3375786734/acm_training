#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+100;
vector<int> vv[maxn];
int sz[maxn],fac[maxn],cnt,cc,ans[maxn],N,vvv[maxn];
int dfs(int now,int pre){
	sz[now]=1;
	for(int vi : vv[now]){
		if(vi==pre)continue;
		sz[now]+=dfs(vi,now);
	}
	vvv[sz[now]]++;
	return sz[now];
}
void get_fac(int n){
	fac[cnt++]=1;
	for(int i=2;i<n;i++)
		if(n%i==0){
			fac[cnt++]=i;
		}
}
bool check(int factor){
	int cccc=0;
	for(int i=factor;i<=N;i+=factor)
		cccc+=vvv[i];
	return cccc==N/factor;
	/*
	for(int i=factor;i<=N;i+=factor){
		int id=lower_bound(sz+1,sz+1+N,i)-sz;
		int id2=lower_bound(sz+1,sz+1+N,N-i-1)-sz;
		if(sz[id]!=i&&sz[id2]!=N-i-1)return false;
	}*/
	/*
	int id=lower_bound(sz+1,sz+1+N,factor)-sz;
	if(sz[id]==factor)	return true;
	else return false;
	*/
}
int main()
{
	scanf("%d",&N);
	int a,b;
	for(int i=1;i<N;i++){
		scanf("%d%d",&a,&b);
		vv[a].push_back(b);
		vv[b].push_back(a);
	}
	get_fac(N);
	/*
	for(int i=1;i<=N;i++)
		printf("sz%d\n",sz[i]);
	*/
	dfs(1,1);
	for(int i=0;i<cnt;i++)
		if(check(fac[i]))ans[cc++]=fac[i];
	sort(ans,ans+cc,[&](int a,int b){return a<b;});
	for(int i=cc-1;i>=0;i--)
		printf("%d%c",N/ans[i]-1,i==0?'\n':' ');

}
