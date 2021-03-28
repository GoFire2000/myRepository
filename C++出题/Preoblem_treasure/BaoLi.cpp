#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL long long
#define Inf 1e9
const int maxn=5050;
int n,m,K,f[maxn][maxn];
bool flag[maxn][maxn];
struct Node{
	int x,y;
}a[maxn*maxn]; 
void Init();
int main(){
	Init();
	return 0;
}
void Init(){
	scanf("%d%d%d",&n,&m,&K);
	for(int i=1;i<=K;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		flag[a[i].x][a[i].y]=true;
	}
	int cnt=K;
	for(int i=1;i<=cnt;i++){
		for(int j=1;j<i;j++){
			if(a[i].x!=a[j].x && a[i].y!=a[j].y) {
				if(flag[a[i].x][a[j].y] && !flag[a[j].x][a[i].y]) {
					flag[a[j].x][a[i].y]=true;
					++cnt;
					a[cnt].x=a[j].x;a[cnt].y=a[i].y;
				}
				if(flag[a[j].x][a[i].y] && !flag[a[i].x][a[j].y]){
					flag[a[i].x][a[j].y]=true;
					++cnt;
					a[cnt].x=a[i].x;a[cnt].y=a[j].y;	
				} 
			}
		}
	}
	int num=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			num+=flag[i][j];
			f[i][j]=max(f[i-1][j],f[i][j-1])+flag[i][j];
		}
	}
	printf("%d %d\n",num,f[n][m]);
}
