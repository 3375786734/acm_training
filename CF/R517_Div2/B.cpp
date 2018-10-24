#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5;
int a[maxn],b[maxn],ans[maxn];
int N;
bool dfs(int now,int dep){
	if(dep>0)ans[dep]=now;
	if(dep==N)return 1;
	//printf("Yes %d\n",now);
	int ok=0;
	for(int i=0;i<4;i++){
		if((dep>0&&(((now&i)==b[dep])&&((now|i)==a[dep])))||dep==0)
			if(dfs(i,dep+1))return true;
	}
	return false;
}
int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N-1;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=N-1;i++)
		scanf("%d",&b[i]);
	int ok=dfs(0,0);
	if(ok==0)printf("No\n");
	else {
		printf("Yes\n");
		for(int i=1;i<=N;i++)
			printf("%d%c",ans[i],i==N?'\n':' ');
	}
}
