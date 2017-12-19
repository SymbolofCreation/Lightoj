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

int kase=1,n,m;
int Left[150],Right[150];
bool vis[150];

vector<int> v[150],blue,red;

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
        memset(vis,false,sizeof(vis));
        if(Kuhn(i))
            cnt++;
    }
    return cnt;
}

void reset()
{
    for(int i=0; i<150; i++)
        v[i].clear();
    memset(vis,false,sizeof(vis));
    blue.clear();
    red.clear();
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
        cin >> n;
        for(int i=0; i<n; i++)
        {
            int x;
            cin >> x;
            red.push_back(x);
        }

        cin >> m;
        for(int i=0; i<m; i++)
        {
            int x;
            cin >> x;
            blue.push_back(x);
        }

        sort(blue.begin(),blue.end());
        sort(red.begin(),red.end());

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                int a = red[i];
                int b = blue[j];
                if(b%a==0)
                    v[i].push_back(j);
            }
        }

        pcase;
        cout << matching() << endl;
    }

    return 0;
}
