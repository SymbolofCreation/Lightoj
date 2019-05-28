#include<bits/stdc++.h>
using namespace std;

int main()
{

    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    
    int t;
    cin>>t;

    for(int i=1; i<=t; i++) {

        int x1,x2,y1,y2,y,x;
        cin >> x1 >> y1 >> x2 >> y2;
        
        y=abs(y1-y2);
        x=abs(x1-x2);
        
        if(y%2 != x%2) {
            printf("Case %d: impossible\n", i);
            continue;
        }

        else if(y==x) {
            printf("Case %d: 1\n", i);
            continue;
        }

        else {
            printf("Case %d: 2\n", i);
        }
    }

    return 0;
}
