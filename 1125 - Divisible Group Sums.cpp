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
#define         pcase           printf("Case %d:\n",kase++)

//    constants

#define         INF             (1 << 31)

#define         ll              long long int
#define         pii             pair<ll,ll>

//	typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

using namespace std;

int kase = 1;
ll n,mod,cnt,q;

std::vector<ll> v;
ll dp[300][30][30];

ll rec(ll pos,ll rem,ll taken) {
	if(taken==cnt)
		return rem == 0 ? 1 : 0;
	if(pos>=n)
		return 0;

	if(dp[pos][rem][taken]!=-1)
		return dp[pos][rem][taken];

	ll ret = rec(pos+1,rem,taken)+rec(pos+1,((rem%mod+v[pos])%mod+mod)%mod,taken+1);   //negative number can come. ((rem%mod)+(v[pos]%mod))%mod will not work 
	return dp[pos][rem][taken] = ret;
}

int main()
{
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	int test;
	cin >> test;

	while(test--) {
		cin >> n >> q;
		v.clear();
		for(int i=0; i<n; i++) {
			ll x;
			cin >> x;
			v.push_back(x);
		}
		pcase;
		while(q--) {
			cin >> mod >> cnt;
			memset(dp,-1,sizeof(dp));
			cout << rec(0,0,0) << endl;
		}
	}

	return 0;
}	
