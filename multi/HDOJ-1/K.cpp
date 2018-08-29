#include <bits/stdc++.h>
using namespace std;
const int maxn=1000;
double get_zone(char *str,int ps,int len)
{
	char tmp[100];
	memset(tmp,0,sizeof(tmp));
	for(int i=ps;i<len;i++)
		tmp[i-ps]=str[i];
	return atof(tmp);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		char str[300];
		scanf("%d%d",&a,&b);
		scanf("%s",str);
		int cnt=0,len=strlen(str);
		while(str[cnt]>'9'||str[cnt]<'0')cnt++;
		double zone=get_zone(str,cnt,len);
		printf("%lf\n",zone);
	}
}
