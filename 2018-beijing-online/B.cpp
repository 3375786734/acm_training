#include <bits/stdc++.h>
using namespace std;
const int maxn=20;
string str[maxn];
set<string> ss;
map<string,int> mm;
int N;
int main()
{
	while(cin>>N){
		mm.clear();
		for(int i=0;i<N;i++)
			cin>>str[i];
		for(int i=0;i<N;i++){
			int len= str[i].length();
			ss.clear();
			for(int off=0;off<len;off++){
				for(int k=0;k<(1<<len);k++){
					string tmp;
					for(int b=0;b<len;b++)
						if((1<<b)&k){
							tmp=tmp+str[i][(b+off)%len];
						}
					ss.insert(tmp);
				}
			}
			for(set<string>::iterator it=ss.begin();it!=ss.end();it++){
				if(*it!="")mm[*it]++;
//				cout<<"str "<<str[i]<<" "<<*it<<endl;
			}
		}
		int ans=0,flag=0;
		map<string,int>::iterator it=mm.begin(),pos;
		for(;it!=mm.end();it++)
			if(it->second==N&&it->first.length()>ans){
				pos=it;
				flag=1;
				ans=it->first.length();
			}
//		printf("%d\n",ans);
		if(flag==1)cout<<pos->first<<endl;
		else printf("0\n");
	}
}
