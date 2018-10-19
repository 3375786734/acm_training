#include<bits/stdc++.h>
using namespace std;
int a[3000],b[3000];
int main(){
	int n,m,l1,r1,l2,r2,s1,k,s2,ans;
	freopen("t.in","r",stdin);
	while(~scanf("%d%d",&n,&m)){
	ans=0;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),a[i]+=a[i-1];
	for(int i=1;i<=m;i++) scanf("%d",&b[i]);
	scanf("%d",&k),s1=a[1];
	for(int i=1;i<=n;i++){
		s1=1e9;
		for(int j=1;j<=n-i+1;j++) s1=min(s1,a[j+i-1]-a[j-1]);
		l2=r2=1,s2=b[1];
		while(r2<=m){
			if((long long)s1*s2<=k) ans=max(ans,i*(r2-l2+1)),s2+=b[++r2];
			else s2-=b[l2++];
		}
	}
	printf("%d",ans);
	}
}
