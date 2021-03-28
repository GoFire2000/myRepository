#include <ctime>
#include <cmath>
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
	srand(time(NULL));
	srand(time(NULL));
	srand(time(NULL));
	srand(time(NULL));
	srand(time(NULL));
	freopen("test12_example2.in","w",stdout);
	
	srand(time(NULL));
	Init();
	return 0;	
}
void Init(){
	srand(time(NULL));
	int n=4,m=4;
	int K=Rand()%(n*m);
	srand(time(NULL));
	printf("%d %d %d\n",n,m,K);
	for(int i=1;i<=K;i++){
		int x=rand()%n+1;
		int y=rand()%m+1;
		printf("%d %d\n",x,y);
	}
}

