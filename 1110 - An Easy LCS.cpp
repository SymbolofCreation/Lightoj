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
 
int kase=1;
int dp[105][105];
 
string a,b;
string ans[105][105];
 
void LCS(int n,int m)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i-1]==b[j-1])
            {
                dp[i][j] = 1+dp[i-1][j-1];
                ans[i][j] = ans[i-1][j-1] + a[i-1];
            }
            else if(dp[i-1][j] > dp[i][j-1])
            {
                dp[i][j] = dp[i-1][j];
                ans[i][j] = ans[i-1][j];
            }
            else if(dp[i][j-1] > dp[i-1][j])
            {
                dp[i][j] = dp[i][j-1];
                ans[i][j] = ans[i][j-1];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
                ans[i][j] = min(ans[i-1][j],ans[i][j-1]);
            }
        }
    }
 
    if(dp[n][m]==0)
        cout << ":(" << endl;
    else
        cout << ans[n][m] << endl;
}
 
void reset()
{
    for(int i=0; i<105; i++)
        for(int j=0; j<105; j++)
            ans[i][j] = "";
    for(int i=0; i<105; i++)
        for(int j=0; j<105; j++)
            dp[i][j] = 0;
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
        cin >> a >> b;
        pcase;
        LCS(a.size(),b.size());
    }
 
    return 0;
}
