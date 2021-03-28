#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL long long
#define Inf 1e9
const int maxn=1010;
int Rand(){
	return rand()<<15|rand();	
}
void Init();
int main(){
	//2 5 6 7 11 12
	freopen("test19.in","w",stdout);
    srand(time(NULL));
    Init();
    return 0;
}
void Init(){
	int n=100000,Q=100000;
	printf("%d %d\n",n,Q);
	for(int i=1;i<=n;i++){
		if(i<=n-2) printf("%d ",i*21);
		else {
			printf("%d %d\n",(n-2)*21+1,(n-2)*21+2);
			break;	
		}
		continue;
		int x=Rand()%10+1;int tp=rand()%2;
		if(tp==0) x=-x;
		if(i!=n) printf("%d ",x);
		else printf("%d\n",x);
//		now<<=1;
	} 
	for(int i=1;i<=Q;i++){
		printf("%d\n",i*21);
		continue;
		int x=Rand()%10;int tp=rand()%2;
		if(tp==0) x=-x;
		printf("%d\n",x);
	}
}
