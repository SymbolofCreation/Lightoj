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

int kase = 1;
int n,w,k;

struct Point {
	int x,y;

	/*bool operator < (Point &p) const {
		return y != p.y ? y < p.y : x < p.x;
	}*/
};

inline bool acomp(const Point &a, const Point &b) {
	return a.y == b.y ? a.x < b.x : a.y < b.y;
}

std::vector<Point> v;
int dp[105][105];

void reset() {
	v.clear();
	for(int i=0; i<105; i++) 
		for(int j=0; j<105; j++)
			dp[i][j] = -1;
}

int rec(int pos, int stroke) {
	if(pos>=n || stroke>=k) 
		return 0;
	if(dp[pos][stroke]!=-1)
		return dp[pos][stroke];

	int a,b;
	for(a=pos; a<n && ((v[a].y-v[pos].y) <= w); a++);
	for(b=pos+1; b<n && (v[b].y == v[pos].y); b++);

	int ret = 0;
	ret = max(rec(b,stroke) , rec(a,stroke+1)+(int)(a-pos));

	return dp[pos][stroke] = ret;
}

int main()
{
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	int test;
	cin >> test;

	while(test--) {
		reset();
		cin >> n >> w >> k;
		for(int i=0; i<n; i++) {
			Point p;
			cin >> p.x >> p.y;
			v.push_back(p);
		}
		sort(v.begin(), v.end(),acomp);

		pcase;
		cout << rec(0,0) << endl;
	}

	return 0;
}
