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
 
int kase=1,a,b,k,cnt=0;
int dp[12][85][87];
 
void getdig(int a,vector<int> &v)
{
    while(a)
    {
        int x = a%10;
        v.push_back(x);
        a /= 10;
    }
}
 
ll solve(int index,int dig_sum,int num,int tight,vector<int> &v)
{
    if(index<0)
    {
        if(dig_sum!=0 && num!=0 && dig_sum%k==0 && num%k==0)
            return 1ll;
        else
            return 0ll;
    }
 
    if(dp[index][dig_sum][num%k] != -1 && tight != 1)
        return dp[index][dig_sum][num%k];
 
    ll ret = 0;
 
    int range = (tight) ? v[index] : 9;
    for(int i=0; i<=range; i++)
    {
        int new_tight = (i==v[index]) ? tight : 0;
        ret += solve(index-1,dig_sum+i,num*10+i,new_tight,v);
    }
    if(!tight)
        return dp[index][dig_sum][num%k] = ret;
    return ret;
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
        a,b,k;
        cin >> a >> b >> k;
        if(a>b)
            swap(a,b);
        a--;
 
        vector<int> dig_a;
        vector<int> dig_b;
 
        getdig(a,dig_a);
        getdig(b,dig_b);
 
        ll ans1,ans2;
        if(k<85)
            ans1 = solve(dig_a.size()-1,0,0,1,dig_a);
        else
            ans1 = 0ll;
        if(k<85)
            ans2 = solve(dig_b.size()-1,0,0,1,dig_b);
        else
            ans2 = 0ll;
 
        pcase;
        cout << ans2-ans1 << endl;
    }
 
    return 0;
}
