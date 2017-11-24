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
#define INF 9999999
 
#define ll long long int
#define pii pair<int,int>
 
using namespace std;
 
int kase=1;
 
vector<int> v[2000];
 
struct tt
{
    int nod,num;
};
 
tt ar[1005];
 
bool comp(tt a,tt b)
{
    if(a.nod != b.nod)
        return a.nod < b.nod;
    return a.num > b.num;
}
 
void precal()
{
    for(int i=1; i<=1002; i++)
    {
        for(int j=i; j<=1002; j+=i)
        {
            v[j].push_back(i);
        }
    }
 
    for(int i=1; i<=1001; i++)
    {
        ar[i].nod = v[i].size();
        ar[i].num = i;
    }
 
    sort(ar,ar+1001,comp);
}
 
int main()
{
//    freopen (".in", "r", stdin);
//    freopen (".out", "w", stdout);
 
    precal();
 
    int test;
    cin >> test;
 
    while(test--)
    {
        int n;
        cin >> n;
        pcase;
        cout << ar[n].num << endl;
    }
 
    return 0;
}
