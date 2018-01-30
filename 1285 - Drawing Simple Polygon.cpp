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
#define         pcase           printf("Case %d:\n",kase++)

// constants

#define         INF             (1 << 29)

#define         ll              long long int
#define         pii             pair<int,int>

//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

using namespace std;

int kase=1,n;

struct Point
{
    int x,y,pos;
    double angle;

    bool operator < (const Point &p) const
    {
        return y<p.y || (y==p.y && x<p.x);
    }

    void print()
    {
        cout << "X coordinate is -> " << x << endl << "Y coordinate is -> " << y << endl;
        cout << "Angle is -> " << angle << endl;
    }
};

vector<Point> v;

ll cross(Point a,Point b,Point c)
{
    return ((b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y));
}

double dis(Point a,Point b)
{
    return sqrt((double)(a.x-b.x)*(a.x-b.x) + (double)(a.y-b.y)*(a.y-b.y));
}

bool acomp(Point a,Point b)
{
    ll m = cross(v[0],a,b);
    if(m == 0)
        return dis(v[0],a) < dis(v[0],b);
    else
        return m>0;
}

int main()
{
//    freopen (".in", "r", stdin);
//    freopen (".out", "w", stdout);

    int test;
    cin >> test;

    while(test--)
    {
        cin >> n;
        v.clear();
        for(int i=0; i<n; i++)
        {
            Point p;
            cin >> p.x >> p.y;
            p.pos = i;
            v.push_back(p);
        }

        sort(v.begin(),v.end());
        sort(v.begin()+1,v.end(),acomp);

        int f = 0;
        for(int i=n-2;i>=1;i--)
        {
            if(cross(v[0],v[n-1],v[i])!=0)
            {
                f=i;
                break;
            }
        }

        pcase;
        if(!f)
        {
            cout << "Impossible" << endl;
            continue;
        }

        cout << v[0].pos;
        reverse(v.begin()+f+1,v.end());

        for(int i=1; i<n; i++)
        {
            cout << " " << v[i].pos;
        }
        cout << endl;
    }

    return 0;
}
