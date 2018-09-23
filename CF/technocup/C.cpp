#include <bits/stdc++.h>
using namespace std;
int N;
int num[200],pre[200];
char str[200];
int main()
{
	scanf("%d%s",&N,str);
	for(int i=1;i<=N;i++){
		num[i]=str[i-1]-'0';
		pre[i]=pre[i-1]+num[i];
	}
	int flag=1;
	for(int i=1;i<=N;i++)
		if(num[i]!=0)flag=0;
	for(int i=1;i<N;i++){
		int ps=i+1;
		if(flag==1)break;
		if(pre[i]==0)continue;
		while(1){
			int sum=num[ps];
			while(ps<=N&&sum<pre[i]){
				ps++;
				sum+=num[ps];
			}
			if(sum!=pre[i])break;
			if(ps>N){
				flag=1;
				break;
			}
			sum=0;
		}
	}
	if(flag==1)printf("YES\n");
	else printf("NO\n");
}
