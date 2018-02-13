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

int ara[100005],lazy[500005];

void lazy_update(int at,int Left,int Right)
{
     if(Left<Right)
     {
          lazy[at*2] += lazy[at];
          lazy[at*2+1] += lazy[at];
          lazy[at] = 0;
     }
}

void update(int at,int Left,int Right,int l,int r)
{
     if(Right<l || r<Left)
          return;
     if(l<=Left && Right<=r)
     {
          lazy[at]++;
          return;
     }

     int mid = (Left+Right)/2;
     update(at*2,Left,mid,l,r);
     update(at*2+1,mid+1,Right,l,r);
}

int query(int at,int Left,int Right,int l,int r)
{
     if(lazy[at]!=0)
          lazy_update(at,Left,Right);
     if(Right<l || r<Left)
          return -10;
     if(l<=Left && Right<=r)
     {
          if(lazy[at]%2)
               ara[l] ^= 1;
          lazy[at] = 0;
          return ara[l];
     }

     int mid = (Left+Right)/2;
     return max(query(at*2,Left,mid,l,r),query(at*2+1,mid+1,Right,l,r));
}


int main()
{
//    freopen (".in", "r", stdin);
//    freopen (".out", "w", stdout);

     int test;
     sf1(test);

     while(test--)
     {
          string s;
          cin >> s;
          n = s.size();
          sf1(q);
          for(int i=1; i<=n; i++)
               ara[i] = s[i-1]-'0';

          memset(lazy,0,sizeof(lazy));
          pcase;

          while(q--)
          {
               getchar();
               char ch;
               sf("%c",&ch);

               if(ch=='I')
               {
                    int i,j;
                    sf2(i,j);

                    update(1,1,n,i,j);
               }
               else
               {
                    int i;
                    sf1(i);

                    int ans = query(1,1,n,i,i);
                    pf("%d\n",ans);
               }
          }
     }

     return 0;
}
