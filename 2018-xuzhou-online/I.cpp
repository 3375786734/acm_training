#include <bits/stdc++.h>
using namespace std;
const int maxn=5e6;
char ans[maxn];
int sz,flag;
int Abs(int a){
	if(a>0)return a;
	else return -a;
}
void solve(int n){
		if(n<10)ans[sz++]='0',ans[sz++]='0'+n;
		else while(n){
			ans[sz++]=n%10+'0';
			n/=10;
		}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		char tmp[2],str[1000100];
		int N;
		sz=flag=0;
		scanf("%d%s",&N,tmp);
		scanf("%s",str);
		for(int i=0;i<N;i++)
			solve(Abs(tmp[0]-str[i]));
		int s=sz;
		for(int i=0;i<sz;i++)
			if(ans[i]=='0'&&flag==0)s--;
			else flag=1;
		printf("%d\n",s);
	}
}
