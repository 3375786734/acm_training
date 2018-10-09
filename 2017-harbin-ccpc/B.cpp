#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef set<int> ::iterator SI;
const int maxn=1e5+100;
int a[maxn],N,M,K,sqe[maxn];

int main()
{
	int T;
	freopen("t.in","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		set<int >ss;
		int sz=0;
		scanf("%d%d%d",&N,&K,&M);
		for(int i=1;i<=N;i++)
			scanf("%d",&a[i]);
		int head=0,tail=0;
		ss.clear();
		for(int i=1;i<=K;i++)ss.insert(a[i]);
		int knum=0,cnt=1;
		for(int si :ss )knum=si;

		//printf("knum %d\n",knum);

		head=1,tail=K;
		for(int tail=K+1;tail<=N;tail++){
			if(a[tail] > knum){
				for(int i=0;i<=tail-head-K+1;i++)
					sqe[sz++] = knum;
			}
			else{
				ss.insert(a[tail]);
				SI si = ss.lower_bound(knum);si--;
				knum=*si;
				while(tail-head>K && knum>a[head]){
					sqe[sz++] = knum;
					head++;
				}
			}
		}
		sort(sqe,sqe+sz);
		for(int i=0;i<sz;i++)
			printf("sqe %d\n",sqe[i]);
		printf("%d\n",sqe[M-1]);
	}
}
