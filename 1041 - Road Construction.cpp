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
#define pcase printf("Case %d: ",kase++)
 
// constants
 
#define infinity 9999999
 
using namespace std;
 
int kase=1;
 
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
 
int ddx[]={1,1,0,-1,-1,-1,0,1};
int ddy[]={0,1,1,1,0,-1,-1,-1};
 
struct edge
{
    int s,e,cost;
 
    bool operator < (const edge &p) const
    {
        return cost < p.cost;
    }
};
 
vector<edge> v;
int parent[110];
 
inline void reset(void)
{
    v.clear();
    for(int i=0; i<110; i++)
        parent[i] = i;
}
 
inline int find_parent(int x)
{
    if(parent[x] == x)
        return x;
    return parent[x] = find_parent(parent[x]);
}
 
inline int MST(int n)
{
    sort(v.begin(),v.end());
    int sum = 0;
    int count = 0;
    for(int i=0; i<v.size(); i++)
    {
        int one = find_parent(v[i].s);
        int two = find_parent(v[i].e);
        if(one != two)
        {
            parent[one] = two;
            count++;
            sum += v[i].cost;
            if(count == n-1)
                break;
        }
    }
    if(count == n-1)
        return sum;
    return -1;
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
        int n;
        cin >> n;
        map<string,int> mp;
        int cnt = 0;
        for(int i=0; i<n; i++)
        {
            string x,y;
            int c;
            cin >> x >> y;
            cin >> c;
            edge input;
            if(mp[x] == 0)
            {
                cnt++;
                input.s = mp[x] = cnt;
            }
            else
                input.s = mp[x];
            if(mp[y] == 0)
            {
                cnt++;
                input.e = mp[y] = cnt;
            }
            else
                input.e = mp[y];
            input.cost = c;
            v.push_back(input);
        }
        int ans = MST(cnt);
        pcase;
        if(ans != -1)
            cout << ans << endl;
        else
            cout << "Impossible" << endl;
    }
 
    return 0;
}
