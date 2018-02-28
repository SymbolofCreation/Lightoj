#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include <deque>
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
#define sf scanf
#define pf printf
#define pro printf("1\n")
using namespace std;
int main(){
    int t,k=1;
    string pushLeft="pushLeft",pushRight="pushRight",popLeft="popLeft",popRight="popRight";
    sf("%d",&t);
    while(t--)
    {
        int n,m;
        sf("%d %d",&n,&m);
        deque<int>dq;
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            int y;
            string x;
            cin>>x;
            if(i==0)
            {
                pf("Case %d:\n",k++);
            }
            if(x==pushLeft)
            {
                cin>>y;
                if(cnt==n)
                {
                    pf("The queue is full\n");
                    continue;
                }
                dq.push_front(y);
                pf("Pushed in left: %d\n",y);
                cnt++;
            }
            else if(x==pushRight)
            {
                cin>>y;
                if(cnt==n)
                {
                    pf("The queue is full\n");
                    continue;
                }
                dq.push_back(y);
                pf("Pushed in right: %d\n",y);
                cnt++;
            }
            else if(x==popLeft)
            {
                if(cnt==0)
                {
                    pf("The queue is empty\n");
                    continue;
                }
                int z=dq.front();
                dq.pop_front();
                pf("Popped from left: %d\n",z);
                cnt--;
            }
            else if(x==popRight)
            {
                if(cnt==0)
                {
                    pf("The queue is empty\n");
                    continue;
                }
                int z=dq.back();
                dq.pop_back();
                pf("Popped from right: %d\n",z);
                cnt--;
            }
        }
    }
    return 0;
}
