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
string s;

int dp[55][55][55];

bool is_consonant(char c) {
	return c!='A' && c!='E' && c!='I' && c!='O' && c!='U';
}

int rec(int pos,int vowel,int consonant) {
	if(vowel>=3 || consonant>=5)
		return 1;
	if(pos>=n)
		return 2;

	if(dp[pos][vowel][consonant]!=-1)
		return dp[pos][vowel][consonant];
	
	int ret = 0;
	if(s[pos]=='?')
		ret = rec(pos+1,vowel+1,0) | rec(pos+1,0,consonant+1);
	else if(is_consonant(s[pos]))
		ret = rec(pos+1,0,consonant+1);
	else
		ret = rec(pos+1,vowel+1,0);

	return dp[pos][vowel][consonant] = ret;
}

int main()
{
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	int test;
	cin >> test;

	while(test--) {
		memset(dp,-1,sizeof(dp));
		cin >> s;
		n = s.size();

		int ans = rec(0,0,0);
		pcase;
		ans == 1 ? cout << "BAD" << endl : ans == 2 ? cout << "GOOD" << endl : cout << "MIXED" << endl;
	}

	return 0;
}
