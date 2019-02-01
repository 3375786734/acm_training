#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
using namespace std;
const int maxn =2e5;
int N,M;
int a[maxn],vis[maxn];
vector<int> dif[maxn];
Mset<int> cnt[maxn];
int main()
{
	scanf("%d%d",&N,&M);
	int mm =0;
	for(int i=1;i<=N;i++)
		cnt[0].insert(i);
	for(int i=1;i<=M;i++)
		scanf("%d",&a[i]);
	int ccnt = 0;
	for(int i=1;i<=M;i++){
		cnt[vis[a[i]]].erase(a[i]);vis[a[i]]++;
		cnt[vis[a[i]]].insert(a[i]);
		if(cnt[ccnt].empty()){
			printf("1");ccnt++;
		}
		else printf("0");
	}
	printf("\n");
}
