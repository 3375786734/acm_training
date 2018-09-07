#include <bits/stdc++.h>
using namespace std;
vector<int>ans;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int n,R,r;
		scanf("%d%d%d",&n,&R,&r);
		int mi=999999999;
		for(int i=1;i<=n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			int d=x*x+y*y;
			int flag=0;
			if(d<mi){
				if(mi>(R-2*r)*(R-2*r)){
					mi=d;
					ans.clear();
					ans.push_back(i);
				}
				else {
					mi=(R-2*r)*(R-2*r);
					if(!flag)ans.clear();
					ans.push_back(i);
					flag=1;
				}
			}	
			else if(d==mi){
				ans.push_back(i);
			}
		}
		printf("%d\n",(int)ans.size());
		printf("%d",ans[0]);
		for(int i=1;i<(int)ans.size();i++){
			printf(" %d",ans[i]);
		}
		printf("\n");
	}
	return 0;
}
