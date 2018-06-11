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
int prime[300000],nprime = 0;
int mark[1000005];

void sieve(int n) {
	int limit = sqrt(n*1.)+2;
	mark[1] = 1;

	for(int i=4; i<n; i+=4) mark[i] = 1;

	prime[nprime++] = 2;
	for(int i=3; i<=n; i+=2) {
		if(!mark[i]) {
			prime[nprime++] = i;
			if(i<=limit) {
				for(int j=i*i; j<n; j+=i*2)
					mark[j] = 1;
			}
		}
	}
}

ll numberofdivisors(ll n) {
	ll ret = 1,cnt;
	for(ll i=0; i<78498 && ((ll)prime[i]*(ll)prime[i]<=n); i++) {
		if(n%prime[i]==0) {
			cnt = 1;
			n /= prime[i];
			while(n%prime[i]==0) {
				cnt++;
				n /= prime[i];
			}
			ret *= (cnt+1);
		}
	} 
	if(n>1) 
		ret *= 2;
	return ret;
}

int main()
{
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	int test;
	cin >> test;

	sieve(1000002);

	while(test--) {
		ll n;
		cin >> n;
		pcase;
		cout << numberofdivisors(n)-1 << endl;
	}

	return 0;
}
