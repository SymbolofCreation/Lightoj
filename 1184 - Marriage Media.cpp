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

struct people{
    int height,age,divorced;
};

people man[55],woman[55];
int Left[55],Right[55];
bool vis[55];

vector<int> v[55];

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
    for(int i=0; i<m; i++)
    {
        memset(vis,false,sizeof(vis));
        if(Kuhn(i))
            cnt++;
    }
    return cnt;
}

void reset()
{
    for(int i=0; i<55; i++)
        v[i].clear();
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
        cin >> m >> n;
        for(int i=0; i<m; i++)
            cin >> man[i].height >> man[i].age >> man[i].divorced;
        for(int i=0; i<n; i++)
            cin >> woman[i].height >> woman[i].age >> woman[i].divorced;

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                int a,b,c,d,e,f;
                a = man[i].height;
                b = woman[j].height;
                c = man[i].age;
                d = woman[j].age;
                e = man[i].divorced;
                f = woman[j].divorced;

                if(abs(a-b)>12 || abs(c-d)>5 || e!=f)
                    continue;

                v[i].push_back(j);
            }
        }

        int ans = matching();
        pcase;
        cout << ans << endl;
    }

    return 0;
}
