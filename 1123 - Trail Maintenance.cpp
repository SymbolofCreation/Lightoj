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
#define pcase printf("Case %d:\n",kase++)
 
// constants
 
#define infinity 9999999
 
using namespace std;
 
int kase=1;
 
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
 
int ddx[]={1,1,0,-1,-1,-1,0,1};
int ddy[]={0,1,1,1,0,-1,-1,-1};
 
int par[230];
 
struct edge
{
    int x,y,z;
 
    bool operator < (const edge &a) const
    {
        return z < a.z;
    }
};
 
//bool comp(const edge &a,const edge &b)
//{
//    if(a.z!=b.z)
//        return a.z < b.z;
//    if(a.x!=b.x)
//        return a.x < b.x;
//    return a.y < b.y;
//}
 
vector<edge>v,e;
 
inline void reset()
{
    v.clear();
    e.clear();
}
 
inline int find_parent(int x)
{
    if(par[x] == x)
        return x;
    return par[x] = find_parent(par[x]);
}
 
inline long long int MST(int n)
{
    long long int sum,count;
    sum = count = 0;
    for(int i=1; i<230; i++)
        par[i] = i;
    for(int i=0; i<v.size(); i++)
    {
        int one = find_parent(v[i].x);
        int two = find_parent(v[i].y);
        if(one!=two)
        {
            par[one] = two;
            sum += v[i].z;
            count++;
            e.push_back(v[i]);
            if(count == n-1)
                break;
        }
    }
    if(e.size())
    {
        v.clear();
        v = e;
        e.clear();
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
        int n,w;
        sf2(n,w);
        pcase;
        for(int i=0; i<w; i++)
        {
            int a,b,c;
            sf3(a,b,c);
            edge var;
            var.x = a;
            var.y = b;
            var.z = c;
            v.push_back(var);
            sort(v.begin(),v.end());
            long long int ans = MST(n);
            pf("%lld\n",ans);
        }
    }
 
    return 0;
}
