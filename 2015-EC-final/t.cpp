#include <bits/stdc++.h>
using namespace std;
struct Eg{
	int u,v;
	Eg(int u,int v):u(u),v(v){}
	bool operator<(const Eg &a)const{
		return u==a.u?v<a.v:u<a.u;
	}
};
map<Eg,int >  egmp;
int main()
{
	list<int> st;
	st.push_back(1);
	st.push_back(2);
	printf("%d\n",st.back());
	st.pop_back();
	printf("%d\n",st.back());
	egmp[Eg(1,1)]=1;
}
