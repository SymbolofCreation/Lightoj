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
#define pcase(kase) printf("Case %d:\n",kase)

// constants

#define infinity 9999999

using namespace std;

int kase=1;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int ddx[]={1,1,0,-1,-1,-1,0,1};
int ddy[]={0,1,1,1,0,-1,-1,-1};

#define pii pair<int,int>

vector<pii>v[30005];
bool vis[30005];
int lev[30005];
int lev2[30005];

int find_node,n,maxi;

void reset(void)
{
    for(int i=0; i<n; i++)
    {
        v[i].clear();
        vis[i] = false;
        lev[i] = 0;
        lev2[i] = 0;
    }
    maxi = -5;
}

void bfs1(int node)
{
    queue<int>q;
    q.push(node);
    vis[node] = true;
    lev[node] = 0;
    if(lev[node] > maxi)
    {
        maxi = lev[node];
        find_node = node;
    }
    while(q.size()!=0)
    {
        int f = q.front();
        q.pop();
        for(int i=0; i<v[f].size(); i++)
        {
            int x,y;
            x = v[f][i].first;
            y = v[f][i].second;
            if(vis[x])
                continue;
            vis[x] = true;
            lev[x] = lev[f]+y;
            if(lev[x] > maxi)
            {
                maxi = lev[x];
                find_node = x;
            }
            q.push(x);
        }
    }
}

void bfs2(int node)
{
    queue<int>q;
    q.push(node);
    vis[node] = true;
    lev2[node] = 0;

    while(q.size()!=0)
    {
        int f = q.front();
        q.pop();
        for(int i=0; i<v[f].size(); i++)
        {
            int x,y;
            x = v[f][i].first;
            y = v[f][i].second;
            if(vis[x])
                continue;
            vis[x] = true;
            lev2[x] = lev2[f]+y;
//            cout << "y = " << y << " " << "f = " << f << " " << "x = " << x << " " << "lev[x] = " << lev[x] << " " << "lev[f] = " << lev[f] << endl;
            q.push(x);
        }
    }
}

int main()
{
//    freopen (".in", "r", stdin);
//    freopen (".out", "w", stdout);

    int test;
    sf1(test);

    while(test--)
    {

        reset();

        sf1(n);

        for(int i=1; i<n; i++)
        {
            int x,y,z;
            sf3(x,y,z);
            v[x].push_back(make_pair(y,z));
            v[y].push_back(make_pair(x,z));
        }

        bfs1(0);
        int dia1 = find_node;
        memset(vis,false,sizeof(vis));
        maxi = -5;

        bfs1(dia1);
        int dia2 = find_node;
        memset(vis,false,sizeof(vis));

        bfs2(dia2);
        lev[dia2] = lev[dia1] = maxi;

//        cout << dia1 << " " << dia2 << endl;

        pcase(kase++);
        for(int i=0; i<n; i++)
        {
            int z= max(lev2[i],lev[i]);
            pf("%d\n",z);
        }

    }

    return 0;
}
/*
2
4
0 1 20
1 2 30
2 3 50
5
0 2 20
2 1 10
0 3 29
0 4 50
*/
