/*
 *IDEA:在一条直线上,每新来一个,就站在中间即可,十分简单.
 *trick
 */
#include <bits/stdc++.h>
using namespace std;
int N,M;
char ask(int ps){
	char lebel[50];
	printf("%d %d\n",ps,0);
	fflush(stdout);
	scanf("%s",lebel);
	return lebel[0];
}
int main()
{
	int N;
	scanf("%d",&N);
	char pre=ask(0);
	int l = 0, r = 1e9,lt=pre=='w'?0:1;
	while(--N){
		int mid = (l+r)/2;
		//printf("here %d\n",N);
		char tag = ask(mid);
		if((tag=='w'&&lt==0)||(tag=='b'&&lt==1))
			l=mid+1;
		else r = mid-1;
	}
	printf("%d %d %d %d\n",(l+r)/2,2,(l+r)/2,1);
	fflush(stdout);
}
