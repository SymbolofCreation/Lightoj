/*
ID: protikn2
PROG: test
LANG: C++14
*/

//#include <bits/stdc++.h>

#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<deque>
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
#include<climits>
#include<cassert>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

//  scan & print

#define sf scanf
#define pf printf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c);
#define sfl1(a) scanf("%lld",&a)
#define sfl2(a,b) scanf("%lld %lld",&a,&b)
#define sfl3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c);

#define pro printf("1\n")
#define pcase printf("Case %d: ",kase++)

// constants

#define INF 9999999
#define mod 100000007

#define ll long long int
#define pii pair<int,int>

//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

using namespace std;

int kase=1,n,k;

int a[51],NumberofCoins[51];
ll dp[55][1005];

ll rec(int pos,int sum)
{
    if(pos>n || sum>k)
        return 0;
    if(pos==n)
    {
        if(sum==k)
            return 1;
    }
    if(dp[pos][sum]!=-1)
        return dp[pos][sum];
    ll ans = 0;
    for(int i=0; i<=NumberofCoins[pos]; i++)
    {
        ans = ((ans%mod)+(rec(pos+1,(sum+(i*a[pos]))))%mod)%mod;
    }
    dp[pos][sum] = ans;
    return dp[pos][sum];
}

int main()
{
//    freopen (".in", "r", stdin);
//    freopen (".out", "w", stdout);

    int test;
    sf1(test);

    while(test--)
    {
        sf2(n,k);

        for(int i=0; i<n; i++)
            sf1(a[i]);
        for(int i=0; i<n; i++)
            sf1(NumberofCoins[i]);

        memset(dp,-1,sizeof(dp));

        pcase;
        pf("%lld\n",rec(0,0));
    }

    return 0;
}
