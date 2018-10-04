#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PP;
set<PP> ss;
int N;
int dx[4] = {0 , 0 , 1 , -1};
int dy[4] = {1 , -1 , 0 , 0};
bool isin(int x,int y)
{
	if(x >= 1 && x <= N && y >= 1 && y <= N)return true;
	else return false;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int ans = 0,N,D,s = 0 ;
		scanf("%d%d",&N,&D);
		int x,y;
		ss.clear();
		for(int i = 1;i <= D;i++){
			scanf("%d%d",&x,&y);
			ss.insert(PP(x,y));
		}
		for(int i=1;i<=N;i++)
			for(int j=1;j<=N;j++){
				int tmp = 0;
				if(i>j)tmp = ans;
				if((i == 1 || i == N) && (j == 1 || j == N))
					ans += 3;
				else if(i == 1 || i == N || j == 1 || j == N)
					ans += 4;
				else ans += 5;
				for(int k = 0 ;k < 4; k++){
                        int nx = j+dx[k] , ny = i+dy[k];
                        if(isin(nx,ny) && ss.count(PP(nx,ny)))ans--;
                    }
				if(i != j)s += ans-tmp;
			}
		int fra = __gcd(ans - s,ans);
		printf("%d/%d\n",(ans - s)/fra , ans/fra);
	}
}
