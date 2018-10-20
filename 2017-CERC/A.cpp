#include <bits/stdc++.h>
using namespace std;
const int maxn = ;
struct Node{
	int x,y;
}
Node nn[maxn];
int main()
{
	scanf("%d%d",&r,&n);
	for(int i=1;i<=r+3;i++){
		scanf("%s",str);	
		for(int j=0;j<11;j++)
			if(str[i][j]=='-')nn[sz++]=(Node){j,i};
			
		if(i==1||i==r+3||i=r/2+2)continue;
	}
}
