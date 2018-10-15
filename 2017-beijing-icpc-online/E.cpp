#include <bits/stdc++.h>
using namespace std;
const int maxn=1005;
int a[maxn],vis[maxn];
int main()
{
	int N,M,X;
	while(~scanf("%d%d%d",&M,&N,&X)){
		int ans=0,q=0;
		for(int i=1;i<=N;i++)scanf("%d",&a[i]);
		sort(a+1,a+1+N);
		for(int i=0;i<X;i++){
			q=0;
			for(int j=1;j<=N;j++)
				if(i%a[j]==0){
					if(M>0){
						vis[j]=1;
						M--;
					}
					else vis[j]=0;
				}
		}
		for(int j=1;j<=N;j++)
			if(X%a[j]!=0&&vis[j])q++;
		printf("%d %d\n",M,q);
	}
}
