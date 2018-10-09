/*
 *idea:难点在于怎么放石子最优,考虑在已有的基础上,每次更新最大的那一个直到没有剩余的石子为止.
 *考虑最优问题时,尝试先排序,然后逐个求解
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+100;
int fac[maxn],a[maxn];
ll quality_fac[maxn],frequency[maxn];
int N,ss[maxn];
ll get_fac(ll n)
{
//n是待分解的数,quality_fac[]会存放它包含的质因子,而frequency[]存放对应次数
//如q_f[k]=7,fre[k]=2就表示质因数分解后里面包含有7,且次数是2
//函数返回有几种质因子,比如分解了25就返回1,分解28返回2
    ll res,temp,i;
    res=0;
    temp=n;
    for(i=2;i*i<=temp;i++)
        if(temp%i==0)
        {
            quality_fac[res]=i;
            frequency[res]=0;
            while(temp%i==0)
            {
                temp=temp/i;
                frequency[res]++;
            }
            res++;
        }
    if(temp>1)
    {
        quality_fac[res]=temp;
        frequency[res++]=1;
    }
    return res;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		ll sum=0,ans=1e12;
		for(int i=1;i<=N;i++){
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		
		int res=get_fac(sum);

		for(int i = 0;i<res;i++){
			memset(fac,0,sizeof(fac));
			int ff = quality_fac[i],check=0,sz=0;
			for(int j = 1;j <= N;j++){
				fac[a[j]%ff]++;
				check+=a[j]%ff;
				ss[sz++]=a[j]%ff;
			}
			sort(ss,ss+sz);
			sz=unique(ss,ss+sz)-ss;

			ll tmp=0;
			for(int  j = sz-1; j>=0 ; j--){
				if(check==0)break;
				tmp += (ff-ss[j])*fac[ss[j]];
				check-=fac[ss[j]]*ff;
			}
			ans = min(ans,tmp);
		}
		printf("%lld\n",ans);
	}
}
