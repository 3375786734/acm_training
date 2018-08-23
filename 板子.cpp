/*****************************************************************
					数据结构:
********************************************************************/
/*
	Trie;
	注意的是:有必要时MEM(ch,0); 因为MEM可能会超内存
 */
 int ch[id_num][maxn],ct[maxn],tag[maxn];
 void insert(char *str)
 {
	 int len=strlen(str),ps=0;//rt=ps
	for(int i=0;i<len;i++)
	{
		int id=str[i];
		if(ch[id][ps]==0)
		{
			memset(ch[sz],0,sizeof(ch[sz]));
			ch[id][ps]=++sz;
		}
		ps=ch[id][ps]; //next node
		ct[ps]++;
	}
	tag[ps]=1;
 }
 /*
	Fenwich Tree 注意的是bit要开两倍
	其中find是找到一个位置,使得和刚好为ll
  */
 int lowbit(int a)
{return a&(-a);}
void add(int x,int y){
	for(int i=x;i<=N;i+=lowbit(i))
		bit[i]+=y;
}
int get_sum(int x){
	int ans=0;
	for(int i=x;i>0;i-=lowbit(i))ans+=bit[i];
	return ans;
}
int Find(int ll)
{
	int ps=0,num=0;
	for(int i=20;i>=0;i--)
		if((1<<i)+ps<=N&&num+bit[(1<<i)+ps]<ll)
			num+=bit[ps+=(1<<i)];
	return ps+1;
}
  
/*
	lca O(nlogn)
*/  
void init()
{
	for(int i =LOGN-1;i>=0;i--)
		for(int j=1;j<=N;j++)
			anc[j][i]=anc[anc[j][i-1]][i-1];
}
void lca(int a,int b)
{
	if(dep[a]>dep[b])swap(a,b);
	for(int i=0;i<LOGN;i++)
		if(((dep[b]-dep[a])>>i)&i)b=anc[b][i];
	if(a==b)return a;
	for(int i=LOGN-1;i>=0;i--)
		if(anc[a][i]!anc[b][i])
		{
			a=anc[a][i];
			b=anc[b][i];
		}
	return anc[a][0]
}
void dfs(int fa,int now)
{
	dep[now]=dep[now]+1;
	for(int i=head[now];i!=-1;i=eg[i].next)
	{
		int id=eg[i].to;
		if(id!=fa)
			dfs(now,id);
	}
}
/*
	segment Tree
*/
void Update(int cl,int cr,int ql,int qr,int op,int rt)
{
	if()
	int m=(cl+cr)>>1;
	push_down(rt,cl,cr);
	// there many way 
	
}
/*
	Treap
*/
//暂时没有
/*
	chairman tree
*/
//暂时没有
/******************************************************
			DP类
********************************************************/
/*
		数位DP
*/
    typedef long long ll;  
    int a[20];  
    ll dp[20][state];//不同题目状态不同  
    ll dfs(int pos,/*state变量*/,bool lead/*前导零*/,bool limit/*数位上界变量*/)//不是每个题都要判断前导零  
    {  
        //递归边界，既然是按位枚举，最低位是0，那么pos==-1说明这个数我枚举完了  
        if(pos==-1) return 1;/*这里一般返回1，表示你枚举的这个数是合法的，那么这里就需要你在枚举时必须每一位都要满足题目条件，也就是说当前枚举到pos位，一定要保证前面已经枚举的数位是合法的。不过具体题目不同或者写法不同的话不一定要返回1 */  
        //第二个就是记忆化(在此前可能不同题目还能有一些剪枝)  
        if(!limit && !lead && dp[pos][state]!=-1) return dp[pos][state];  
        /*常规写法都是在没有限制的条件记忆化，这里与下面记录状态是对应，具体为什么是有条件的记忆化后面会讲*/  
        int up=limit?a[pos]:9;//根据limit判断枚举的上界up;这个的例子前面用213讲过了  
        ll ans=0;  
        //开始计数  
        for(int i=0;i<=up;i++)//枚举，然后把不同情况的个数加到ans就可以了  
        {  
            if() ...  
            else if()...  
            ans+=dfs(pos-1,/*状态转移*/,lead && i==0,limit && i==a[pos]) //最后两个变量传参都是这样写的  
            /*这里还算比较灵活，不过做几个题就觉得这里也是套路了 
            大概就是说，我当前数位枚举的数是i，然后根据题目的约束条件分类讨论 
            去计算不同情况下的个数，还有要根据state变量来保证i的合法性，比如题目 
            要求数位上不能有62连续出现,那么就是state就是要保存前一位pre,然后分类， 
            前一位如果是6那么这意味就不能是2，这里一定要保存枚举的这个数是合法*/  
        }  
        //计算完，记录状态  
        if(!limit && !lead) dp[pos][state]=ans;  
        /*这里对应上面的记忆化，在一定条件下时记录，保证一致性，当然如果约束条件不需要考虑lead，这里就是lead就完全不用考虑了*/  
        return ans;  
    }  
    ll solve(ll x)  
    {  
        int pos=0;  
        while(x)//把数位都分解出来  
        {  
            a[pos++]=x%10;//个人老是喜欢编号为[0,pos),看不惯的就按自己习惯来，反正注意数位边界就行  
            x/=10;  
        }  
        return dfs(pos-1/*从最高位开始枚举*/,/*一系列状态 */,true,true);//刚开始最高位都是有限制并且有前导零的，显然比最高位还要高的一位视为0嘛  
    }  
    int main()  
    {  
        ll le,ri;  
        while(~scanf("%lld%lld",&le,&ri))  
        {  
            //初始化dp数组为-1,这里还有更加优美的优化,后面讲  
            printf("%lld\n",solve(ri)-solve(le-1));  
        }  
    }  
