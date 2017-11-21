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
#define pcase(kase) printf("Case %d: ",kase)
 
// constants
 
#define infinity 9999999
 
using namespace std;
 
int kase=1;
 
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
 
int ddx[]={1,1,0,-1,-1,-1,0,1};
int ddy[]={0,1,1,1,0,-1,-1,-1};
 
#define white 0
#define gray 1
#define black 2
 
vector<int>v[10010];
int vis[10010];
map<string,int> mp;
bool cycle = false;
 
inline void reset(void)
{
    for(int i=0; i<10010; i++)
    {
        v[i].clear();
        vis[i] = white;
    }
    mp.clear();
    cycle = false;
}
 
inline void cycle_finder(int node)
{
    vis[node] = gray;
    for(int i=0; i<v[node].size(); i++)
    {
        int j = v[node][i];
        if(vis[j] == black)
            continue;
        else if(vis[j] == white)
        {
            cycle_finder(j);
        }
        else if(vis[j] == gray)
        {
            cycle = true;
            return;
        }
    }
    vis[node] = black;
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
 
        int m;
        cin >> m;
 
        int ID = 0;
        for(int i=0; i<m; i++)
        {
            string one,two;
            cin >> one >> two;
            if(mp[one] == 0)
                mp[one] = ++ID;
            if(mp[two] == 0)
                mp[two] = ++ID;
            v[mp[one]].push_back(mp[two]);
        }
 
        cycle = false;
 
        for(int i=1; i<=ID; i++)
        {
            if(cycle)
            {
                pcase(kase++);
                cout << "No" << endl;
                break;
            }
            if(vis[i] == white)
                cycle_finder(i);
        }
 
        if(cycle == false)
        {
            pcase(kase++);
            cout << "Yes" << endl;
        }
    }
 
    return 0;
}
