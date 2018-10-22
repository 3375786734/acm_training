/*
 *IDEA:直观上,对称的放是最优的,因此我们将其进行排序,每次放大的一边即可.
 *详见代码怎么操作:直观上,你一个积木一个积木的填到球的最里面直到与前面的积木碰到一起了,或者你碰到球了为止
 */

#include <bits/stdc++.h>
using namespace std ;
 
typedef long long LL ;
 
const int Maxn = 100005 ;
const double eps=1e-10;
double a[Maxn],ned[Maxn];
int n;
double sqr(double x){return x*x;}
int dcmp(double x){if(fabs(x)<eps)return 0;if(x>eps)return 1;return -1;}
bool check(double md){
    for(int i=0;i<n;i++){
        if(dcmp(md*md-a[i])<=0)return 0;
    }
	//l是半径大的一边.
    double l=md,r=md;
    for(int i=0;i<n;i++){
        if(l<r)swap(l,r);
        l=min(l,sqrt(md*md-a[i]));
        if(dcmp(l-1)>=0){l-=1;continue;}
        else{
			//将最后一块积木挤在中间,如果挤不下去(太大了或者宽度不够那么就退出)
            if(dcmp(l+r-1)<0)return 0;
            if((1-l)*(1-l)+a[i]>md*md)return 0;
            if(i!=(n-1))return 0;
        }
    }
    return 1;
}
void solve () {
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        double x,y;
        scanf("%lf%lf",&x,&y);
        a[i]=min(sqr(x)+sqr(y/2),sqr(y)+sqr(x/2));
    }
    sort(a,a+n);
    double l=0,r=1e6;
    for(int i=0;i<200;i++){
        double md=(l+r)/2;
        if(check(md))r=md;
        else l=md;
    }
    printf("%.12f\n",r);
     
}
 
int main () {
    int T ;
    scanf ( "%d" , &T ) ;
    for ( int i = 1 ; i <= T ; ++ i ) {
        printf ( "Case #%d: " , i ) ;
        solve () ;
    }
    return 0 ;
}
