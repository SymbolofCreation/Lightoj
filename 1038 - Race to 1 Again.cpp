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
std::vector<int> divi[100005];
double dp[100005];
bool vis[100005];

void divisors() {
	for(int i=1; i<=100000; i++) {
		for(int j=i; j<=100000; j+=i)
			divi[j].push_back(i);
	}
}

double rec(int x) {
	if(x==1)
		return 0.0;
	if(vis[x])
		return dp[x];
	vis[x] = true;

	double sum = 0;
	int total = 0;
	for(int i=0; i<divi[x].size(); i++) {
		int a = divi[x][i];

		sum += 1.0 + rec(x/a);
		total++;
	}

	return dp[x] = (double)sum/(double)(total-1);
}

int main()
{
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	int test;
	cin >> test;

	divisors();

	while(test--) {
		cin >> n;
		pcase;
		double ans = rec(n);

		cout << fixed;
		cout.precision(10);
		cout << ans << endl;
	}

	return 0;
}
