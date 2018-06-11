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

std::vector<ll> calculate(ll n,ll l) {
	ll srt = sqrt(n);
	std::vector<ll> v;
	for(ll i=1; i<=srt; i++) {
		if(n%i==0) {
			if(i>l)
				v.push_back(i);
			if(i*i!=n)
				if((n/i)>l)
					v.push_back(n/i);
		}
	}
	return v;
}

int main()
{
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	int test;
	cin >> test;

	while(test--) {
		ll p,l;
		cin >> p >> l;
		std::vector<ll> ans = calculate(p-l,l);
		sort(ans.begin(),ans.end());
		pcase;
		if(ans.size()==0) {
			cout << "impossible" << endl;
			continue;
		}
		for(int i=0; i<ans.size(); i++) {
			i == 0 ? cout << ans[i] : cout << " " << ans[i];
		}
		cout << endl;
	}

	return 0;
}
