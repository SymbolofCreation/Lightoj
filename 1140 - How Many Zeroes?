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
#define pcase printf("Case %lld: ",kase++)

// constants

#define INF 9999999

#define ll long long int
#define pii pair<ll,ll>

//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

using namespace std;

ll kase=1,a,b;
ll dp[50][50];

void getdig(ll a, vector<int> &digit)
{
    while(a)
    {
        ll x = a%10;
        digit.push_back(x);
        a /= 10;
    }
}

ll solve(int index,int sum,int tight,int taken,vector<int> &v)
{
    if(index==-1)
        return sum;

    if(dp[index][sum]!=-1 && tight!=1 && taken)
        return dp[index][sum];

    int k = tight ? v[index] : 9;

    ll ret = 0;

    for(int i=0; i<=k; i++)
    {
        ll new_tight = tight? (v[index]==i) : 0;

        if(i==0)
        {
            if(!taken)ret += solve(index-1,sum,new_tight,0,v);
            else ret +=  solve(index-1,sum+1,new_tight,1,v);
        }
        else
            ret += solve(index-1,sum,new_tight,1,v);
    }

    if(!tight && taken)
        dp[index][sum] = ret;
    return ret;
}

ll getans(ll a)
{
    if(a<0)
        return 0ll;
    if(a==0)
        return 1ll;

    vector<int> v;
    getdig(a,v);

    return solve(v.size()-1,0,1,0,v)+1ll;
}

void reset()
{
    memset(dp,-1,sizeof(dp));
}

int main()
{
//    freopen (".in", "r", stdin);
//    freopen (".out", "w", stdout);

    ll test;
    cin >> test;

    while(test--)
    {
        reset();
        cin >> a >> b;
        if(a>b)
            swap(a,b);
        a--;

        ll ans1 = getans(b);
        ll ans2 = getans(a);
        pcase;
        cout << ans1-ans2 << endl;
    }

    return 0;
}
