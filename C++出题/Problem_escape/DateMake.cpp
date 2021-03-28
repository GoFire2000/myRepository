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
struct Node{
	int x,y,z;
	Node(){};
	Node(int xx,int yy,int zz){
		x=xx;y=yy;z=zz;
	}
	bool operator == (const Node & a)const{
		return x==a.x && y==a.y && z==a.z;
	}
};
int n,m,h;
Node randNode(){
	return Node(rand()%n,rand()%m,rand()%h);
}
void Init();
int main(){
	srand(time(NULL));
	freopen("test12.in","w",stdout);
//	freopen()
	srand(time(NULL));
	srand(time(NULL));
	srand(time(NULL));
	srand(time(NULL));
	srand(time(NULL));
	srand(time(NULL));
	srand(time(NULL));
	srand(time(NULL));
	srand(time(NULL));
	srand(time(NULL));
	Init();
	return 0;
}
void Init(){
	n=200,m=200,h=200;
	printf("%d %d %d\n",n,m,h);
	Node S=randNode(),T=randNode(),P=randNode();
	while(S==T) T=randNode();
	while(P==S || P==T) P=randNode();
	for(int k=0;k<h;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(Node(i,j,k)==S) printf("S");
				else if(Node(i,j,k)==T) printf("T");
				else if(Node(i,j,k)==P) printf("P");
				else {
					int x=rand()%10;
					if(x<=5) printf("#");
					else printf("*");
				}	
			}
			puts("");
		}
		if(k!=h-1) puts(""); 
	}
}

