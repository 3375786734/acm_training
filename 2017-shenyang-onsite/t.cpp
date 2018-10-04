#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int x,y;
	Node operator- (const Node &a)const{
		return (Node){x-a.x,y-a.y};
	}
};
int main()
{
	Node a=(Node){1,1},b=(Node){2,2},c=a-b;
	printf("%d\n",c.x);
}
