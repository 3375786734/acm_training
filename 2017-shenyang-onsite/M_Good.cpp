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
	int T,cas=1;
	scanf("%d",&T);
	while(T--)
	{
		int ans = 0,D,s = 0 ;
		scanf("%d%d",&N,&D);
		int x,y;
		ss.clear();
		for(int i = 1;i <= D;i++){
			scanf("%d%d",&x,&y);
			ss.insert(PP(x+1,y+1));
		}
		/*
		for(int i=1;i<=N;i++)
			for(int j=1;j<=N;j++){
				int tmp = ans;
				if((i == 1 || i == N) && (j == 1 || j == N))
					ans += 3;
				else if(i == 1 || i == N || j == 1 || j == N)
					ans += 4;
				else ans += 5;
				for(int k = 0 ;k < 4; k++){
                        int nx = j+dx[k] , ny = i+dy[k];
                        if(isin(nx,ny) && ss.count(PP(nx,ny)))
							ans--;
                    }
				if(ss.count(PP(j,i)))ans=tmp;
				if( i + j >= N+1)
					s += ans-tmp;
			}
		*/
		ans=(N-2)*(N-2)*5+16*(N-2)+12;
		s=(ans-(6+(N-2)*5))/2+6+(N-2)*5;
		for(set<PP>::iterator it=ss.begin();it!=ss.end();it++){
			int xx = it->first , yy = it->second;
			if((xx==1||xx==N)&&(yy==1||yy==N)){
				ans -= 3;
				if(xx+yy >= N+1)s -= 3;
			}
			else if(xx==1||yy==1||xx==N||yy==N){
				ans -= 4;
				if(xx+yy >= N+1)s -= 4;
			}
			else{
				ans -= 5;
				if(xx+yy >= N+1)s -= 5;
			}
			for(int k = 0;k < 4;k++){
				int nx = xx+dx[k], ny = yy+dy[k];
				if(isin(nx,ny) && nx+ny >= N+1 && !ss.count(PP(nx,ny)))s--;
				if(isin(nx,ny) && !ss.count(PP(nx,ny)))ans--;
			}
		}
		int fra = __gcd(s,ans);
		//printf("ans %d %d\n", ans,s);
		printf("Case #%d: %d/%d\n",cas++,s/fra ,ans/fra);
	}
}
