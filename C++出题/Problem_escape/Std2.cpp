#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int n,m,h;
int sx,sy,sz;
int tx,ty,tz;
int px,py,pz;
int F[301][301][301][3];
char mp[301][301][301];
struct Node{
	int x,y,z,S;
	Node(){;}
	Node(int _x,int _y,int _z,int _S){
		x = _x,y = _y,z = _z,S = _S;
	}
};
queue<Node> q;
int dx[] = {1,-1,0,0,0,0};
int dy[] = {0,0,1,-1,0,0};
int dz[] = {0,0,0,0,1,-1};
int main(){
	scanf("%d%d%d",&n,&m,&h);
	for(int k = 1;k <= h;k++){
		for(int i = 1;i <= n;i++){
			scanf("%s",mp[k][i]+1);
			for(int j = 1;j <= m;j++){
				if(mp[k][i][j] == 'S')sx=i,sy=j,sz=k;
				if(mp[k][i][j] == 'T')tx=i,ty=j,tz=k;
				if(mp[k][i][j] == 'P')px=i,py=j,pz=k;
			}
		}
	}
	memset(F,-1,sizeof F);
	F[sx][sy][sz][0] = 0;
	q.push(Node(sx,sy,sz,0));
	while(!q.empty()){
		Node D = q.front();q.pop();
		if(D.x == tx && D.y == ty && D.z == tz){
			printf("%d\n",F[D.x][D.y][D.z][D.S]);
			return 0;
		}
		for(int i = 0;i < 6;i++){
			int xx = D.x + dx[i],yy = D.y+dy[i],zz = D.z+dz[i];
			if(xx==0)xx = n;else if(xx == n+1)xx = 1;
			if(yy==0)yy = m;else if(yy == m+1)yy = 1;
			if(zz==0)zz = h;else if(zz == h+1)zz = 1;
			if(mp[zz][xx][yy] == 'P'){
				if(D.S == 0){
					if(F[xx][yy][zz][1]!=-1)continue;
					else {
						F[xx][yy][zz][1]=F[D.x][D.y][D.z][0]+1;
						q.push(Node(xx,yy,zz,1));
					}
				}
				else continue;
			}
			if(mp[zz][xx][yy] == '#'){
				if(D.S == 1){
					if(F[xx][yy][zz][2]!=-1)continue;
					else{
						F[xx][yy][zz][2] = F[D.x][D.y][D.z][1]+1;
						q.push(Node(xx,yy,zz,2));
					}
				}
				else continue;
			}
			if(mp[zz][xx][yy] == '*'||mp[zz][xx][yy]=='S'||mp[zz][xx][yy] == 'T'){
				if(F[xx][yy][zz][D.S]!=-1)continue;
				else{
					F[xx][yy][zz][D.S] = F[D.x][D.y][D.z][D.S]+1;
					q.push(Node(xx,yy,zz,D.S));
				}
			}
		}

	}
	puts("-1");
	return 0;
}