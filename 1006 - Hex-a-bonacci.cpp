#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
#include<functional>
#define sf scanf
#define pf printf
#define pro printf("1\n")
using namespace std;
int a, b, c, d, e, f;
int dp[10010];
int fn( int n ) {
    if( n == 0 )
    {
        dp[0]=a%10000007;
        return dp[0];
    }
    if( n == 1 )
    {
        dp[1]=b%10000007;
        return dp[1];
    }
    if( n == 2 )
    {
        dp[2]=c%10000007;
        return dp[2];
    }
    if( n == 3 )
    {
        dp[3]=d%10000007;
        return dp[3];
    }
    if( n == 4 )
    {
        dp[4]=e%10000007;
        return dp[4];
    }
    if( n == 5 )
    {
        dp[5]=f%10000007;
        return dp[5];
    }
    if(dp[n]!=-1)return dp[n];
    dp[n]=( fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6) )% 10000007;
    return dp[n];
}
int main() {
    int n, caseno = 0, cases;
    scanf("%d", &cases);
    while( cases-- ) {
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        memset(dp,-1,sizeof(dp));
        printf("Case %d: %d\n", ++caseno, fn(n) % 10000007);
    }
    return 0;
}
