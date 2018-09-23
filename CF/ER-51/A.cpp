#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dep(i,a,b) for(int i=a;i>=b;i--)
typedef long long ll;
using namespace std;
typedef pair<int,int > PP;
typedef set<PP> SS;
typedef vector<int> VI;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		char str[1000];
		scanf("%s",str);
		int len =strlen(str);
		int vis[4],ps[4];
		MEM(ps,-1);MEM(vis,0);
		for(int i=0;i<len;i++){
			if(str[i]>='a'&&str[i]<='z'){
				if(vis[0]==0)
					vis[0]=1;
				else ps[0]=i;
			}
			else if(str[i]>='A'&&str[i]<='Z'){
				if(vis[1]==0)
					vis[1]=1;
				else ps[1]=i;
			}
			else if(str[i]>='0'&&str[i]<='9'){
				if(vis[2]==0)
					vis[2]=1;
				else ps[2]=i;
			}
		}
		if(vis[0]==vis[1]&&vis[1]==vis[2]&&vis[2]==1)printf("%s\n",str);
		else {
			if(vis[0]==vis[1]&&vis[0]==1){
				rep(i,0,2)
					if(ps[i]!=-1){
						str[ps[i]]='1';
						break;
					}
			}
			else if(vis[0]==vis[2]&&vis[0]==1){
                rep(i,0,2)
                    if(ps[i]!=-1){
                        str[ps[i]]='A';
                        break;
                    }
            }
			else if(vis[1]==vis[2]&&vis[1]==1){
                rep(i,0,2)
                    if(ps[i]!=-1){
                        str[ps[i]]='a';
                        break;
                    }
            }
			else {
				if(vis[0]==1)str[0]='A',str[1]='1';
				else if(vis[1]==1)str[0]='a',str[1]='1';
				else if(vis[2]==1)str[0]='a',str[1]='A';
			}
			printf("%s\n",str);
		}
	}
}
