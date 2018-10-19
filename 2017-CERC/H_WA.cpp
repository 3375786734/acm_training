#include <bits/stdc++.h>
using namespace std;
const int maxn=2050;
string str[maxn];
vector<string> vv[maxn];
int N,K,ssz[maxn];
map<string,int> mm;
string id[maxn];
int get_num(string ss,int l,int r){
	int tmp[500],ans=0,bits=1;
	for(int i=r-1;i>=l;i--){
		ans+=(ss[i]-'0')*bits;
		bits*=10;
	}
	return ans;
}
int dfs(string rt,string pre){
	//cout<<rt<<endl;
	for(auto u:vv[mm[rt]]){
		if(u==pre)continue;
		ssz[mm[rt]]+=dfs(u,rt);
	}
	//if(vv[mm[rt]].size==1)vv[mm[rt]].clear();
	return ssz[mm[rt]];
}
int main()
{
	freopen("t.in","r",stdin);
	cin>>N;
	for(int i=0;i<=N;i++)
		getline(cin,str[i]);
	cin>>K;
	int sz=0,cid=0;
	id[cid++]="rt";
	sort(str,str+N);
	for(int i=1;i<=N;i++){
		int len=str[i].length(),cnt=0,flag=0,ok=1,pid=0;
		string pre="rt",cur;
		for(int j=1;j<len;j++){
			//cout<<str[i][j]<<endl;
			if(str[i][j]=='/'||(flag==0&&str[i][j]==' ')){
				if(ok==0 || !mm.count(cur))
					id[cid++]=cur,ok=0;
				else cid =;
				vv[pid].push_back(cid-1);
				pre=cur;pid=cid;
				cnt=0;cur.clear();
				if(str[i][j]==' ')flag=1;
			}
			else if(str[i][j]!=' ')cur.insert(cnt++,str[i],j,1);
			if(str[i][j]>='0'&&str[i][j]<='9'){
				int bit=get_num(str[i],j,len);
				ssz[pid]=bit;
				break;
			}
		}
	}
	for(int i=0;i<=N;i++)
		sort(vv[i].begin(),vv[i].end(),[&](int a,int b){return id[a]<id[b];});
	dfs(0,0);
}
