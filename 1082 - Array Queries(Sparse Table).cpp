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
int tree[100005][20];

void build()
{
     for(int i=0; i<n; i++)
          tree[i][0] = i;

     for(int j=1; 1<<j <= n; j++)
     {
          for(int i=0; i+(1<<j)-1 < n; i++)
          {
               ara[tree[i][j-1]] < ara[tree[i+(1<<(j-1))][j-1]] ? tree[i][j] = tree[i][j-1] : tree[i][j] = tree[i+(1<<(j-1))][j-1];
          }
     }
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
          for(int i=0; i<n; i++)
               sf1(ara[i]);

          build();

          pcase;
          while(q--)
          {
               int i,j;
               sf2(i,j);
                i--,j--;

               int k = log2(j-i+1);
               int power = pow(2,k);
               pf("%d\n", ara[tree[i][k]] <= ara[tree[j-power+1][k]] ? ara[tree[i][k]] : ara[tree[j-power+1][k]]);
          }
     }

     return 0;
}