/***********************************************************************
							图论
***********************************************************************/
 /*
	Dinic+当前弧
  */
  void addedge(int a,int b,int c)
{
	edge[cur].next=head[a];
	edge[cur].to=b;
	edge[cur].cap=c;
	head[a]=cur++;
	edge[cur].next=head[b];
	edge[cur].to=a;
	edge[cur].cap=0;
	head[b]=cur++;
}

bool dfs(int now,int res)
{	
	if(now==T)return res;
	for(int &i=iter[now];i!=-1;i=edge[i].next)
	{
		int v=edge[i].to,a;
		if(edge[i].cap>0&&layer[v]==layer[now]+1&&(a=dfs(v,min(edge[i].cap,
			res))))
		{
			edge[i].cap-=a;
			edge[i^1].cap+=a;
			return a;
		}
	}
	layer[now]=-1;
	return 0;
}
bool bfs()
{
	queue<int> q;
	memset(layer,-1,sizeof(layer));
	q.push(S);
	layer[S]=1;
	while(!q.empty())
	{
		int fa=q.front();q.pop();
		for(int i=head[fa];i!=-1;i=edge[i].next)
		{
			int v=edge[i].to;
			if(edge[i].cap>0&&layer[v]==-1)
			{
				layer[v]=layer[fa]+1;
				q.push(v);
			}
		}
	}
	return layer[T]!=-1;
}
int Dinic()
{
	int ans=0,aug;
	while(bfs())
	{
		for(int i=0;i<=N+M+1;i++)iter[i]=head[i];
		while(aug=dfs(S,inf))
			ans+=aug;
	}
	return ans;
}
  
  
/*
	MCMF
*/
bool SPFA(int S,int T)
{
	queue<int>q;
	q.push(S);
	memset(vis,0,sizeof(vis));
	memset(pre,-1,sizeof(pre));
	memset(dist,0x3f3f3f,sizeof(dist));
	dist[S]=0,vis[S]=1;
	while(!q.empty())
	{
		int fa=q.front();q.pop();vis[fa]=0;
		for(int i=head[fa];i!=-1;i=edge[i].next)
		{
			int id=edge[i].to;
			if(dist[id]>edge[i].cost+dist[fa]&&edge[i].cap>edge[i].flow)
			{
				dist[id]=edge[i].cost+dist[fa];
				pre[id]=i;
				if(vis[id]==0)
				{
					vis[id]=1;q.push(id);
				}
			}
		}
	}
	return pre[T]!=-1;
}
int MCMF()
{
	int flow,ccc;
	flow=ccc=0;S=0,T=cm+cn+1;
	while(SPFA(S,T))
	{
		int Min=inf;
		for(int i=pre[T];i!=-1;i=pre[edge[i^1].to])
			Min=min(Min,edge[i].cap-edge[i].flow);
		for(int i=pre[T];i!=-1;i=pre[edge[i^1].to])
		{
			edge[i].flow+=Min;
			edge[i^1].flow-=Min;
			ccc+=edge[i].cost*Min;
		}
		flow+=Min;
	}
	return ccc;
}
 /*
	Hungary algortihm+路径输出
 */
 int dfs(int now)
 {
	 for(int i=head[now];i!=-1;i=eg[i].next)
	 {
		 int id=eg[i].to;
		 if(used[id]==0)
		 {
			 used[id]=1;
			 if(linker[id]==-1||dfs(linker[id]))
			 {
				 linker[id]=now;
				 return true;
			 }
		 }
	 }
	 
	 return false;
 }
 int hungary()
 {
	 int res=0;
	 MEM(linker,-1);
	 rep(i,1,N)
	 {
		 memset(used,0);
		 if(dfs(i))res++;
	 }
	 return res;
 }
