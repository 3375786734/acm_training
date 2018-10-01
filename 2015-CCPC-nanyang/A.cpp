#include <bits/stdc++.h>
using namespace std;
int t[4][4]={{0,1,2,3},{2,0,3,1},{3,2,1,0},{1,3,0,2}};
int main()
{
	int T,cas=1;
	scanf("%d",&T);
	while(T--)
	{
		int a[5],b[5];
		for(int i=0;i<4;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<4;i++)
			scanf("%d",&b[i]);
		int ok=0;
		for(int i=0;i<4;i++){
			int flag=1;
			for(int j=0;j<4;j++)
				if(a[t[i][j]]!=b[j]){
					flag=0;
					break;
				}
			if(flag==1){
				ok=1;
				break;
			}
		}
		printf("Case #%d: %s\n",cas++,ok==1?"POSSIBLE":"IMPOSSIBLE");
	}
}
