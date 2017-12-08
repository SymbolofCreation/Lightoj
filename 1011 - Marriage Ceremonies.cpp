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
#include<iomanip>
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
#define maxx 16

#define ll long long int
#define pii pair<int,int>

//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

using namespace std;

int kase=1,n;
ll ara[17][17];
ll dp[maxx+1][1 << maxx];

ll rec(int pos,int mask)
{
    if(pos>=n)
        return 0ll;

    if(dp[pos][mask]!=-1)
        return dp[pos][mask];

    for(int i=0; i<n; i++)
    {
        if(!(mask & (1 << i)))   // Checking that is it visited or not. If this bit is off [mask & (1<<i)] == 0.
        {
            dp[pos][mask] = max(dp[pos][mask],ara[pos][i]+rec(pos+1,(mask | (1<<i))));  //  Making the bit visited.
        }
    }

    return dp[pos][mask];
}

int main()
{
//    freopen (".in", "r", stdin);
//    freopen (".out", "w", stdout);

    int test;
    cin >> test;

    while(test--)
    {
        memset(dp,-1,sizeof(dp));
        cin >> n;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin >> ara[i][j];
            }
        }

        ll ans = rec(0,0);
        pcase;
        cout << ans << endl;
    }

    return 0;
}
