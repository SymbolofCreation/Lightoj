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
int prime[6] = {2,3,5,7,11,13};

std::map<int, int> mp;

void prime_factorization(int n) {
	for(int i=0; i<6 and (prime[i]*prime[i]<=n); i++) {
		if(n%prime[i]==0) {
			while(n%prime[i]==0) {
				n /= prime[i];
				mp[prime[i]]++;
			} 
		}
	}
	if(n>1)
		mp[n]++;
}

int main()
{
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	int test;
	cin >> test;

	while(test--) {
		mp.clear();
		int n;
		cin >> n;
		
		for(int i=2; i<=n; i++)
			prime_factorization(i);

		pcase;
		cout << n << " = ";
		int cnt = 0;
		for (std::map<int,int>::iterator it=mp.begin(); it!=mp.end(); ++it) {
			cnt++;
			cnt == 1 ? cout << (it->first) << " (" << (it->second) << ")" : 
						cout << " * " << it->first << " (" << it->second << ")";
		}
		cout << endl;
	}

	return 0;
}
