#include <bits/stdc++.h>
using namespace std;
const int maxn=150;
typedef struct Point
{
	int x, y;
	Point() {}
	Point(int x, int y): x(x),y(y) {}
	Point operator + (const Point &b) const {  return Point(x+b.x,y+b.y);  }
	Point operator - (const Point &b) const {  return Point(x-b.x,y-b.y);  }
	int operator * (const Point &b) const {  return x*b.y-y*b.x;  }
	int len() const {  return x*x+y*y;  }
	int operator < (const Point &a) const
	{
		if((*this)*a>0 || (*this)*a==0 && len()<a.len())
			return 1;
		return 0;
	}
}Point;
int n;
Point s[maxn], p[maxn];
int dp[maxn][maxn];
double Jud(int m)
{
	int ans, i, j, now, k, flag, S;
	memset(dp, 0, sizeof(dp));
	ans = 0;
	for(i=2;i<=m;i++)
	{
		now = i-1;
		while(now>=1 && p[i]*p[now]==0)
			now--;
		flag = 0;
		if(now==i-1)
			flag = 1;
		while(now>=1)
		{
			S = p[now]*p[i];
			k = now-1;
			while(k>=1 && (p[now]-p[i])*(p[k]-p[now])>0)
				k--;
			if(k>=1)
				S += dp[now][k];
			if(flag)
				dp[i][now] = S;
			ans = max(ans, S);
			now = k;
		}
		if(flag==0)
			continue;
		for(j=1;j<=i-1;j++)
			dp[i][j] = max(dp[i][j],dp[i][j-1]);
	}
	return ans/2.0;
}
int main(void)
{
	int T, i, j, m;
	scanf("%d", &T);
	while(T--)
	{
		double ans=0;
		scanf("%d", &n);
		for(i=1;i<=n;i++)
			scanf("%d%d", &s[i].x, &s[i].y);
		ans = 0;
		for(i=1;i<=n;i++)
		{
			m = 0;
			for(j=1;j<=n;j++)
			{
				if(s[j].y>s[i].y || s[j].y==s[i].y && s[j].x>=s[i].x)
					p[++m] = s[j]-s[i];
			}
			sort(p+1, p+m+1);
			ans = max(ans, Jud(m));
		}
		printf("%.1f\n", ans);
	}
	return 0;
}
