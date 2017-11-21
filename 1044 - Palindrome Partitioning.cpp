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

#define INF 99999999

#define ll long long int
#define pii pair<int,int>

//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

using namespace std;

int kase=1;

string s;
int dp[1005];

bool pal(int i,int j)
{
    while(i<=j)
    {
        if(s[i]!=s[j])
            return false;
        i++,j--;
    }
    return true;
}

int rec(int l)
{
    if(l>=s.size())
        return 0;
    if(dp[l]!=-1)
        return dp[l];
    int ret = INF;
    for(int i=l; i<s.size(); i++)
    {
        if(pal(l,i))
            ret = min(ret,1+rec(i+1));
    }
    dp[l] = ret;
    return dp[l];
}

int main()
{
//    freopen (".in", "r", stdin);
//    freopen (".out", "w", stdout);

    int test;
    cin >> test;

    while(test--)
    {
        cin >> s;

        int ret = INF;
        memset(dp,-1,sizeof(dp));
        for(int i=0; i<s.size(); i++)
        {
            if(pal(0,i))
            {
                ret = min(ret,1+rec(i+1));
            }
        }
        pcase;
        cout << ret << endl;
    }

    return 0;
}
