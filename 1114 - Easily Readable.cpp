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
#define pcase printf("Case %d:\n",kase++)
 
// constants
 
#define INF 9999999
 
#define ll long long int
#define pii pair<int,int>
 
using namespace std;
 
int kase=1;
#define maxn 100000
 
int convert(char c)
{
    if(c>='A' && c<='Z')
        return c-'A';
    return c-'a'+26;
}
 
struct trie
{
    int nxt[maxn][55];
    ll endd[maxn];
    int sz;
 
    trie()
    {
        memset(nxt,-1,sizeof(nxt));
        memset(endd,0,sizeof(endd));
        sz = 0;
    }
 
    void insert(string s)
    {
        int node = 0;
        for(int i=0; i<s.size(); i++)
        {
            char c = s[i];
            int j = convert(c);
            if(nxt[node][j]==-1)
                nxt[node][j] = ++sz;
            node = nxt[node][j];
        }
        endd[node]++;
    }
 
    ll search(string s)
    {
        int node = 0;
        for(int i=0; i<s.size(); i++)
        {
            char c = s[i];
            int j = convert(c);
            if(nxt[node][j]==-1)
                return 0;
            node = nxt[node][j];
        }
        return endd[node];
    }
};
 
int main()
{
//    freopen (".in", "r", stdin);
//    freopen (".out", "w", stdout);
 
    int test;
    sf1(test);
 
    while(test--)
    {
        int n;
        sf1(n);
        trie in;
        for(int i=0; i<n; i++)
        {
            char ss[200];
            sf("%s",ss);
            string s;
            s = ss;
            if(s.size()>2)sort(s.begin()+1,s.end()-1);
            in.insert(s);
        }
        int m;
        sf1(m);
        getchar();
        pcase;
        for(int i=0; i<m; i++)
        {
            char x[10005];
            gets(x);
            ll cnt = 1;
            stringstream ss(x);
            string s;
            while(ss >> s)
            {
                if(s.size()>2)sort(s.begin()+1,s.end()-1);
                cnt *= in.search(s);
            }
            pf("%lld\n",cnt);
        }
    }
 
    return 0;
}
