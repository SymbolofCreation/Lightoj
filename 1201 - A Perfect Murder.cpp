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

#define         pro             printf("1\n")
#define         pcase           printf("Case %d: ",kase++)

// constants

#define         INF             (1 << 29)

#define         ll              long long int
#define         pii             pair<int,int>

//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

using namespace std;

int kase=1,n,m;
int col[1010],Left[1010],Right[1010];
bool vis[1010];
vector<int> v[1010];
vector<int> graph[1010];

void bfs(int node)
{
    vis[node] = true;
    for(int i=0; i<graph[node].size(); i++)
    {
        if(vis[graph[node][i]])
            continue;
        if(col[node]==0)
            col[graph[node][i]] = 1;
        else
            col[graph[node][i]] = 0;
        bfs(graph[node][i]);
    }
}

void reset()
{
    for(int i=0; i<1010; i++)
    {
        v[i].clear();
        graph[i].clear();
    }
    memset(vis,false,sizeof(vis));
}

bool Kuhn(int node)
{
    for(int i=0; i<v[node].size(); i++)
    {
        int x = v[node][i];
        if(vis[x])
            continue;
        vis[x] = true;
        if(Right[x]==-1 || Kuhn(Right[x]))
        {
            Right[x] = node;
            Left[node] = x;
            return true;
        }
    }
    return false;
}

int matching()
{
    memset(Left,-1,sizeof(Left));
    memset(Right,-1,sizeof(Right));

    int cnt = 0;
    for(int i=0; i<n; i++)
    {
        if(col[i])
            continue;
        memset(vis,false,sizeof(vis));
        if(Kuhn(i))
            cnt++;
    }
    return cnt;
}

int main()
{
//    freopen (".in", "r", stdin);
//    freopen (".out", "w", stdout);

    int test;
    cin >> test;

    while(test--)
    {
        reset();
        cin >> n >> m;
        for(int i=0; i<m; i++)
        {
            int x,y;
            cin >> x >> y;
            x--,y--;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        for(int i=0; i<n; i++)
            if(vis[i]==false)
                bfs(i);

        for(int i=0; i<n; i++)
        {
            if(col[i])
                continue;
            v[i] = graph[i];
        }

        int ans = n-matching();
        pcase;
        cout << ans << endl;
    }

    return 0;
}
