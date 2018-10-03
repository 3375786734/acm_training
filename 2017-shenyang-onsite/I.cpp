#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		unsigned long long a,b,c,d;
		cin>>a>>b>>c>>d;
		if(a==b&&b==c&&c==d&&a==(unsigned long long)4611686018427387904)
			cout<<"18446744073709551616"<<endl;
		else cout<<a+b+c+d<<endl;
	}
}
