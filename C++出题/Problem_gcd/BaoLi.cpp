#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
#define Inf 1e9
const int maxn=120000;
int a[maxn];
int n,Q;
int Gcd(int x,int y){
    if(x==0) return y;
    if(y==0) return x;
    int r=x%y;
    while(r){
        x=y;y=r;r=x%y;
    }
    return y;
}
int Query(){
    int gcd=abs(a[1]);
    for(int i=2;i<=n;i++){
        gcd=Gcd(abs(a[i]),gcd);
    }
    return gcd;
}
void Init();
signed main(){
    Init();
    return 0;
}
void Init(){
    scanf("%lld%lld",&n,&Q);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=Q;i++){
        int d;scanf("%lld",&d);
        for(int j=1;j<=n;j++) a[j]+=d;
        printf("%lld\n",Query());
    }
}