/*
	Tarjan 双联通分量:注意存的是边的信息
*/
//
/*
	Tarjan 强连通分量
*/
void dfs(int u, int f)  
{  
    dfn[u] = low[u] = ++dfs_clock;  
    s.push(u);  
    for(int i = 0; i < g[u].size(); i++)  
    {  
        int v = g[u][i];  
        if(v == f) continue;  
        if(!dfn[v])  
        {  
            dfs(v, u);  
            low[u] = min(low[u], low[v]);  
        }  
        else if(!belong[v])  
            low[u] = min(low[u], dfn[v]);  
    }  
    if(low[u] == dfn[u])  
    {  
        scc_cnt++;  
        while(1)  
        {  
            int x = s.top(); s.pop();  
            belong[x] = scc_cnt;  
            if(x == u) break;  
        }  
    }  
}  

/*
	Tarjan 桥边割点
*/

void Tarjan(int i,int Father)
{
    father[i]=Father;/*记录每一个点的父亲*/
    dfn[i]=low[i]=tim++;
    for(int j=0;j<G[i].size();++j)
    {
        int k=G[i][j];
        if(dfn[k]==-1)
        {
            Tarjan(k,i);
            low[i]=min(low[i],low[k]);
        }
        else if(Father!=k)/*假如k是i的父亲的话，那么这就是无向边中的重边，有重边那么一定不是桥*/
            low[i]=min(low[i],dfn[k]);//dfn[k]可能！=low[k]，所以不能用low[k]代替dfn[k],否则会上翻过头了。
    }
}
void count()
{
    int rootson=0;
    Tarjan(1,0);
    for(int i=2;i<=n;++i)
    {
        int v=father[i];
        if(v==1)
        rootson++;/*统计根节点子树的个数，根节点的子树个数>=2,就是割点*/
        else{
            if(low[i]>=dfn[v])/*割点的条件*/
            is_cut[v]=true;
        }
    }
    if(rootson>1)
    is_cut[1]=true;
    for(int i=1;i<=n;++i)
    if(is_cut[i])
    printf("%d\n",i);
    for(int i=1;i<=n;++i)
    {
        int v=father[i];
        if(v>0&&low[i]>dfn[v])/*桥的条件*/
        printf("%d,%d\n",v,i);
    }
    
}
/*
	Topsort 只能用于有向无环图
*/
queue<int> qq;
void Topsort()
{
	stack<intt> s;
	for(int i=0;i<N;i++)
		if(inn[i]==0)s.push(i);
	while(!s.empty())
	{
		int fa=s.top();s.pop();qq.push(fa);
		for(int i=head[fa];i!=-1;i=eg[i].next)
		{
			int id=eg[i].to;
			inn[id]--;
			if(inn[id]==0)s.push(id);
		}
	}
}

