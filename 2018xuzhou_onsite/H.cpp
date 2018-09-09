#include <bits/stdc++.h>
using namespace std;
int lowbit(int x){
	return x&(-x);
}
void add(int a,int x,int op){
	for(int i=x;i<=N;i+=lowbit(i))
		bit[op][i]+=x;
}
int sum(int r,int op){
	int ans=1;
	for(int i=r;i>0;i-=lowbit(i))
		ans+=bit[op][i];
	return ans;
}
void add()
int main()
{
	scanf("%d%d",&N,&Q);
	for(int i=1;i<=N;i++)scanf("%d",&a[i]);
	for(int i=1;i<=N;i++){
		add(i,);
	}
	for(int i=1;i<=Q;i++){
		int l,r,op;
		scanf("%d%d",&op,&l,&r);
		if(op==1){
			printf("%d\n",sum(r,1)-sum(l-1,1)-()*(sum(r,0)-sum(l,0)));
		}
		else {
			
		}
	}
}
