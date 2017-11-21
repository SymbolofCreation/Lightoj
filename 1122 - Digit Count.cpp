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

#define ll long long int
#define pii pair<int,int>

//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

using namespace std;

int kase=1,n,m;
int dig[15];
ll dp[15][15];

void reset()
{
    memset(dp,-1,sizeof(dp));
}

ll getans(int pos,int taken)
{
    if(pos>=n)
        return 1ll;
    if(taken!=-1 && dp[pos][taken]!=-1)
        return dp[pos][taken];

    ll ret = 0;
    for(int i=0; i<m; i++)
    {
        if(taken==-1 || (abs(taken-dig[i])<=2))
            ret += getans(pos+1,dig[i]);
    }

    return dp[pos][taken] = ret;
}

int main()
{
//    freopen (".in", "r", stdin);
//    freopen (".out", "w", stdout);

    int test;
    cin >> test;

    while(test--)
    {
        reset();
        cin >> m >> n;
        for(int i=0; i<m; i++)
            cin >> dig[i];
        ll ans = getans(0,-1);
        pcase;
        cout << ans << endl;
    }

    return 0;
}
