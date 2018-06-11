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
 
int parent[200];
 
struct edge
{
    int u,v,w;
};
 
vector<edge> v;
 
inline void reset(void)
{
    v.clear();
}
 
inline void initial_parent(void)
{
    for(int i=0; i<200; i++)
        parent[i] = i;
}
 
bool comp1(const edge &a,const edge &b)
{
    return a.w < b.w;
}
 
bool comp2(const edge &a,const edge &b)
{
    return a.w > b.w;
}
 
inline int find_parent(int r)
{
    if(parent[r] == r)
        return r;
    find_parent(parent[r]);
}
 
inline int MST(int n)
{
    int sum = 0;
    int count = 0;
    initial_parent();
    for(int i=0; i<v.size(); i++)
    {
        int one = find_parent(v[i].u);
        int two = find_parent(v[i].v);
        if(one!=two)
        {
            parent[one] = two;
            count++;
            sum += v[i].w;
            if(count == n)
                return sum;
        }
    }
    return sum;
}
 
int main(void)
{
//    freopen (".in", "r", stdin);
//    freopen (".out", "w", stdout);
 
    int test;
    cin >> test;
 
    while(test--)
    {
        int n;
        cin >> n;
        reset();
        while(1)
        {
            int a,b,c;
            cin >> a >> b >> c;
            if(a==0 && b==0 && c==0)
                break;
            edge net;
            net.u = a;
            net.v = b;
            net.w = c;
            v.push_back(net);
        }
        sort(v.begin(),v.end(),comp1);
        int ans1 = MST(n);
        sort(v.begin(),v.end(),comp2);
        int ans2 = MST(n);
        int ans = ans1 + ans2;
        if((ans>>1) == ceil((double)ans/2.0))
        {
            pcase(kase++);
            printf("%d\n",ans>>1);
        }
        else
        {
            pcase(kase++);
            printf("%d/2\n",ans);
        }
    }
 
    return 0;
}
