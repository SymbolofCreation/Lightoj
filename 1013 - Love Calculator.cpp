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

#define         sf              scanf
#define         pf              printf
#define         sf1(a)          scanf("%d",&a)
#define         sf2(a,b)        scanf("%d %d",&a,&b)
#define         sf3(a,b,c)      scanf("%d %d %d",&a,&b,&c);
#define         sfl1(a)         scanf("%lld",&a)
#define         sfl2(a,b)       scanf("%lld %lld",&a,&b)
#define         sfl3(a,b,c)     scanf("%lld %lld %lld",&a,&b,&c);

#define         pro             printf("PRINT  ::  DEBUG\n")
#define         pcase           printf("Case %d: ",kase++)

// constants

#define         INF             (1 << 29)

#define         ll              long long int
#define         pii             pair<int,int>

//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

using namespace std;

int kase=1;
ll dp[40][40];
ll dp2[40][40][40];

string a,b;

inline void reset()
{
    for(int i=0; i<40; i++)
    {
        for(int j=0; j<40; j++)
        {
            for(int k=0; k<40; k++)
            {
                dp[i][j] = -1;
                dp2[i][j][k] = -1;
            }
        }
    }
}

inline ll LCS(int i,int j)
{
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(i>=a.size() || j>=b.size())
        return 0ll;

    ll ret;
    if(a[i]==b[j])
        ret = 1ll + LCS(i+1,j+1);
    else
        ret = max(LCS(i+1,j),LCS(i,j+1));

    return dp[i][j] = ret;
}

inline ll Ways(int i,int j,int lcs)
{
    if(i>=a.size() && j<b.size())
        return Ways(i,j+1,lcs-1);
    if(i<a.size() && j>=b.size())
        return Ways(i+1,j,lcs-1);
    if(i==a.size() && j==b.size())
    {
        if(lcs==0)
            return 1ll;
        return 0ll;
    }

    if(dp2[i][j][lcs]!=-1)
        return dp2[i][j][lcs];

    ll ret;
    if(a[i]==b[j])
        ret = Ways(i+1,j+1,lcs-1);
    else
        ret = Ways(i+1,j,lcs-1) + Ways(i,j+1,lcs-1);

    return dp2[i][j][lcs] = ret;
}

int main()
{
//    freopen (".in", "r", stdin);
//    freopen (".out", "w", stdout);

    int test;
    cin >> test;
    while(test--)
    {
        cin >> a >> b;
        reset();
        ll ans1 = LCS(0,0);
        ans1 = a.size()+b.size()-ans1;
        ll ans2 = Ways(0,0,ans1);
        pcase;
        cout << ans1 << " " << ans2 << endl;
    }

    return 0;
}
