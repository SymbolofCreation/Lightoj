#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<deque>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
#include<functional>
#include<climits>
 
//  scan & print
 
#define sf scanf
#define pf printf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
 
#define pro printf("1\n")
#define pcase(kase) printf("Case %d: ",kase)
 
using namespace std;
 
int kase=1;
 
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
 
int ddx[]={1,1,0,-1,-1,-1,0,1};
int ddy[]={0,1,1,1,0,-1,-1,-1};
 
int GCD(int A,int B)
{
    if(!B)
        return A;
    return GCD(B,A%B);
}
 
vector<int>v[10010];
bool vis[10010];
stack<int>st;
 
void reset()
{
    memset(vis,false,sizeof(vis));
    for(int i=0;i<10010;i++)
        v[i].clear();
    while(st.size()!=0)
    {
        st.pop();
    }
}
 
void dfs(int i)
{
    if(vis[i]==true)
        return;
    vis[i]=true;
    for(int j=0;j<v[i].size();j++)
    {
        int x=v[i][j];
        if(vis[x]==false)
            dfs(x);
    }
    st.push(i);
}
 
int main()
{
    int t;
    sf1(t);
    while(t--)
    {
        reset();
        int n,m;
        sf2(n,m);
        for(int i=0;i<m;i++)
        {
            int a,b;
            sf2(a,b);
//            a--,b--;
            v[a].push_back(b);
//            v[b].push_back(a);
        }
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==false)
            {
                dfs(i);
//                cnt++;
//                cout<<i<<"  "<<cnt<<endl;
            }
        }
        memset(vis,false,sizeof(vis));
        while(st.size()!=0)
        {
            int t=st.top();
            st.pop();
            if(vis[t]==false)
            {
                dfs(t);
                cnt++;
            }
        }
        pcase(kase++);
        pf("%d\n",cnt);
    }
    return 0;
}
 
/*
 
24 31
6 19
7 19
7 10
15 17
22 20
12 14
4 14
1 4
11 5
15 24
20 2
7 23
13 10
12 20
2 3
23 21
10 17
19 11
23 11
9 18
14 21
20 15
17 6
11 7
21 23
1 19
21 13
4 24
1 21
1 19
19 13
 
 
*/
