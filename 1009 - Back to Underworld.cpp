/*input
2
2
1 2
2 3
3
1 2
2 3
4 2
*/

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

//    typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

using namespace std;

int kase = 1, zero = 0, one = 0;

std::vector<int> v[20010];
bool visited[20010];

void clean_prev_data() {
	for(int i=0; i<20010; i++) {
		v[i].clear();
	}
	memset(visited, false, sizeof(visited));
}

void dfs(int node, int val) {
	if(visited[node]==true)
		return;

	if(val==0)
		zero++;
	else if(val==1)
		one++;

	visited[node] = true;

	for(int i=0; i<v[node].size(); i++) {
		int x = v[node][i];
		if(val==0) 
			dfs(x, 1);
		else if(val==1)
			dfs(x, 0);
	}
}

int main()
{

    // freopen ("input.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);

	int test;
	sf1(test);

	while(test--) {
		clean_prev_data();

		int n;
		sf1(n);

		for(int i=0; i<n; i++) {
			int x,y;
			sf2(x,y);
			x--, y--;
			v[x].push_back(y);
			v[y].push_back(x);
		}

		int ans = 0;

		for(int i=0; i<20001; i++) {
			if(visited[i]==false && v[i].size()!=0){
				zero = 0, one = 0;
				dfs(i, 0);
				ans += max(one, zero);
			}
		}

		pcase;
		pf("%d\n", ans);
	}

    return 0;
}