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

#define infinity 9999999

#define ll long long int
#define pii pair<int,int>

using namespace std;

int kase=1;

string s;
int dp[105][105];

inline int func(int i,int j)
{
    if(i>=j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(s[i]==s[j])
        return dp[i][j] = func(i+1,j-1);
    return dp[i][j] = 1+min(func(i,j-1),func(i+1,j));
}

int main(void)
{
//    freopen (".in", "r", stdin);
//    freopen (".out", "w", stdout);

    int test;
    cin >> test;

    while(test--)
    {
        cin >> s;
        memset(dp,-1,sizeof(dp));
        pcase;
        pf("%d\n",func(0,s.size()-1));
    }

    return 0;
}
