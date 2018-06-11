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
const int maxn = 100000;
 
struct trie
{
    int next[maxn][11];
    int sz = 0;
    int word[maxn];
    bool ret;
 
    trie(){
        memset(next,-1,sizeof(next));
        memset(word,0,sizeof(word));
        sz = 0;
        ret = false;
    }
 
    bool insert(string s)
    {
        int node = 0;
        int c = 0;
        for(int i=0; i<s.size(); i++)
        {
            if(word[node])
                ret = true;
            if(next[node][s[i]-'0'] == -1)
            {
                c = 1;
                next[node][s[i]-'0'] = ++sz;
            }
            node = next[node][s[i]-'0'];
        }
        word[node]++;
        if(ret == false && c == 0)
            ret = true;
        return ret;
    }
};
 
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
 
        trie in;
        bool flag = false;
        for(int i=0; i<n; i++)
        {
            string s;
            cin >> s;
            if(in.insert(s))
                flag = true;
        }
 
        pcase;
        if(flag)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
 
    return 0;
}
