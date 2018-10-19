#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+100;
int a[maxn];
char str[maxn];
struct Node{
	int cc,id;
	bool operator<(const Node &a)const {
		return cc<a.cc;
	}
};
Node alph[50];
int main()
{
	int n;
	scanf("%d%s",&n,str);
	for(int i=0;i<n;i++)
		a[str[i]-'a']++;
	for(int i=0;i<26;i++)
		alph[i]=(Node){a[i],i};
	sort(alph,alph+26);
	for(int i=25;i>=0;i--)
	{
		/*
		if(i-1>=0){
			//printf("here %d %d\n",alph[i].cc,alph[i-1].cc);
			for(int j=0;j<alph[i-1].cc;j++)
				printf("%c%c",alph[i].id+'a',alph[i-1].id+'a');
			for(int j=0;j<alph[i].cc-alph[i-1].cc;j++)
				printf("%c",alph[i].id+'a');
			i--;
		}
		else{
			for(int j=0;j<alph[i].cc;j++)
					printf("%c",alph[i].id+'a');
		}*/
		for(int j=0;j<alph[i].cc;j++)
			printf("%c",alph[i].id+'a');
	}
	printf("\n");
}
