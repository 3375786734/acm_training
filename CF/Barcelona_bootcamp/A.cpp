#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long ll;

int main()
{
	int N,cnt=0;
	char str[1000];
	scanf("%d",&N);
	scanf("%s",str);
	for(int i=0;i<N;i++)
		if(str[i]=='8')cnt++;
	if(cnt*10<=N-cnt)printf("%d\n",cnt);
	else printf("%d\n",N/11);
}
