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

int main()
{
//    freopen (".in", "r", stdin);
//    freopen (".out", "w", stdout);

    int t;
    sf1(t);

    while(t--)
    {
        int n;
        sf1(n);
        int a[n+10][4];

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<3; j++)
            {
                sf1(a[i][j]);
            }
        }

        for(int i=1; i<n; i++)
        {
             a[i][0] += min(a[i-1][1],a[i-1][2]);
             a[i][1] += min(a[i-1][0],a[i-1][2]);
             a[i][2] += min(a[i-1][1],a[i-1][0]);
        }

        pcase(kase++);

        cout << min(a[n-1][0],min(a[n-1][1],a[n-1][2])) << endl;
    }

    return 0;
}
