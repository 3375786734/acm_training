/*idea:-for ST-version
 *注意到是单点修改,相当于给了一个pivot,因此在这里我们总是进行预处理求出满足要求的前缀
 *如果某一个query,我们先看在这个query之前的,然后再看query之后的
 *
 *
 *1.对query之前的最大值位置为cur1,前缀cur1不会改变,cur1到query也不会改变,只是query如果比cur1位置的大,那么结果在预处理基础上+1
 *
 *2.如果当前query位置已经成为最大值了,那么会对后面的结果产生影响,因此使用线段树找到第一个在query后比他大的数的位置cur2,query - cur2不会发生改变,query-end也不发生改变,因此整个复杂度落在了找cur2,cur1上面
 *
 *3.复杂度分析:预处理O(nlogn)-ST表复杂度,一次查询前缀最大位置O(logn),一次查询后面最大位置O(logn),因此复杂度为O(qlogn)
 *
 *4.类似题目 bzoj-楼房重建
 *
 *5.基础知识:怎么使用线段树找区间最大所在下标,区间后第一个大于某个数的位置
 *
 *6.出现bug的地方:空间开小了,搜索应从max(hh,h[pl])开始而不是hh,因为hh可能小于h[pl];线段树函数接口写挂了
 *  还要一个地方是应该从dl[pl]开始计数,而不是dl[current]开始计数,这是因为cur本身可能+1,如果本身已经+1替换后又+1将产生问题;
 */
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dep(i,a,b) for(int i=a;i>=b;i--)
#define MEM(a,num) memset(a,num,sizeof(a))
using namespace std;
const int maxn=1e5+100;
int tag[maxn<<2],tr[maxn<<2];
int dl[maxn],dr[maxn];
int h[maxn],N,M;

void push_up(int rt)
{
	if(tr[rt<<1]>tr[rt<<1|1])
		tr[rt]=tr[rt<<1],tag[rt]=tag[rt<<1];
	else tr[rt]=tr[rt<<1|1],tag[rt]=tag[rt<<1|1];
}
void build(int cl,int cr,int rt)
{
	if(cl==cr){
		tr[rt]=h[cl];
		tag[rt]=cl;
		return ;
	}
	int mid=(cl+cr)/2;
	build(cl,mid,rt<<1);
	build(mid+1,cr,rt<<1|1);
	push_up(rt);
}
/*
int que_pr(int cl,int cr,int ql,int qr,int rt,int val)
{
	if(cl==cr)return tr[rt]>val?cl:N+1;
	if(cl>qr)return N+1;
	int mid=(cl+cr)/2;
	if(tr[rt<<1]>val&&mid>=ql)return que_pr(cl,mid,ql,qr,rt<<1,val);
	else if(tr[rt<<1|1]>val&&mid<qr)return que_pr(mid+1,cr,ql,qr,rt<<1|1,val);
	else return N+1;
}
*/
/*idea:由于我们在这里找最小的满足要求的下标,如果落在query区间内,我们可以直接按照二分的方法进行处理
 *     如果不在询问区间内,如果有一部分重合了,那么先递归到query内部再处理,每一个query子区间满足要求的,我们都计算一遍,直到找到最小的
 *
 */
void que_pr(int cl,int cr,int ql,int qr,int rt,int val,int &index)
{
	if(cl==cr)
	{
		//由于并不是有序的
		if(tr[rt]>val)
			index=min(index,cl);
		return ;
	}
	int mid = (cl+cr)/2;
	if(cl>=ql && cr<=qr)   //如果落到里面去了
	{
		if(tr[rt<<1]>val) que_pr(cl,mid,ql,qr,rt<<1,val,index);
		else if(tr[rt<<1|1]>val) que_pr(mid+1,cr,ql,qr,rt<<1|1,val,index);
		return ;
	}
	if(mid>=ql)que_pr(cl,mid,ql,qr,rt<<1,val,index);
	//如果只有一部分落到里面,搜那一部分
	if(mid<qr)que_pr(mid+1,cr,ql,qr,rt<<1|1,val,index);
}
/*idea:每一个子区间取最大的,思想很简单
 *
 */
void que_pl(int cl,int cr,int ql,int qr,int rt,int &index)
{
	if(cl>=ql&&cr<=qr){
		if(tr[rt]>h[index])index=tag[rt];
		return ;
	}
	int mid=(cl+cr)/2;
	if(mid>=ql)que_pl(cl,mid,ql,qr,rt<<1,index);
	if(mid<qr)que_pl(mid+1,cr,ql,qr,rt<<1|1,index);
}
int main()
{
	int T;
//	freopen("t.in","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		MEM(dr,0);MEM(dl,0);MEM(tag,0);MEM(tr,0);
		scanf("%d%d",&N,&M);
		int MM=0;
		rep(i,1,N){
			scanf("%d",&h[i]);
			if(MM<h[i]){
				dl[i]=dl[i-1]+1;
				MM=h[i];
			}
			else dl[i]=dl[i-1];
		}
		build(1,N,1);
		dep(i,N,1){
			int ps=N+1;
			if(i<N)que_pr(1,N,i+1,N,1,h[i],ps);
//			printf("hehre%d %d %d\n",N,M,ps);
			dr[i]=dr[ps]+1;
		}
		rep(i,1,M){
			int ans=0,ps,hh,pr=N+1,pl=0;
			scanf("%d%d",&ps,&hh);
			if(ps!=1)que_pl(1,N,1,ps-1,1,pl);
			if(h[pl]<hh)ans+=dl[pl]+1;
			else ans+=dl[pl];
			if(ps<N)que_pr(1,N,ps+1,N,1,max(hh,h[pl]),pr);
//			printf("pr %d\n",pr);
			ans+=dr[pr];
			printf("%d\n",ans);
		}
	}
}
