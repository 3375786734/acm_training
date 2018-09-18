/*
 *题意要求一个括号序列的平均入栈到出栈的时间
 * idea:常规想法是按每个序列进行统计求出入栈时间的总和
 * 换一种想法,由于如果固定一个括号对,其时间是非常容易求的
 * 因此如果按(i,j)的等待时间进行求和,那么计算将变得容易
 * 具体的(i,j)固定,那么合法的序列有Catalan(len-1)*Catalan(N-len)个,其中len对应这(i,j)序列长度为2*len,中间的必须要匹配,因此固定长度(i,j),时间是dtim*Catalan(len-1)*Catalan(N-len)
 *然后注意到长度为2×len的括号对的等待时间可以用前缀和表示,因此问题的求解变得十分容易了
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		
	}

}
