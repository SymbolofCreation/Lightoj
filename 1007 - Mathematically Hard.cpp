/*
ID: protikn2
PROG: test
LANG: C++14
*/

//    #include <bits/stdc++.h>

#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <set>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
#include <functional>
#include <climits>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

//    scan & print

#define         sf              scanf
#define         pf              printf
#define         sf1(a)          scanf("%d",&a)
#define         sf2(a,b)        scanf("%d %d",&a,&b)
#define         sf3(a,b,c)      scanf("%d %d %d",&a,&b,&c);
#define         sfl1(a)         scanf("%lld",&a)
#define         sfl2(a,b)       scanf("%lld %lld",&a,&b)
#define         sfl3(a,b,c)     scanf("%lld %lld %lld",&a,&b,&c);

#define         pro             printf("PRINT  ::  DEBUG\n")
#define         pcase           printf("Case %d: ",kase++)

//    constants

#define         INF             (1 << 31)

#define         ll              long long
#define         pii             pair<ll,ll>

//	typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

using namespace std;

int kase = 1;
int phi[5000005];
unsigned ll score[5000005];

void compute_totient() {
	for(int i=1; i<=5000000; ++i) 
		phi[i]=i;
	for(int p=2; p<=5000000; p++) {
		if(phi[p]==p) {
			for(int j=p; j<=5000000; j+=p)
                phi[j] -= phi[j]/p;
		}
	}
}

void compute_score() {
	score[0] = score[1] = 0;
	for(int i=2; i<=5000000; i++)  {
		score[i] = score[i-1] + ((unsigned ll)phi[i]*(unsigned ll)phi[i]);
	}
}

int main()
{
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	compute_totient();
	compute_score();

	int test;
	sf1(test);
      
	while(test--) {
		int a,b;
		sf2(a,b);
		unsigned ll ans = score[b]-score[a-1];
		pcase;
		pf("%llu\n",ans);
	}

	return 0;
}
