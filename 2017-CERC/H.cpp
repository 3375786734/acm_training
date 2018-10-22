/*
 *IDEA:建一颗trie
 *
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn=6000;
string str[maxn];
vector<string> vv[maxn],vvv;
map<string,int> ss[maxn];
string idd[maxn];
int N,K,cnnt[maxn],val[maxn];
int tag[maxn];
int get_num(string ss,int l,int r){
    int tmp[500],ans=0,bits=1;
    for(int i=r-1;i>=l;i--){
        ans+=(ss[i]-'0')*bits;
        bits*=10;
    }
    return ans;
}
void build(){
	int sz=0;
	for(int i=1;i<=N;i++){
		int ps=0;
		for(auto sss:vv[i]){
			if(!ss[ps].count(sss)){
				ss[ps][sss]=++sz;
				ps=sz;
				idd[ps]=sss;
			}
			else ps=ss[ps][sss];
		}
		cnnt[ps]=val[i];
		tag[ps]=1;
		//cout<<"cnt"<<ps<<" "<<cnnt[ps]<<endl;
	}
}
int dfs(int now,int pre){
	int ok=0,ok2=0;
	for(auto mi:ss[now]){
		if(mi.second == pre)continue;
		//cout<<now<<" "<<mi.first<<endl;
		if(tag[mi.second]!=1)ok=1;
		if(tag[mi.second]!=1&&cnnt[mi.second]>=K)ok2=1;
		cnnt[now]+=dfs(mi.second,now);
	}
	if(ok==0)tag[now]=2;
	if(ok==1&&ok2==0)tag[now]=3;
	return cnnt[now];
}
void print_ans(int now,int pre)
{
	if(tag[now]==0)cout<<"- ";
	if(tag[now]==2)cout<<"  ";
	if(tag[now]==3)cout<<"+ ";
	for(auto vi:vvv)cout<<"/"<<vi;
	cout<<" "<<cnnt[now]<<endl;
	if(tag[now]!=0)return;
	for(auto mi:ss[now]){
		if(mi.second==pre||tag[mi.second]==1)continue;
		vvv.push_back(mi.first);
		print_ans(mi.second,now);
		vvv.pop_back();
	}
}
int main()
{

    freopen("t.in","r",stdin);
    cin>>N;
    for(int i=0;i<=N;i++){
        getline(cin,str[i]);
		cout<<str[i]<<endl;
	}
    cin>>K;
	for(int i=1;i<=N;i++){
		int len=str[i].length(),cnt=0;
		int flagsp=0;
		string cur;
		for(int j=1;j<len;j++){
			//cout<<cur<<endl;
			if(str[i][j]=='/'||(str[i][j]==' '&&flagsp==0)){
				if(str[i][j]==' ')flagsp=1;
				//cout<<cur<<endl;
				vv[i].push_back(cur);
				cur.clear();cnt=0;
			}
			else if(str[i][j]>='0'&&str[i][j]<='9'){
				int ccc=get_num(str[i],j,len);
				val[i]=ccc;
				break;
			}
			else if(str[i][j]!=' ')cur.insert(cnt++,str[i],j,1);
		}
	}
	build();
	dfs(0,0);
	//cout<<cnnt[0];
	print_ans(0,0);
}
