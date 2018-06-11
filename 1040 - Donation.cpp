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
 
using namespace std;
 
int kase=1;
 
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
 
int ddx[]={1,1,0,-1,-1,-1,0,1};
int ddy[]={0,1,1,1,0,-1,-1,-1};
 
struct edge
{
    int x,y,w;
    bool operator < (const edge&p) const
    {
        return w < p.w;
    }
};
 
vector<edge> v;
int par[100];
 
inline void reset()
{
    for(int i=0; i<100; i++)
        par[i] = i;
    v.clear();
}
 
inline int find_parent(int x)
{
    if(x == par[x])
        return x;
    return par[x] = find_parent(par[x]);
}
 
inline int MST(int n)
{
    int sum = 0;
    int count = 0;
 
    for(int i=0; i<v.size(); i++)
    {
        int a = find_parent(v[i].x);
        int b = find_parent(v[i].y);
        if(a!=b)
        {
            par[a] = b;
            count++;
            sum += v[i].w;
            if(count == n-1)
                break;
        }
    }
 
    if(count == n-1)
        return sum;
    return -1;
}
 
int main(void)
{
//    freopen (".in", "r", stdin);
//    freopen (".out", "w", stdout);
 
    int test;
    cin >> test;
 
    while(test--)
    {
        reset();
        int n,fact=0;
        cin >> n;
 
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                int f;
                cin >> f;
                if(!f)
                    continue;
                fact += f;
                edge in;
                in.x = i;
                in.y = j;
                in.w = f;
                v.push_back(in);
            }
        }
 
        sort(v.begin(),v.end());
 
        int ans = MST(n);
        if(ans>=0)
            ans = fact - ans;
        pcase;
        cout << ans << endl;
    }
 
    return 0;
}
