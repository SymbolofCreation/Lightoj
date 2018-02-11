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

#define         pro             printf("PRINT  ::  DEBUG\n")
#define         pcase           printf("Case %d:\n",kase++)

// constants

#define         INF             (1 << 29)

#define         ll              long long int
#define         pii             pair<int,int>

//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

using namespace std;

int kase=1,n,q;
int ara[100005];
int tree[500005];

int build(int at,int Left,int Right)
{
     if(Left==Right)
          return tree[at] = ara[Left];

     int mid = (Left+Right)/2;
     int l = build(at*2, Left, mid);
     int r = build(at*2+1, mid+1, Right);

     return tree[at] = min(l,r);
}

int query(int at,int Left,int Right,int l,int r)
{
     if(r<Left || Right<l)
          return INT_MAX;
     if(l<=Left && Right<=r)
          return tree[at];

     int mid = (Left+Right)/2;
     int x = query(at*2,Left,mid,l,r);
     int y = query(at*2+1,mid+1,Right,l,r);

     return min(x,y);
}

int main()
{
//    freopen (".in", "r", stdin);
//    freopen (".out", "w", stdout);

    int test;
    sf1(test);

    while(test--)
    {
         sf2(n,q);
         for(int i=1; i<=n; i++)
             sf1(ara[i]);

         build(1,1,n);
         pcase;
         while(q--)
         {
              int i,j;
              sf2(i,j);
              int ans = query(1,1,n,i,j);
              pf("%d\n",ans);
         }
    }

     return 0;
}
