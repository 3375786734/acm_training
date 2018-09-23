#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N,a,f=0;
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%d",&a);
		if(a==1)f=1;
	}
	printf("%s\n",f==1?"Hard":"Easy");
}
