#include <bits/stdc++.h>

using namespace std;

double inf=1e9;
int n;
int x[16],y[16];
double dp[(1<<16)+2];

int on(int n, int pos){
    return n|(1<<pos);
}
int of(int n, int pos){
    return n& ~(1<<pos);
}
bool check(int n, int pos){
    return bool(n&(1<<pos));
}

double dist(int ax, int ay, int bx, int by){
    return hypot(bx-ax, by-ay);
}

double cal(int mask){
    if(mask==(1<<n)-1) return 0;
    if(dp[mask]!=0) return dp[mask];

    double mn=inf;
    for(int i=0; i<n; ++i){

        if(!check(mask,i)){
            for(int j=0; j<n; ++j){
                if(i!=j and !check(mask,j)){
                    double d=dist(x[i],y[i],x[j],y[j]);
                    double ret=d+cal(on(on(mask,j),i));
                    mn=min(mn,ret);
                }

            }

        }
    }
    return dp[mask]=mn;
}

int main()
{
    int nn,t=0;
    while(~scanf("%d",&nn)){
        if(nn==0) break;
        n=2*nn;
        memset(dp,0,sizeof dp);

        string s;
        for(int i=0; i<n; ++i){
            cin>>s;
            scanf("%d %d",x+i,y+i);
        }

        printf("Case %d: %.2f\n",++t,cal(0));
    }
    return 0;
}
