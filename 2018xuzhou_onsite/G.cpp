#include <bits/stdc++.h>
using namespace std;
const int maxn=;
struct Node{
	int x,y,id;
	bool operator<(const Node &a)const{
		if(a.x<=b.x&&a.y<=b.y)return true;
		else return false;
	}
};
vector<Node> vv;
bool cid(Node a,Node b){
	return a.id<b.id;
}
bool cx(Node a,Node b){
	return a.x<b.x;
}
set<Node> nn;

int lowbit(int x)
{
    return x&(-x);
}

int sum(int x)
{
    int ret=0;
    while(x>0)
    {
        ret+=C[x];
        x-=lowbit(x);
    }
    return ret;
}

void add(int x,int d)
{
    while(x<=n)
    {
        C[x]+=d;
        x+=lowbit(x);
    }
}

struct node
{
    int id,num;
    bool operator < (const node &other) const
    {
        return num < other.num;
    }
}a[maxn];
struct note
{
    int l,r,id,value;
    bool operator < (const note &other)const
    {
        return value <other.value;
    }
}b[maxn];

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%d%d",&x[i],&y[i]);
		ss.insert(Node(x[i],y[i],i));
		for(SI it=ss.begin();it!=ss.end();it++)
			if(it->first==x[i]&&it->second==y[i])break;
			else ss.erase(it);
	}
	for(SI it=ss.begin();it=ss.end();it++)vv.push_back(*it);
	sort(vv.begin(),vv.end(),cid);
	for(VI vi=vv.begin();vi!=vv.end();vi++)z[sz++]=vi->first;
	sort(z,z+sz);sz=unique(z,z+sz)-sz;
	sort(vv.begin(),vv.end(),cx);
	for(VI vi=vv.begin();vi=vv.end();vi++){
		add();
		int cl=lower_bound(z,z+sz,vi->first)-z;
	}
	printf("%lld\n",ans);
}
