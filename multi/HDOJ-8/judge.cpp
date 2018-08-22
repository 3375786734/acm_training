#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+100;
char str[maxn][11],str2[maxn][11];
double Abs(double a){
	if(a>0)return a;
	else return -a;
}
int main()
{
	freopen("B.txt","r",stdin);
	int cnt=0;
	while(~scanf("%s",str[cnt++])){}
	//for(int i=0;i<100;i++)
	//		printf("%s\n",str[i]);
	freopen("b.ans","r",stdin);
	cnt=0;
	while(~scanf("%s",str2[cnt++])){}
		for(int i=0;i<cnt;i++){
			if(str[i][0]=='i'&&str2[i][0]=='i')continue;
			else if((str[i][0]=='i'&&str2[i][0]!='i')||(str2[i][0]=='i'&&str[i][0]!='i'))
				printf("case %d\n",i+1);
			else{
				double a=atof(str[i]),b=atof(str2[i]);
				if(Abs(a-b)>1e-5)
					printf("case %d %lf %lf\n",i+1,a,b);
			}
		}
}
