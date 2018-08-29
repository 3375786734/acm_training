#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dep(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
//const int maxn=;
/*
int gcd(int a,int b){
	if(a%b==0)return b;
	else return gcd(b,a%b);
}*/

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int p;
		scanf("%d",&p);
		/*
		for(int i=1;i<=p;i++){
			printf("%d",__gcd(i-1,0)%p);
			for(int j=2;j<=p;j++)
				printf(" %d",__gcd(i-1,j-1)%p);
			printf("\n");
		}
		for(int i=1;i<=p;i++){
			printf("%d",((__gcd((i-1),0)+1)%p));
			for(int j=2;j<=p;j++){
				printf(" %d",(__gcd(i-1,j-1)+1)%p);
			}
			printf("\n");
 		}
		*/
		for(int i=1;i<=p;i++){
//			printf("%d",(i-1+1-1)%p);
			for(int j=1;j<=p;j++)
				printf("%d%c",(i-1+j-1)%p,j==p?'\n':' ');
		}
		for(int i=1;i<=p;i++){
//			printf("%d",(i-1)*0%p);
			for(int j=1;j<=p;j++)
				printf("%d%c",((i-1)*(j-1))%p,j==p?'\n':' ');
		}
	}
}
