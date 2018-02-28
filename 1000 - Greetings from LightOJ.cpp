#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int t,kase=1;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b;
        c=a+b;
        printf("Case %d: %d\n",kase,c);
        kase++;
    }
    return 0;
}
