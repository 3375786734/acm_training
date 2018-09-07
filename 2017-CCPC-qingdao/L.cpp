#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		char s[100005];
		scanf("%s",s+1);
		int l=0,r=0;
		for(int i=2;i<n;i++){
			if(i<=m&&s[i]=='R')l++;
			if(i>=m&&s[i]=='L')r++;
		}
		printf("%d\n",min(l,r));
	}
	return 0;
}