/*
	K-th short road
*/
 class Node
{
public:
	int g,id;
	Node(int g=0,int id=0):g(g),id(id){}
	bool operator<(const Node &a) const
	{return dist[this->id]+this->g>dist[a.id]+a.g;}
};
void addedge(int a,int b,int v,int op)
{
	if(op==0)
	{
		edge[cur].next=head[a];
		edge[cur].to=b;
		edge[cur].val=v;
		head[a]=cur++;
	}
	else
	{
		reedge[rcur].next=rhead[a];
		reedge[rcur].val=v;
		reedge[rcur].to=b;
		rhead[a]=rcur++;
	}
}
struct cmpdj
{
	bool operator ()(int a,int b){return dist[a]>dist[b];}
};
void dj()
{
	memset(dist,0x3f3f3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	priority_queue<int,vector<int>,cmpdj>q;
	dist[T]=0;
	q.push(T);
	while(!q.empty())
	{
		int fa=q.top();
		q.pop();
		if(vis[fa]==1)continue;
		vis[fa]=1;
		for(int i=rhead[fa];i!=-1;i=reedge[i].next)
		{
			if(dist[reedge[i].to]>dist[fa]+reedge[i].val)
			{
				dist[reedge[i].to]=dist[fa]+reedge[i].val;
				q.push(reedge[i].to);
			}
		}
	}
}
int Astar()
{
	int cnt=0;
	priority_queue<Node>open;
	Node s(0,S);
	if(dist[S]>=INF)return -1;
	if(S==T)K++;
	open.push(s);
	while(!open.empty())
	{
		Node fa=open.top();
		open.pop();
		if(fa.id==T)cnt++;
//		if(cnt[fa.id]>K)continue;
		if(fa.id==T&&cnt==K)return fa.g;
		for(int i=head[fa.id];i!=-1;i=edge[i].next)
		{
			Node tmp(fa.g+edge[i].val,edge[i].to);
			open.push(tmp);
		}
	}
	return -1;
}
/*
	SPFA
*/
void SPFA()
{
	int vis[maxn];
 	memset(vis,0,sizeof(vis));
 	memset(dist,0x3f3f3f,sizeof(dist));
 	dist[S]=0;
 	queue<int> q;
 	q.push(S);
 	while(!q.empty())
 	{
 		int fa=q.front();
 		q.pop();
 		vis[fa]=0;
 		for(int i=head[fa];i!=-1;i=edge[i].next)
 			if(dist[edge[i].to]>dist[fa]+edge[i].val)
 			{
 				dist[edge[i].to]=dist[fa]+edge[i].val;
 				if(vis[edge[i].to]==0)
 				{
 					q.push(edge[i].to);
 					vis[edge[i].to]=1;
 				}
 			}
 	}
}
/*
	bellman_ford 找负圈
*/

/***************************************************************
							number Theory
***************************************************************/
/*
   Euler函数的板子
 */
#include <cstdio>
#include <cstring>
using namespace std;
 
bool vis[1000005];
int tot=0, pri[1000005], phi[1000005];

void Get_phi(int N){
    phi[1] = 1;
    for(int i=2; i<=N; ++i){
        if(!vis[i]){
            pri[++tot] = i;
            phi[i] = i-1;
        }
        for(int j=1,x; j<=tot&&(x=i*pri[j])<=N; ++j){
            vis[x] = true;
            if(i%pri[j] == 0){
                phi[x] = phi[i]*pri[j];
                break;
            }
            else phi[x] = phi[i]*phi[pri[j]];
        }
    }
}
/*
	线性筛素数
*/

     int Mark[MAXSIZE];  
    int prime[MAXSIZE];  
      
    //判断是否是一个素数  Mark 标记数组 index 素数个数  
    int Prime(){  
        int index = 0;  
        memset(Mark,0,sizeof(Mark));  
        for(int i = 2; i < MAXSIZE; i++)  
        {  
            //如果未标记则得到一个素数  
            if(Mark[i] == 0){  
                prime[index++] = i;  
            }  
            //标记目前得到的素数的i倍为非素数  
            for(int j = 0; j < index && prime[j] * i < MAXSIZE; j++)  
            {  
                Mark[i * prime[j]] = 1;  
                if(i % prime[j] == 0){  
                    break;  
                }  
            }  
        }  
        return index;  
    }  
/*
	质因数的分解
*/
    #include <cstdio>  
    #include <cstring>  
    #include <cmath>  
    #include <iostream>  
    using namespace std;  
    const int MAXN=10000;  
    int prime[MAXN+1];  
    int nprime;  
    void getPrime(){  
        int m=sqrt(MAXN+0.5);  
        memset(prime,0,sizeof(prime));  
        for(int i=2;i<=m;++i)if(!prime[i])  
            for(int j=i*i;j<=MAXN;j+=i) prime[j]=1;  
        nprime=0;  
        for(int i=2;i<=MAXN;++i){  
            if(!prime[i])  
                prime[nprime++]=i;  
        }  
    }  
    int e[MAXN+1];  
    void add_integer(int n,int d){  
        for(int i=0;i<nprime;i++){  
            while(n%prime[i]==0){  
                n/=prime[i];  
                e[i]+=d;  
            }  
            if(n==1) break;  
        }  
    }  
    void add_factorial(int n,int d){  
        for(int i=1;i<=n;i++)  
            add_integer(i,d);  
    }  
    int main(){  
        getPrime();  
        int p,q,r,s;  
        while(scanf("%d%d%d%d",&p,&q,&r,&s)!=EOF){  
            memset(e,0,sizeof(e));  
            add_factorial(p,1);  
            add_factorial(q,-1);  
            add_factorial(p-q,-1);  
            add_factorial(r,-1);  
            add_factorial(s,1);  
            add_factorial(r-s,1);  
            int maxn=max(p,r);  
            double ans=1;  
            for(int i=0;i<=maxn;i++){  
                ans*=pow(prime[i],e[i]);  
            }  
            printf("%.5lf\n",ans);  
        }  
        return 0;  
    }  
/***************************************************************
						DandC
***************************************************************/

/*
	矩阵的快速幂
*/

const int mat_size = 40 * 2;//矩阵大小，需要乘以2，为了&运算的时候需要二倍的矩阵大小  
struct Matrix  
{  
        unsigned long long a[mat_size][mat_size];  
        int x, y;//x-row  y-column  
        Matrix()    //返回0矩阵  
        {  
            memset(a,0,sizeof(a));  
        }  
        Matrix(int x,int y)//返回0矩阵，并且x,y赋值  
        {  
            this->x = x;  
            this->y = y;  
            memset(a, 0,sizeof(a));  
        }  
      
        Matrix(int n)   //返回n*n的【单位矩阵】  
        {  
            this->x=n;  
            this->y=n;  
            memset(a,0,sizeof(a));  
            for (int i = 0; i <n;++i)    a[i][i]=1;  
        }  
        Matrix operator * (const Matrix &B)//矩阵乘法  
        {  
            Matrix tmp;  
            for (int i = 0; i < x; ++ i)  
                for (int j = 0; j < B.y; ++ j)  
                {  
                    tmp.a[i][j] = 0;  
                    for (int k = 0; k < y; ++ k)  
                    {  
                        tmp.a[i][j] = (tmp.a[i][j] + a[i][k] * B.a[k][j]);  
                    }  
                }  
            tmp.x = x;  
            tmp.y=B.y;  
            return tmp;  
        }  
      
        Matrix operator ^ (int b)//矩阵A的b次方  
        {  
            Matrix ret = Matrix(x);    
            Matrix A = *this;  
            while( b )    
            {    
                if( b & 1 ) ret = ret * A ;    
                b >>= 1 ;    
                A = A * A ;    
            }    
            return ret ;    
        }  
        Matrix operator & (int b)//A^0 +A^1+A^2+A^3+++A^n，其中A是矩阵。最后返回的就是一个矩阵  
        {  
            Matrix ret = *this;  
            for (int i = ret.x; i < ret.x * 2; ++ i)   
            {  
                ret.a[i-ret.x][i]= 1;  
                ret.a[i][i] = 1;  
            }
            ret.x <<= 1;ret.y <<= 1;
            /*
            to:    A  I   
				   0  I
            */  
            ret = ret^b;  
            ret.x >>= 1;  ret.y >>= 1; 
            for (int i = 0; i < ret.x; ++ i)   
                for (int j = 0; j < ret.y; ++ j)  
                    ret.a[i][j] += ret.a[i][j + ret.x];  
            return ret;
        }
};
//使用时调用Matrix 即可  a^1,  
/*
	FFT
*/

struct complex
{
	double r,i;
	complex(double _r=0,double _i=0)
	{r=_r,i=_i;}
	complex operator +(const complex &a)const
	{
		return complex(r+a.r,i+a.i);
	}
	complex operator -(const complex &a)const 
	{
		return complex(r-a.r,i-a.i);
	}
	complex operator *(const complex &a)const 
	{
		return complex(a.r*r-a.i*i,a.i*r+a.r*i);
	}
};
complex va[maxn];

void change(complex y[],int len)
{
    int i,j,k;
    for(i = 1,j=len/2;i < len-1;i++)
    {
        if(i < j)swap(y[i],y[j]);
        k = len/2;
        while( j >= k)
        {
            j -= k;
            k /= 2;
        }
        if(j < k)j += k;
    }
}
//here 1 fft -1 rfft

void fft(complex y[],int len,int on)
{
    change(y,len);
    for(int h = 2;h <= len;h <<= 1)
    {
        complex wn(cos(-on*2*PI/h),sin(-on*2*PI/h));
        for(int j = 0;j < len;j += h)
        {
            complex w(1,0);
            for(int k = j;k < j+h/2;k++)
            {
                complex u = y[k];
                complex t = w*y[k+h/2];
                y[k] = u+t;
                y[k+h/2] = u-t;
                w = w*wn;
            }
        }
    }
    if(on == -1)
        for(int i = 0;i < len;i++)
            y[i].r /= len;
}
void init(ll *s1)
{
	len=1;
	MEM(va,0);MEM(cc,0);
	while(len<2*n1)len<<=1;
	for(int i=0;i<n1;i++)
		va[i]=complex(nm[i],0);
	for(int i=n1;i<len;i++)
		va[i]=complex(0,0);
}

/***************************************************************
						String
***************************************************************/
/*
	Manacher
*/
inline int Manacher(char *s)
{
	int id=0,len=strlen(s),maxlen=0;
	for(int i=len;i>=0;--i){//插入'#'  
            s[i+i+2]=s[i];
            s[i+i+1]='#';
        }//插入了len+1个'#',最终的s长度是1~len+len+1即2*len+1,首尾s[0]和s[2*len+2]要插入不同的字符   
        s[0]='*';//s[0]='*',s[len+len+2]='\0',防止在while时p[i]越界  
        for(int i=2;i<2*len+1;++i)
        {  
            if(p[id]+id>i)p[i]=min(p[2*id-i],p[id]+id-i);
            else p[i]=1;  
            while(s[i-p[i]] == s[i+p[i]])++p[i];  
            if(id+p[id]<i+p[i])id=i;  
            if(maxlen<p[i])maxlen=p[i]; 
        } 
    return maxlen-1;
}


/*
	KMP  其中A较长的字符串,s是模式串
	O(N+M)
*/

int nxt[maxn];
void nxt(char *s)  
{  
	int ls=strlen(s);
    memset(nxt,0,sizeof(nxt));  //根据其前一个字母得到  
    for(int i=1;i<ls;i++)  
    {  
        int j=nxt[i];  
        while(j && s[i]!=s[j])  
            j=nxt[j];  
        nxt[i+1]=(s[i]==s[j])?j+1:0;  
    }  
}  
int find(char *a,char * s)  
{  
    int ans=0;  
	int la=strlen(a),ls=strlen(s);
    get_nxt(s);int j=0;  
    for(int i=0;i<la;i++)  
    {  
        while(j && a[i]!=s[j])  
            j=nxt[j];  
        if(a[i]==s[j])  
            j++;  
        if(j==ls)//s的所有字符都与a的子串匹配上了
		{  
            ans++;  
        }  
    }
    return ans;  
}


/*
	exKMP	定义extend[i]等于S[i]...S[n-1]与T的最长公共前缀的长度
	如果extend[i]为最长公共前缀的长度就是T的长度,也就是说在这个位置与母串匹配了
*/
int nxt[maxn],extend[maxn];
void get_nxt(char *T)
{
	int len=strlen(T),p=0,a=0;
	nxt[0]=len;
	for(int i=1;i<len;i++)
	{
		 if (i >= p || i + nxt[i - a] >= p)
        {
            if (i >= p)
                p = i;
            while (p < len && T[p] == T[p - i])
                p++;
            nxt[i] = p - i;
            a = i;
        }
        else
            nxt[i] = nxt[i - a];
	}
}

void get_extend(char *S,char *T)
{
	int a = 0, p = 0,m=strlen(T),n=strlen(S);
    get_nxt(T);
    for (int i = 0; i < n; i++)
    {
        if (i >= p || i + nxt[i - a] >= p) // i >= p 的作用：举个典型例子，S 和 T 无一字符相同
        {
            if (i >= p)
                p = i;
            while (p < n && p - i < m && S[p] == T[p - i])
                p++;
            extend[i] = p - i;
            a = i;
        }
        else extend[i] = nxt[i - a];
    }
}

/*
	AC -automation
*/
class AC
{
public:
	int cnt[maxn],tag[maxn],fail[maxn];
	int ch[maxn][27];
	int sz;
	void init()
	{
		sz=1;
		MEM(ch[0],0);MEM(tag,0);MEM(fail,0);
	}
	void insert(char *str)
	{
		int len=strlen(str),ps=0;
		for(int i=0;i<len;i++)
		{
			int id=str[i]-'a';
			if(!ch[ps][id]){
				MEM(ch[sz],0);ch[ps][id]=sz++;
			}
			ps=ch[ps][id];
		}
		tag[ps]++;
	}
	void build()
	{
		int que[maxn],head=0,tail=0;
		for(int i=0;i<MAG;i++)
			if(ch[0][i])
				que[head++]=ch[0][i];
		while(head!=tail)
		{
			int fa=que[tail++];
			if(tag[fail[fa]]>0)
				tag[fa]=1;
			for(int i=0;i<MAG;i++)
			{
				if(!ch[fa][i])
					ch[fa][i]=ch[fail[fa]][i];
				else
				{
					int tmp=fail[fa];
					while(tmp!=0&&!ch[tmp][i])
						tmp=fail[tmp];
					fail[ch[fa][i]]=ch[tmp][i];
					que[head++]=ch[fa][i];
				}	
			}
		}
	}
	void query(char *T)
	{
		int len=strlen(T),ct=0,ps=0,ans=0;
		for(int i=0;i<len;i++)
		{
			int id=T[i];
			if(ch[ps][id]!=0)
				ps=ch[ps][id];
			else
			{
				while(ch[ps][id]==0&&ps!=0)  //lose it
					ps=fail[ps];
				//here  is not ps cuz we want to go to it's child
				ps=(ch[ps][id]==0?0:ch[ps][id]);
			}
			int tmp=ps;
			while(tmp!=0&&exist[tmp]>0)
			{
				aa[ct++]=exist[tmp];	//这里exist是匹配末端的编号
				tmp=fail[tmp];
			}
		}
	}
	ll count_it()
	{
		Matrix mat(sz,sz);
		for(int i=0;i<sz;i++)
			for(int j=0;j<MAG;j++)
				if(!tag[i]&&!tag[ch[i][j]])
					mat.a[ch[i][j]][i]++;
		//get col 1
		mat=mat&L;
		ll aa=0;
//		pg(mat);
		for(int i=0;i<mat.x;i++)
			aa+=mat.a[i][0];
		Matrix tmp=Matrix(2,2);
		tmp.a[0][0]=26;tmp.a[0][1]=1;tmp.a[1][1]=1;
		tmp=tmp^L;
		ll tt=tmp.a[0][0]+tmp.a[0][1];
		return tt-aa;
	}
}ac;


/*
	SA-is
*/
int wsf[maxn],sa[maxn],wa[maxn],wb[maxn],wv[maxn];
int rank[maxn],height[maxn],s[maxn],ST[maxn][30];
int cmp(int *r,int a,int b,int k){
	return r[a]==r[b]&&r[a+k]==r[b+k];
}
void getsa(int *r,int *sa,int n,int m)
{
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0;i<m;i++)  wsf[i]=0;
    for(i=0;i<n;i++)  wsf[x[i]=r[i]]++;
    for(i=1;i<m;i++)  wsf[i]+=wsf[i-1];
    for(i=n-1;i>=0;i--)  sa[--wsf[x[i]]]=i;
    p=j=1;
    for(;p<n;j*=2,m=p)
    {
        for(p=0,i=n-j;i<n;i++)  y[p++]=i;
        for(i=0;i<n;i++)  if(sa[i]>=j)  y[p++]=sa[i]-j;
        for(i=0;i<n;i++)  wv[i]=x[y[i]];
        for(i=0;i<m;i++)  wsf[i]=0;
        for(i=0;i<n;i++)  wsf[wv[i]]++;
        for(i=1;i<m;i++)  wsf[i]+=wsf[i-1];
        for(i=n-1;i>=0;i--)  sa[--wsf[wv[i]]]=y[i];
        t=x;x=y;y=t;
        x[sa[0]]=0;
        for(p=1,i=1;i<n;i++)
        x[sa[i]]=cmp(y,sa[i-1],sa[i],j)? p-1:p++;
    }
}
void getheight(int *r,int n)
{
    int i,j,k=0;
    for(i=1;i<=n;i++)  rank[sa[i]]=i;
    for(i=0;i<n;i++)
    {
        if(k)k--;
        else k=0;
        j=sa[rank[i]-1];
        while(r[i+k]==r[j+k])
        	k++;
        height[rank[i]]=k;
    }
}

