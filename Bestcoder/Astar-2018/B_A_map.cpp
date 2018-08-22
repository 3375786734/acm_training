/*we use map here to avoid MLE ,cuz map can open the space only when is needed
 *
 */
#include <bits/stdc++.h>
using namespace std;
map <int,deque<int>> mm;
int N,Q;
int main()
{
	while(~scanf("%d%d",&N,&Q)){
		mm.clear();
		for(int i=0;i<Q;i++)
		{
			int u,w,op,a;
			scanf("%d%d%d",&op,&u,&w);
			if(op==1){
				scanf("%d",&a);
				if(w==0)
					mm[u].push_front(a);
				else mm[u].push_back(a);
			}
			if(op==2){
				if(!mm[u].empty()){
					if(w==0){
						printf("%d\n",mm[u].front());
						mm[u].pop_front();
					}
					else{
						printf("%d\n",mm[u].back());
						mm[u].pop_back();
					}
				}
				else printf("-1\n");
			}
			if(op==3){
				scanf("%d",&a);
				if(a==0){
					mm[u].insert(mm[u].end(),mm[w].begin(),mm[w].end());
					mm[w].clear();
				}
				else {
					mm[u].insert(mm[u].end(),mm[w].rbegin(),mm[w].rend());
					mm[w].clear();
				}
			}
		}
	}
}
