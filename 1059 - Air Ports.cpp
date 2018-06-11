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
    int u,v,w;
    bool operator< (const edge& p) const
    {
        return w<p.w;
    }
};
 
vector<edge> V;
int par[10010];
 
int find_parent(int x)
{
    if(par[x] == x)
        return x;
    return par[x] = find_parent(par[x]);
}
 
int how_many_airports(int n)
{
    bool vis[10010];
    memset(vis,false,sizeof(vis));
    int count = 0;
    for(int i=1; i<=n; i++)
    {
        int u = find_parent(i);
        if(!vis[u])
        {
            vis[u] = true;
            count++;
        }
    }
    return count;
}
 
int MST(int n,int cost)
{
    int sum = 0;
    int count = 0;
    for(int i=0; i<V.size(); i++)
    {
        int one = find_parent(V[i].u);
        int two = find_parent(V[i].v);
 
        if(one!=two)
        {
            int ex = V[i].w;
            if(ex<cost)
            {
                par[one] = two;
                sum += V[i].w;
                count++;
                if(count == n-1)
                    return sum;
            }
        }
    }
    return sum;
}
 
void reset()
{
    V.clear();
    for(int i=0; i<10010; i++)
        par[i] = i;
}
 
int main(void)
{
//    freopen (".in", "r", stdin);
//    freopen (".out", "w", stdout);
 
    int test;
    sf1(test);
 
    while(test--)
    {
        reset();
        int n,m,cost;
        sf3(n,m,cost);
        for(int i=0; i<m; i++)
        {
            int x,y,z;
            sf3(x,y,z);
            edge vertex;
            vertex.u = x;
            vertex.v = y;
            vertex.w = z;
            V.push_back(vertex);
        }
        sort(V.begin(),V.end());
 
        int ans = MST(n,cost);
        int number = how_many_airports(n);
 
        pcase;
        pf("%d %d\n",ans+(cost*number),number);
    }
 
    return 0;
}
