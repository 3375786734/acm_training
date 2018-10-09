#include <bits/stdc++.h>
using namespace std;

int main()
{
	scanf("%d%d%lld",&N,&L,&S);
	int ok=1;
	for(int i = 1; i <= N; i++){
		scanf("%d",&w[i]);
	}
	int p;
	for(int i = 2;i <= N; i++){
		scanf("%d",&p);
		v[p].push_back(i);
	}

	if(ok==0)printf("-1\n");
	else {
	}
}
