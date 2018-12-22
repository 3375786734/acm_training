/*  -*- coding: utf-8 -*- */
#include <bits/stdc++.h>
#define MEM(a,num) memset(a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define pb push_back
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> PP;
//const double esp=1e-6
const int maxn =1e2+100;
const double eps =1e-6;

class Matrix{
public:
	double mat[maxn][maxn];
	int n,m;
	Matrix(){n=m = 0;MEM(mat,-1);}
	Matrix operator +(const Matrix &a)const{
		Matrix tmp ;
		if(a.n !=n||a.m!= m)
			printf("Can not add\n");
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				tmp[i][j] = a.mat[i][j] +mat[i][j] ;
		tmp.n = n ,tmp.m  = m;
		return tmp;
	}
	bool operator==(const Matrix &a)const{
		if(a.m!=m||a.n!=n)return false;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(a.mat[i][j]!= mat[i][j])return false;
		return true;
	}
	Matrix t()
	{
		Matrix tmp;
		tmp.n = m ; tmp.m = n;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				tmp.mat[i][j] = mat[j][i];
		return tmp ;
	}
	Matrix operator *(const Matrix &a)const{
		Matrix tmp ;
		if(a.n!=m)
			printf("Can not multiply\n");
		else{
			for(int i=0;i<n;i++)
				for(int j =0;j<a.m;j++){
					for(int k =0;k<m;k++)
						tmp[i][j] += mat[i][k]*a.mat[k][j];
				}
			tmp.n =n ,tmp.m = a.m;
		}
		return tmp;
	}
	void input_m()
	{
		scanf("%d%d",&n,&m);
		printf("here\n");
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				scanf("%lf",&mat[i][j]);
	}
	void elimi(int i,int j)
	{
		int ps =0;while(mat[i][ps]==0)ps++;

		if(ps<m&&fabs(mat[j][ps])>eps){
			double coeff= mat[j][ps]/mat[i][ps];
			for(int k = ps;k<m;k++)
				mat[j][k] -= mat[i][k]*coeff;
		}
	}
	vector<double> Gauss_eliminate()
	{
		int vis[maxn];MEM(vis,0);

		vector<int> col;
		vector<double> pivot;
		for(int i=0;i<n;i++){
			int flag =0;
			for(int j =0;j<n;j++)
				if(!vis[j]&fabs(mat[j][i])>eps){
					col.pb(j);
					flag = 1;vis[j] =1;
					break;
				}
			if(flag == 0){
				for(int j=0;j<n;j++)
					if(!vis[j]){
						col.pb(j);
						vis[j] =1;
					}
			}
		}
		int sz = col.size();
		for(int i=0;i<sz;i++)
			for(int j=i+1;j<sz;j++){
				elimi(col[i],col[j]);
			}
		for(int i=0;i<sz;i++)
			pivot.pb(mat[i][i]);
		return pivot;
	}
	int get_rank()
	{
		int cnt =0;
		vector<double> pivot = Gauss_eliminate();
		for(double it:pivot)
			if(fabs(it)!=0)cnt++;
		return cnt;
	}
	void pf()
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				printf("%lf%c",mat[i][j],j==m-1?'\n':' ');
	}
};
int main()
{
	Matrix a,b;
	int k =0;
	scanf("%d",&k);a.m = a.n = b.m = b.n =k;
	for(int j=0;j<(1<<(k*k));j++)	
		for(int i=0;i<(1<<(k*k));i++){
			for(int p = 0;p<k;p++)
				for(int q=0;q<k;q++){
					if((1<<(p*k+q))&i)a.mat[p][q] =1;
					else a.mat[p][q] =0;
				}
			for(int p =0;p<k;p++)
				for(int q= 0;q<k;q++)
					if((1<<(p*k+1))&&j)b.mat[p][q] =1;
					else b.mat[p][q] = 0;
			if(a.t()*b == 0){
				if(a.get_rank()+b.get_rank()!= (a+b).get_rank()){
					printf("Find a example\n");
				}
			}
		}
	printf("Can not find ont\n");
}

