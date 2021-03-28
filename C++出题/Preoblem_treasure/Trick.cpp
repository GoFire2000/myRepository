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
void Init();
int main(){
	freopen("test12_example2.in","r",stdin);
	freopen("Trick.out","w",stdout);
	Init();
	return 0;
}
void Init(){
	scanf("%d%d%d",&n,&m,&K);
	for(int i=1;i<=K;i++){
		int x,y;scanf("%d%d",&x,&y);
		flag[x][y]=true; 
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
