#include <bits/stdc++.h>
using namespace std;
int N;
char str[200010];
		
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		char s[200050];
		int n;
		scanf("%d%s",&n,s);
		if(n<3){
			printf("0\n");
			continue;
		}
		else{
			s[n]='*';
			int pos=0;
			int ans=0;
			int flag=0;
			while(pos<n-2){
				if(s[pos]=='C'&&s[pos+1]=='C'&&s[pos+2]=='P'&&s[pos+3]=='C'){
					ans++;
					pos+=3;
				}
				else if(s[pos]=='C'&&s[pos+1]=='C'&&s[pos+2]=='P'&&!flag){
					ans++;
					pos+=2;
					flag=1;
				}
				else if(s[pos]=='C'&&s[pos+1]=='C'&&s[pos+2]=='C'&&!flag){
					ans++;
					pos+=2;
					flag=1;
				}
				else if(s[pos]=='C'&&s[pos+1]=='P'&&s[pos+2]=='C'&&!flag){
					ans++;
					pos+=2;
					flag=1;
				}
				else pos++;
			}
			printf("%d\n",ans);
		}
	}
}
