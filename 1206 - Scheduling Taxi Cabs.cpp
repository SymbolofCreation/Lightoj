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

int kase=1,m;
int Left[505],Right[505],start[505],endd[505],a[505],b[505],c[505],d[505];
bool vis[505];

vector<int> v[505];

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
    memset(Left,-1,sizeof Left);
    memset(Right,-1,sizeof Right);

    int cnt = 0;
    for(int i=0; i<m; i++)
    {
        memset(vis,false,sizeof vis);
        if(Kuhn(i))
            cnt++;
    }
    return cnt;
}

void reset()
{
    for(int i=0; i<505; i++)
        v[i].clear();
    memset(vis,false,sizeof vis);
    memset(start,0,sizeof start);
    memset(endd,0,sizeof endd);
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
        cin >> m;
        for(int i=0; i<m; i++)
        {
            int hh,mm;
            scanf("%d:%d",&hh,&mm);
            start[i] = hh*60+mm;
            cin >> a[i] >> b[i] >> c[i] >> d[i];
            endd[i] = start[i] + abs(a[i]-c[i]) + abs(b[i]-d[i]);
        }

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(i==j)
                    continue;
                int dis = abs(a[j]-c[i])+abs(b[j]-d[i]);
                if(endd[i]+dis<start[j])
                    v[i].push_back(j);
            }
        }

        int ans = m - matching();
        pcase;
        cout << ans << endl;
    }

    return 0;
}
