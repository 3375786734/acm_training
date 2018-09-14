/*
 *正向的思路:考虑到当前更新到i,如果前面有x比他小,y比他大的,那么每一个都要减去当前的y值,如果前面有x比他大的,y比小的,都要减去当前的x值,如果另外两种包含关系直接使用排序的关系处理掉即可,现在的问题就转化为了:
 	怎么样在(logN)^2的时间内实现单点修改以及查询在一个序列中比某个数h大的数的个数
	可以使用树套树实现,或者见segment tree的做法.
	注意一个思想误区,认为前面后面都要统计,这样后面的会被统计两次,是错误的.
 */
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
