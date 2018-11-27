
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
 
using namespace std;
 
int used[1001];
int prim[1001];
 
int main()
{
	memset( used, 0, sizeof(used) );
	int count = 0;
	prim[count ++] = 1;
	for ( int i = 2 ; i <= 1000 ; ++ i )
		if ( !used[i] ) {
			prim[count ++] = i;
			for ( int j = i<<1 ; j <= 1000 ; j += i )
				used[j] = 1;
		}
	prim[count] = 1001;
	
    int n,m;
    while ( ~scanf("%d%d",&n,&m) ) {
		printf("%d %d:",n,m);
		int r = 0;
		while ( prim[r+1] <= n ) r ++;
		int mid = r/2;
		int l = mid;
		r = mid+(r%2);
		while ( -- m ) {
			l --; r ++;
			if ( l < 0 ) l ++;
			if ( prim[r] > n ) r --;
		}
		while ( l <= r )
			printf(" %d",prim[l ++]);
		printf("\n\n");
    }
    return 0;
}

--------------------- 
作者：小白菜又菜 
来源：CSDN 
原文：https://blog.csdn.net/mobius_strip/article/details/33522257 
版权声明：本文为博主原创文章，转载请附上博文链接！
