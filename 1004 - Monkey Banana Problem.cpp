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
#define pcase(kase) printf("Case %d: ",kase)

// constants

#define infinity 9999999

using namespace std;

int kase=1;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int ddx[]={1,1,0,-1,-1,-1,0,1};
int ddy[]={0,1,1,1,0,-1,-1,-1};

int banana[200][200];
long long monkey[200][200];
int n,ans = 0;

bool pos_ok(int i, int j)
{
    if(i<0 || j<0)
        return false;
    if(i>=(2*n-1) || j >=(2*n-1))
        return false;
    return true;
}

int eat_banana(int i,int j)
{
//    if(pos_ok(i,j) == false)
//        return 0;

    if(banana[i][j] == -1)
        return 0;

    if(monkey[i][j] != -1)
        return monkey[i][j];

    monkey[i][j] = max(eat_banana(i+1,j),eat_banana(i+1,j+1))+banana[i][j];

    if(monkey[i][j] > ans)
        ans = monkey[i][j];

    return monkey[i][j];
}

int main()
{
//    freopen (".in", "r", stdin);
//    freopen (".out", "w", stdout);

    int t;
    sf1(t);

    while(t--)
    {
        sf1(n);

        memset(banana,-1,sizeof(banana));
        memset(monkey,-1,sizeof(monkey));

        for(int i=0; i<(2*n-1); i++)
        {
            if(i<n)
                for(int j=0; j<i+1; j++)
                    sf1(banana[i][j]);
            else
                for(int j=i-n+1; j<n; j++)
                    sf1(banana[i][j]);
        }

        ans = 0;
        eat_banana(0,0);

        pcase(kase++);
        pf("%d\n",ans);
    }

    return 0;
}
