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

struct Point
{
    ll x,y;

    bool operator < (const Point &p) const
    {
        return x<p.x || (x==p.x && y<p.y);
    }

    void print()
    {
        cout << "X coordinate is -> " << x << "Y coordinate is -> " << y << endl;
    }
};

ll cross(Point p,Point c,Point n)
{
    return (c.x-p.x)*(n.y-p.y) - (c.y-p.y)*(n.x-p.x);
}

vector<Point> convex_hull(vector<Point> a)
{
    int n = a.size(),k = 0;
    vector<Point> H(2*n);

    sort(a.begin(),a.end());

    for(int i=0; i<n; i++)
    {
        while(k>=2 && cross(H[k-2],H[k-1],a[i]) <= 0)
            k--;
        H[k++] = a[i];
    }
    for(int i=n-2, t=k+1; i>=0; i--)
    {
        while(k>=t && cross(H[k-2],H[k-1],a[i]) <= 0)
            k--;
        H[k++] = a[i];
    }

    H.resize(k-1);
    return H;
}

double getdis(Point a,Point b)
{
    return sqrt((double)(a.x-b.x)*(double)(a.x-b.x)+(double)(a.y-b.y)*(double)(a.y-b.y));
}

int main()
{
//    freopen (".in", "r", stdin);
//    freopen (".out", "w", stdout);

    int test;
    cin >> test;

    while(test--)
    {
        int n,d;
        cin >> n >> d;

        vector<Point> v;
        for(int i=0; i<n; i++)
        {
            Point p;
            scanf("%lld %lld",&p.x,&p.y);
            v.push_back(p);
        }

        v = convex_hull(v);

        double dis = 0.0;
        for(int i=0; i<v.size(); i++)
        {
            if(i==0)
                dis += getdis(v[v.size()-1],v[i]);
            else
                dis += getdis(v[i-1],v[i]);
        }

        double circle = (double)2*acos(-1.0)*(double)d;
        double ans = dis+circle;

        cout << fixed;
        cout.precision(10);

        pcase;
        cout << ans << endl;
    }

    return 0;
}
