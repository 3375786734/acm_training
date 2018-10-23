/*
 *思路见Note
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int N,rid[maxn],bit[maxn<<1];
char str[maxn];
int lowbit(int x){
	return x&(-x);
}
void udp(int x,int a){
	for(int i=x;i<=N;i+=lowbit(i))
		bit[i]+=a;
}
ll gtsum(int x){
	ll ans=0;
	for(int i=x;i>=0;i-=lowbit(i))
		ans+=bit[i];
	return ans;
}
/*
int manacher(char *str){
	memset(rid,0,sizeof(rid));
	int len = strlen(str),ans=0,id=0;
	//pre oper
	for(int i = len ;i>=0 ; i--){
		str[i+i+2] = str[i];
		str[i+i+1] = '#';
	}
	str[0] = '*';
	for(int i = 2;i<2*len+1;i++){
		if(rid[id]+id>i) rid[i]= min(rid[2*id-i],rid[id]+id-i);
		else rid[i] = 1;
		while(str[i-rid[i]]==str[i+rid[i]]) rid[i]++;
		if(rid[i]+i > rid[id]+id) id= i;
		ans = max(ans, rid[i]-1);
	}
	return ans;
}
*/
int manacher(char *str){
	int id=0,len=strlen(str),ans=0;
	for(int i=len;i>=0;i--){
		str[i+i+2] = str[i];
		str[i+i+1] = '#';
	}
	str[0] = '*';//防止越界
	for(int i=2;i<2*len+1;i++){
		if(rid[id] + id>i)rid[i]  = min(rid[2*id-i],rid[id]+id-i);
		else rid[i] =1;
		while(str[rid[i]+i]==str[i-rid[i]])rid[i]++;
		if(rid[i]+i>rid[id]+id) id= i;
		ans = max(ans,rid[i]-1);
	}
	return ans;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",str);
		int len = strlen(str),dlen= len*2+1;
		int ans = manacher(str);
		printf("%d\n",ans);
		/*
		for(int i=2;i<dlen;i++){
			int rr = rid[i]/2;
			
		}
		*/
	}
}
