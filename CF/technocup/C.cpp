/*
 *这里,0是个麻烦的数,我们先将其去掉
 *
 */
#include <bits/stdc++.h>
using namespace std;
int N;
int num[200],pre[200],num2[200];
char str[200];
int main()
{
	int cnt=0,flag=0;
	scanf("%d%s",&N,str);
	for(int i=1;i<=N;i++){
		num[i]=str[i-1]-'0';
		if(num[i]>0)num2[++cnt]=num[i];
	}
	for(int i=1;i<=cnt;i++)
		pre[i]=pre[i-1]+num2[i];
//	printf("sz %d",cnt);
	for(int i=1;i<cnt;i++){
		int ps=i+1;
		if(flag==1)break;
		while(1){
			int sum=0;
			while(ps<=cnt&&sum<pre[i])
				sum+=num2[ps++];
			if(sum!=pre[i])break;
			if(ps>cnt){
				flag=1;
				break;
			}
		}
	}
	if(flag==1||cnt==0)printf("YES\n");
	else printf("NO\n");
}
