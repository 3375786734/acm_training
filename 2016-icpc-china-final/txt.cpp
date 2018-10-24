#include <bits/stdc++.h>
using namespace std;
int lsp[maxn];
void get_lsp(char *pat)
{
	int len=0,i=1;
	int n = strlen(pat);
	lsp[0] = 0;  // ofcourse the proper of the first-latter is 0
	while(i<n){
		//if match continue;
		if(pat[i] == pat[len]){
			len++;
			lsp[i++] = len;
		}
		else{
			if(len != 0)
				len = lsp[len-1];
			else 
				lsp[i++] = 0; //mismatch init it
		}
	}
}
int KMP(char *pat,char *txt)
{
	get_lsp(pat);
	int txtid=0,patid=0;
	int M = strlen(txt) , N = strlen(pat);
	while(txtid<M){
		if(pat[patid] == txt[txtid]){
			patid++;txtid++;
		}
		if(patid == N){
			//printf("match here final positon is %d in text\n",txtid-1);
			mat_cnt++;
			patid = lsp[patid-1];
		}
		else if(txtid<M&&pat[patid]!=txt[txtid]){
			if(patid!=0)
				patid = lsp[patid -1];
			else txtid++;
		}
	}
	return mat_cnt;
}
int main()
{
	char pat[6]="ABA",txt[10]="ABABAAB";
	int ans=KMP(pat,txt);
	printf("%d\n",ans);
}
