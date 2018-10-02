/*
 *idea:brute force  .enumerate the alphabet
 *十分精妙的暴力方法:固定右端点,那么左边由于形成的字母集最大是26,我们考虑离散化.每个字母中,离当前第一个不相同的字母之间的距离即我们需要求的距离,即pos[alpha].注意到我们对26个字母进行状态压缩的话数组存不下,可以使用hash映射一下即可.hash的容量注意到每个元素位置最多可以产生26种新的状态,因此最多26*1e5种.
 *
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn=;
int main()
{
	freopen("jingles.in","r",stdin);
	freopen("jingles.out","w",stdout);
	scanf("%d",&TestCase);
	for(int CaseCnt=1;CaseCnt<=TestCase;CaseCnt++)
	{
		char str[maxn];
		int ans=0;
		scanf("%s",str);
		int Slen=strlen(str)
		for(int i=0;i<Slen;i++){
			
		}
		
		printf("%d\n",ans);
	}
}
