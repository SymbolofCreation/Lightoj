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
#include<utility>
#include<ctime>

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
#define pcase(kase) printf("Case %d:\n",kase)

// constants

#define infinity 99999999

using namespace std;

int kase=1;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int ddx[]={1,1,0,-1,-1,-1,0,1};
int ddy[]={0,1,1,1,0,-1,-1,-1};

#define pii pair<int,int> // first element is smaller than the second element

vector<int>v[10010];
bool vis[10010];
int dis[10010];
int low[10010];
int timer;
set<pii>s;

inline void reset(void)
{
    for(int i=0; i<10010; i++)
    {
        v[i].clear();
        vis[i] = false;
        dis[i] = infinity;
        low[i] = infinity;
    }
    s.clear();
    timer = 0;
}

inline void bridge(int node,int pre)
{
    timer++;
    dis[node] = low[node] = timer;
    vis[node] = true;
    for(int i=0; i<v[node].size(); i++)
    {
        int j = v[node][i];
        if(j == pre)
            continue;
        else if(vis[j] != true)
        {
            bridge(j,node);
            low[node] = min(low[node],low[j]);
            if(dis[node] < low[j])
            {
                pii x;
                x.first = min(node,j);
                x.second = max(node,j);
                s.insert(x);
            }
        }
        else
            low[node] = min(low[node],dis[j]);
    }
    return;
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

        int n;
        sf1(n);

        for(int i=0; i<n; i++)
        {
            int u,m;

            sf("%d (%d)",&u,&m);

            for(int j=0; j<m; j++)
            {
                int x;
                sf1(x);
                v[u].push_back(x);
                v[x].push_back(u);
            }
        }
        for(int i=0; i<n; i++)
        {
            if(vis[i] == false)
            {
                bridge(i,-1);
            }
        }

        pcase(kase++);

        pf("%d critical links\n",s.size());

        set<pii>:: iterator it;

        for(it=s.begin(); it!=s.end(); it++)
        {
            pii x = *it;
            pf("%d - %d\n",x.first,x.second);
        }
    }

    return 0;
}