/*
	最小表示法
s="00ab"
变形有（省略引号）b00a ab00 0ab0
一共4种
那么找到其中字典序最小的一个，用的算法便是这个  mr最小  ,lr最大
	O(N)
*/
void Min_Repre(int op)
{
	int len=strlen(str),i=0,j=1,k=0;
	while(i<len&&j<len&&k<len)
	{
		int t=str[(i+k)%len]-str[(j+k)%len];
		if(t==0)k++;
		else
		{
			if(t>0)op==0?i+=k+1:j+=k+1;
			else op==0?j+=k+1:i+=k+1;
			if(i==j)j++;
			k=0;
		}
	}
	if(op==0)mr=i<j?i+1:j+1;
	else lr=i>j?j+1:i+1;
}
/*
	shift-and alorithm
*/
//暂时似乎用不到
/**************************************************************
					计算几何
***************************************************************/
/*
	Andrew Algorithm
*/

/***********************************************************
	STL 用法实例
最常用的有stl的map,set
*************************************************************/

//insert 方法1 ::value_type;
studentMessage.insert(map<int,string>::value_type(54090103,"Jake"));
//insert 方法2 


/***********************************************************
	其他问题
*************************************************************/
/*
	集合上的计数问题  tzcxsj
*/

/*
	Gauss-Jocobi消元,以及xor方程
*/
//白书p
/*
	自适应Simpson计算数值积分
*/


//白书上p

/*
	读写优化(针对正整数数字型输入)
	使用put,getchar,比printf(),scanf()更快,更节省内存
*/
#include <cctype>
int readint()
{
	char c=getchar();
	while(!isdigit(c))c=getchar();
	
	int x=0;
	while(isdigit(c))
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
void writeint(int i)
{
	int p=0;
	if(i==0)p++;//特判
	while(i!=0)
	{
		buff[p++]=i%10;
		i/=10;
	}
	for(int i=p-1;i>=0;i--)puts('0'+buff[i]);//逆序输出,因为十进制处理的问题
}
//example
int mian()
{
	while(n=readint())
	{
		a=readint();
	}
}
