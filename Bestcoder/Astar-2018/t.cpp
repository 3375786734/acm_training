#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int > PP;
set<PP> ss;

int main()
{
	ss.insert(PP(1,2));
	ss.insert(PP(2,1));
	ss.insert(PP(1,3));
	printf("%d\n",ss.size());
}
