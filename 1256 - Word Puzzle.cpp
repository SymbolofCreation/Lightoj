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
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
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
 
#define INF 9999999
 
#define ll long long int
#define pii pair<int,int>
 
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
 
using namespace std;
 
int kase=1;
 
int in[27],out[27],found[27],col[27];
int g[27][27];
 
vector<string> word;
vector<int> gs[27][27];
vector<pii> G[27];
vector<int> path;
 
bool is_connected()
{
    queue<int> q;
    for(int i=0; i<26; i++)
    {
        if(found[i]==1)
            col[i] = 0;
        else
            col[i] = 2;
    }
    int starting;
    for(int i=0; i<26; i++)
    {
        if(col[i]==0)
        {
            starting = i;
            break;
        }
    }
    q.push(starting);
    col[starting] = 2;
    while(!q.empty())
    {
        int f = q.front();
        q.pop();
        for(int i=0; i<26; i++)
        {
            if((g[f][i] || g[i][f]) && !col[i])
            {
                q.push(i);
                col[i] = 2;
            }
        }
    }
    for(int i=0; i<26; i++)
    {
        if(col[i]!=2)
            return false;
    }
    return true;
}
 
void find_path(int node)
{
    for(int i = 0; i < G[node].size(); i++) {
        if(G[node][i].second == 1) {
            G[node][i].second = 0;
            find_path(G[node][i].first);
        }
    }
    path.push_back(node);
}
 
bool has_an_euler_path()
{
    if(is_connected()==false)
        return false;
    int cnt1,cnt2;
    cnt1 = cnt2 = 0;
    for(int i=0; i<26; i++)
    {
        if(in[i]-out[i]==1)
            cnt1++;
        else if(out[i]-in[i]==1)
            cnt2++;
        else if(out[i]!=in[i])
            return false;
    }
    if(cnt1+cnt2==0 || (cnt1==1 && cnt2==1))
        return true;
    return false;
}
 
void reset()
{
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    memset(found,0,sizeof(found));
    memset(g,0,sizeof(g));
    memset(col,0,sizeof(col));
    word.clear();
    path.clear();
    for(int i=0; i<27; i++)
    {
        G[i].clear();
        for(int j=0; j<27; j++)
        {
            gs[i][j].clear();
        }
    }
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
        int n;
        cin >> n;
        for(int i=0; i<n; i++)
        {
            string s;
            cin >> s;
            word.push_back(s);
            int l = word[i].size();
            int u = word[i][0]-'a';
            int v = word[i][l-1]-'a';
            out[u]++;
            in[v]++;
            g[u][v] = found[u] = found[v] = 1;
            gs[u][v].push_back(i);
            G[u].push_back(make_pair(v, 1));
        }
        if(has_an_euler_path())
        {
            pcase;
            cout << "Yes" << endl;
 
            int i;
            for(i = 0; i < 26; i++) {
                if(out[i] > in[i])
                    break;
            }
            if(i == 26) for(i = 0; !out[i]; i++);
            find_path(i);
 
            reverse(path.begin(),path.end());
            vector<string> ans;
 
            for(int i=1; i<path.size(); i++)
            {
                int endd = path[i];
                int start = path[i-1];
//                cout << start << " " << endd << endl;
                int x = gs[start][endd].back();
//                cout << x << endl;
                gs[start][endd].pop_back();
                string y = word[x];
                ans.push_back(y);
            }
 
            cout << ans[0];
            for(int i=1; i<ans.size(); i++)
            {
                cout << " " << ans[i];
            }
            cout << endl;
        }
        else
        {
            pcase;
            cout << "No" << endl;
        }
    }
 
    return 0;
}
 
/*
2
5
abcf
pqrs
fzzp
zama
pxrp
3
yes
no
notsolvable
*/
