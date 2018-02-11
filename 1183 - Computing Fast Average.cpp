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

int ara[100005],tree[500005],lazy[500005];

int gcd(int a,int b) {return b==0?a:gcd(b,a%b);}

int build(int at,int Left,int Right)
{
     if(Left==Right)
          return tree[at] = ara[Right];

     int mid = (Left+Right)/2;
     int l = build(at*2,Left,mid);
     int r = build(at*2+1,mid+1,Right);

     return tree[at] = l+r;
}

void lazy_update(int Left,int Right,int at)
{
     tree[at] = (Right-Left+1) * lazy[at];
     if(Left<Right)
          lazy[at*2] = lazy[at*2+1] = lazy[at];
     lazy[at] = -1;
}

void update(int at,int Left,int Right,int l,int r,int add)
{
     if(lazy[at] != -1)
          lazy_update(Left,Right,at);
     if(r<Left || Right<l)
          return;
     if(l<=Left && Right<=r)
     {
          tree[at] = (Right-Left+1)*add;
          if(Right>Left)
               lazy[at*2] = lazy[at*2+1] = add;
          return;
     }

     int mid = (Left+Right)/2;
     update(at*2,Left,mid,l,r,add);
     update(at*2+1,mid+1,Right,l,r,add);

     tree[at] = tree[at*2] + tree[at*2+1];
}

int query(int at,int Left,int Right,int l,int r)
{
     if(lazy[at]!=-1)
          lazy_update(Left,Right,at);
     if(r<Left || Right<l)
          return 0;
     if(l<=Left && Right<=r)
          return tree[at];

     int mid = (Left+Right)/2;

     return query(at*2,Left,mid,l,r)+query(at*2+1,mid+1,Right,l,r);
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
          memset(lazy,-1,sizeof(lazy));
          memset(ara,0,sizeof(ara));

          build(1,1,n);
          pcase;
          while(q--)
          {
               int type;
               sf1(type);
               if(type==1)
               {
                    int i,j,v;
                    sf3(i,j,v);
                    i++,j++;
                    update(1,1,n,i,j,v);
               }
               else
               {
                    int i,j;
                    sf2(i,j);
                    i++,j++;
                    int ans = query(1,1,n,i,j);
                    int number = j-i+1;

                    if(ans%number)
                    {
                         int gcd = __gcd(ans,number);
                         int nomi = ans/gcd;
                         int denomi = number/gcd;
                         pf("%d/%d\n",nomi,denomi);
                    }
                    else
                         pf("%d\n",ans/number);
               }
          }
     }

     return 0;
}
