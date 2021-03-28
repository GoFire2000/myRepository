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
int root[maxn*2];
int Findroot(int x){
	if(root[x]!=x) root[x]=Findroot(root[x]);
	return root[x];
}
void Init();
int main(){
	
//	freopen("test12_example2.in","r",stdin);
//	freopen("test4.in","r",stdin);
//	freopen("Std.out","w",stdout);
	Init();
	return 0;
}
void Init(){
	scanf("%d%d%d",&n,&m,&K);
	for(int i=1;i<=n+m;i++)
		root[i]=i;
	for(int i=1;i<=K;i++){
		int x,y;scanf("%d%d",&x,&y);
		flag[x][y]=true;
		int rx=Findroot(x),ry=Findroot(n+y);
		if(rx^ry) root[rx]=ry; 
	}
	int num=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int rx=Findroot(i),ry=Findroot(n+j);
			if(rx==ry) flag[i][j]=true,++num;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			f[i][j]=max(f[i-1][j],f[i][j-1])+flag[i][j];
		}
	}
	printf("%d %d\n",num,f[n][m]);
}
