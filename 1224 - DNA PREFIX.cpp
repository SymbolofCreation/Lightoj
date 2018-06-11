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
 
#define INF 9999999
 
#define ll long long int
#define pii pair<int,int>
 
using namespace std;
 
int kase=1;
const int maxn = 1000000;
 
struct trie
{
    int nxt[maxn][5];
    int maxi,sz;
    int used[maxn];
 
    trie()
    {
        memset(nxt,-1,sizeof(nxt));
        memset(used,0,sizeof(used));
        maxi = -5;
        sz = 0;
    }
 
    void insert(char s[])
    {
        int len = strlen(s);
        int node = 0;
        for(int i=0; i<len; i++)
        {
            int j;
            if(s[i]=='A')
                j = 0;
            else if(s[i]=='T')
                j = 1;
            else if(s[i]=='G')
                j = 2;
            else
                j = 3;
            if(nxt[node][j]==-1)
                nxt[node][j] = ++sz;
            node = nxt[node][j];
            used[node]++;
            int pre = used[node]*(i+1);
            maxi = max(pre,maxi);
        }
    }
    int ans()
    {
        return maxi;
    }
};
 
int main(void)
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
            char s[100];
            sf("%s",s);
            in.insert(s);
        }
       int ans = in.ans();
       pcase;
       pf("%d\n",ans);
    }
 
    return 0;
}
