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
 
ll dp[55][55][55];
string a,b,c;
 
ll LCS(int i,int j,int k)
{
    if(i<0 || j<0 || k<0)
        return 0ll;
    if(dp[i][j][k]!=-1)
        return dp[i][j][k];
    if((a[i]==b[j]) && (b[j]==c[k]))
        return dp[i][j][k] = 1+LCS(i-1,j-1,k-1);
    return dp[i][j][k] = max(LCS(i-1,j,k),max(LCS(i,j-1,k),LCS(i,j,k-1)));
}
 
int main()
{
//    freopen (".in", "r", stdin);
//    freopen (".out", "w", stdout);
 
    int test;
    cin >> test;
 
    while(test--)
    {
        cin >> a >> b >> c;
        memset(dp,-1,sizeof(dp));
        pcase;
        cout << LCS(a.size()-1,b.size()-1,c.size()-1) << endl;
    }
 
    return 0;
}
