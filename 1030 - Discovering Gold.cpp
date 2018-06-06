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

#define         ll              long long int
#define         pii             pair<ll,ll>

//	typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

using namespace std;

int kase = 1,n;
std::vector<double> v;

double dp[105];

void reset() {
	for(int i=0; i<105; i++)
		dp[i] = 0.0;
	v.clear();
}

double rec(int pos) {
	if(pos==n-1)
		return dp[pos] = v[pos];

	if(dp[pos])
		return dp[pos];

	double ret = 0.0;
	int count = 0;
	for(int i=1; i<=6; i++) {
		if(pos+i<n) {
			count++;
			ret += rec(pos+i);
		}
	}

	count > 0 ? ret /= (double)count : ret = 0.0;
	return dp[pos] = ret+v[pos];
}

int main()
{
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	int test;
	cin >> test;

	while(test--) {
		reset();
		cin >> n;
		for(int i=0; i<n; i++) {
			int x;
			cin >> x;
			v.push_back(x);
		}
		pcase;
		double ans = rec(0);

		cout << fixed;
		cout.precision(10);

		cout << ans << endl;
	}

	return 0;
}
