/*
ID: protikn2
PROG: test
LANG: C++11
*/
 
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
#define pcase(kase) printf("Case %d: ",kase)
 
// constants
 
#define infinity 9999999
 
using namespace std;
 
int kase=1;
 
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
 
int ddx[]={1,1,0,-1,-1,-1,0,1};
int ddy[]={0,1,1,1,0,-1,-1,-1};
 
vector<int>v[10010];
int dis[10010];
int low[10010];
bool vis[10010];
int timer=0;
set<int>s;
 
void reset()
{
    for(int i=0;i<10010;i++)
    {
        v[i].clear();
        low[i]=100000000;
        vis[i]=false;
        dis[i]=100000000;
    }
    s.clear();
    timer=0;
}
 
void art(int node,int pre)
{
    timer++;
    low[node]=dis[node]=timer;
    vis[node]=true;
 
    int cnt=0;
    for(int i=0;i<v[node].size();i++)
    {
        int j=v[node][i];
        if(j==pre)
            continue;
        if(!vis[j])
        {
            cnt++;
            art(j,node);
            low[node]=min(low[node],low[j]);
            if(low[j]>=dis[node] && pre!=0)
                s.insert(node);
        }
        else
            low[node]=min(low[node],dis[j]);
    }
 
    if(pre==0 && cnt>1)
        s.insert(node);
}
 
int main()
{
//    freopen (".in", "r",stdin);
//    freopen (".out", "w",stdout);
 
    int t;
    sf1(t);
 
    while(t--)
    {
        int n,m;
        sf2(n,m);
 
        reset();
 
        for(int i=0;i<m;i++)
        {
            int x,y;
            sf2(x,y);
 
            v[x].push_back(y);
            v[y].push_back(x);
        }
 
        art(1,0);
 
        pcase(kase++);
        cout << s.size() << endl;
 
    }
 
    return 0;
}
