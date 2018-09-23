#include <bits/stdc++.h>
using namespace std;
//const int maxn=;
int n,d;
bool on(double x,double y,double k,double b){
	if(y>=k*x+b)return true;
	else return false;
}
bool down(double x,double y,double k,double b){
	if(y<=k*x+b)return true;
	else return false;
}
int main()
{
	int M;
	scanf("%d%d",&n,&d);
	scanf("%d",&M);
	int a,b;
	for(int i=1;i<=M;i++){
		scanf("%d%d",&a,&b);
		if(on(a,b,-1,d)&&on(a,b,1,-d)&&down(a,b,1,d)&&down(a,b,-1,2*n-d))printf("YES\n");
		else printf("NO\n");
	}
}
