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
bool flag;
std::vector<int> v;
bool vis[1001];
int dp[1005];

inline int rec(int pos) {
	if(pos>=n)
		return 0;
	if(pos==n-1 && flag)
		return 0;

	if(dp[pos]!=-1)
		return dp[pos];

	int ret = max(rec(pos+1),v[pos]+rec(pos+2));
	return dp[pos] = ret;
}

inline void reset(int x) {
	if(x)
		v.clear();
	memset(dp,-1,sizeof(dp));
	memset(vis,false,sizeof(vis));
}

int main()
{
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	int test;
	cin >> test;

	while(test--) {
		reset(1);
		cin >> n;
		for(int i=0; i<n; i++) {
			int x;
			cin >> x;
			v.push_back(x);
		}

		reset(0);
		flag = false;
		int a = rec(1);

		reset(0);
		flag = true;
		int b = v[0]+rec(2);

		pcase;
		cout << max(a,b) << endl;
	}

	return 0;
}
