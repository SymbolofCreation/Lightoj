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

int kase=1,n,m,counted=0,star;
int Left[405],Right[405],col[405];
bool vis[405];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

vector<int> v[405];
string graph[25];
map<pii,int> mp;

inline bool is_ok(int x,int y)
{
    if(x<0 || y<0 || x>=m || y>=n)
        return false;
    return true;
}

inline void dfs(int x,int y)
{
    pii par = make_pair(x,y);
    if(graph[x][y] == '*')
        star++;
    for(int i=0; i<4; i++)
    {
        int xx = x+dx[i];
        int yy = y+dy[i];

        pii p = make_pair(xx,yy);
        if(mp[p]!=0 || is_ok(xx,yy)==false)
            continue;
        mp[p] = ++counted;
        if(col[mp[par]])
            col[mp[p]] = 0;
        else
            col[mp[p]] = 1;
        dfs(xx,yy);
    }
}

inline void reset()
{
    for(int i=0; i<405; i++)
        v[i].clear();
    for(int i=0; i<25; i++)
        graph[i] = "";
    mp.clear();
    memset(vis,false,sizeof(vis));
    memset(col,0,sizeof(col));
    counted = 0;
    star = 0;
}

inline bool Kuhn(int node)
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
    for(int i=1; i<=counted; i++)
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

    int t;
    cin >> t;

    while(t--)
    {
        reset();
        cin >> m >> n;
        for(int i=0; i<m; i++)
        {
            cin >> graph[i];
        }

        pii z = make_pair(0,0);
        mp[z] = ++counted;
        dfs(0,0);

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                pii par = make_pair(i,j);
                if(col[mp[par]] || graph[i][j]=='o')
                    continue;
                for(int k=0; k<4; k++)
                {
                    int xx = i+dx[k];
                    int yy = j+dy[k];

                    pii p = make_pair(xx,yy);
                    if(col[mp[p]]==0 || graph[i][j]=='o' || graph[xx][yy]=='o')
                        continue;
                    v[mp[par]].push_back(mp[p]);
                }
            }
        }

        int ans = star-matching();
        pcase;
        cout << ans << endl;
    }

    return 0;
}
