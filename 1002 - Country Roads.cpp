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
 
#define pro printf("55\n")
#define pcase printf("Case %d:\n",kase++)
 
// constants
 
#define INF 9999999
 
using namespace std;
 
int kase=1;
 
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
 
int ddx[]={1,1,0,-1,-1,-1,0,1};
int ddy[]={0,1,1,1,0,-1,-1,-1};
 
#define pii pair<int,int>
 
struct comp1{
    bool operator() (const pii &a, const pii &b) {
        return a.second > b.second;
    }
};
 
vector<pii> v[510];
bool vis[510];
int dis[510];
 
inline void reset(void)
{
    for(int i=0; i<501; i++)
    {
        vis[i] = false;
        v[i].clear();
        dis[i] = INF;
    }
}
 
inline bool dijkstra(int node)
{
    priority_queue< pii, vector< pii >, comp1 > q;
    q.push(make_pair(node,0));
 
    while(!q.empty())
    {
        int f = q.top().first;
        q.pop();
        if(vis[f])
            continue;
        vis[f] = true;
        for(int i=0; i<v[f].size(); i++)
        {
            int x = v[f][i].first;
            int cost = v[f][i].second;
            int temp = max(dis[f],cost);
            if(temp<dis[x]){
                dis[x]=temp;
                q.push(make_pair(x,dis[x]));
            }
        }
    }
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
        int n,m;
        sf2(n,m);
        for(int i=0; i<m; i++)
        {
            int x,y,w;
            sf3(x,y,w);
            v[x].push_back(make_pair(y,w));
            v[y].push_back(make_pair(x,w));
        }
        int start;
        sf1(start);
        dis[start] = 0;
 
        dijkstra(start);
 
        pcase;
        for(int i=0; i<n; i++)
        {
            if(dis[i]!=INF)
                pf("%d\n",dis[i]);
            else
                pf("Impossible\n");
        }
    }
 
    return 0;
}
