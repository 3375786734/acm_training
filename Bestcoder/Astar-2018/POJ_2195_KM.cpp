#include <bits/stdc++.h>
#define mp make_pair
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn=1000;
typedef pair<int,int> PP;
char str[maxn][maxn];
int w[maxn][maxn],N,M;
vector<PP> vm,vh;
int Abs(int a){
	if(a>0)return a;
	else return -a;
}
int KM()
{
	int ans=0;
	return ans;
}
int main()
{
	while(~scanf("%d%d",&N,&M)){
		vh.clear();vm.clear();
		rep(i,0,N-1)scanf("%s",str[i]);
		int i,j;
		for(i=0;i<N;i++)
			for(j=0;j<M;j++)
				if(str[i][j]=='m')vm.push_back(PP(i,j));
				else if(str[i][j]=='H')vh.push_back(PP(i,j));
		int sz=vh.size();
		i=1;
		for(vector<PP>::iterator it=vm.begin();it!=vm.end();it++,i++){
			j=1;
			printf("men at %d %d\n",it->first,it->second);
			for(vector<PP>::iterator ii=vh.begin();ii!=vh.end();ii++,j++){
				w[i][j]=-Abs((*it).first-(*ii).first)-Abs((*it).second-(*ii).second);
			}
		}
		for(int i=1;i<=sz;i++)
			for(int j=1;j<=sz;j++)
				printf("%d%c",w[i][j],j==sz?'\n':' ');
		printf("%d\n",-KM());
	}
}
