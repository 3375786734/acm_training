#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PP;
set<int> ss[5][5];
int ans;
PP ps[50];
char str[10][10];
int vis[10][10];
bool check(int cx,int cy)
{
	int ok1=0,ok2=0,s1=0,s2=0,s3=0,ok3=0;
	for(int i=0;i<4;i++)
		if(str[cy][i]=='*')ok1=1;
		else s1+=str[cy][i]-'0';
	if(ok1==0&&s1==10)ok1=1;
	printf("%c %c %c %c\n",str[cy][0],str[cy][1],str[cy][2],str[cy][3]);
	for(int i=0;i<4;i++)
		if(str[i][cx]=='*')ok2=1;
		else s2+=str[i][cx]-'0';
	for(int j=cx/2*2;j<cx/2*2+2;j++)
		for(int i=cy/2*2;i<cy/2*2+2;i++)
			if(str[i][j]=='*')ok3=1;
			else s3+=str[i][j]-'0';
	if(ok2==0&&s2==10)ok2=1;
	if(ok3==0&&s3==10)ok3=1;
	return ok1&&ok2&&ok3;
}
void dfs(int dep){
	if(dep==-1){
		ans=1;
		return;
	}
	int cy=ps[dep].first,cx=ps[dep].second;
	//if(vis[cy][cx]==1)return ;
	//vis[cy][cx]=1;
	//printf("now %d %d %d\n",cx,cy,dep);
	for(set<int>::iterator si=ss[cy][cx].begin();si!=ss[cy][cx].end();si++){
		printf("cx %d cy %d\n",cx,cy);
		PP tmp[18];
		int sz=0;
		str[cy][cx]=(*si)+'0';
		for(int i=0;i<4;i++)
			if(ss[cy][i].count(*si)&&i!=cx){
				tmp[sz++]=PP(cy,i);
			//if(cy==1&&i==1&&*si==2)printf("here %d %d\n",cx,cy);
				ss[cy][i].erase(*si);
			}
		for(int i=0;i<4;i++)
            if(ss[i][cx].count(*si)&&i!=cy){
                tmp[sz++]=PP(i,cx);
                ss[i][cx].erase(*si);
			//if(cy==1&&i==1&&*si==2)printf("herei %d %d\n",cx,cy);
            }
		if(check(cx,cy))dfs(dep-1);
		if(ans==1)return;
		for(int i=0;i<sz;i++){
			//if(xx==1&&yy==1&&*si==2)printf("here %d %d\n",cx,cy);
			ss[tmp[i].first][tmp[i].second].insert(*si);
		}
	}
}
int main()
{
	int T,cas=1;
	freopen("t.in","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		int cnt=0;
		ans=0;
		memset(vis,0,sizeof(vis));
		for(int i=0;i<4;i++)
			scanf("%s",str[i]);
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++){
				ss[i][j].clear();
				for(int k=1;k<=4;k++)ss[i][j].insert(k);
		}
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++){
				if(str[i][j]=='*')ps[cnt++]=PP(i,j);
				else {
					int nn=str[i][j]-'0';
					vis[i][j]=1;
					for(int k=0;k<4;k++)ss[i][k].erase(nn);
					for(int k=0;k<4;k++)ss[k][j].erase(nn);
				}
			}
		printf("Case #%d:\n",cas++);
		dfs(cnt-1);
		//printf("ans %d\n",ans);
		for(int i=0;i<4;i++){
            for(int j=0;j<4;j++)
            printf("%c",str[i][j]);
            printf("\n");
        }
		//printf("Case #%d: %s\n",cas++,ans==1?"Can kill in one move!!!":"Can not kill in one move!!! ");
	}
}
