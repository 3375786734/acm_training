#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
using namespace std;

struct Node{
	int x,y;
	bool operator<(const Node &a)const{
		return x<a.x;
	}
};
Node nn[3];
int main()
{
	priority_queue<Node> qq;
	qq.push((Node){2,1});
	qq.push((Node){1,2});
	qq.push((Node){3,2});
	while(!qq.empty()){
		printf("%d\n",(qq.top()).x);qq.pop();
	}
}
