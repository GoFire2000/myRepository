#include <cmath>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL long long
#define Inf 1e9
const int maxn=1010;
bool vis[maxn];
void Init();
int main(){
	Init();
	return 0;
}
void Init(){
	double x=pow(2.0,1000);
	double y=pow(2.0,998);
	printf("%lf\n%lf\n%lf\n",x,y,x/y);
}

