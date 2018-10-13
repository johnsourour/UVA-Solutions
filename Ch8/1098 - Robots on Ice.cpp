#include<bits/stdc++.h>
using namespace std;
#define MAX 8

typedef pair<int,int> ii;

int dr[4]={0,0,-1,1};
int dc[4]={-1,1,0,0};

int m,n,ans;
int checkIns[4];
int cols[4], rws[4];
bool vis[MAX][MAX];
bool vis2[MAX][MAX];
bool can(int x, int y){
	if(x<0 || y<0 || x>=n || y>=m)return false;
	return true;
}

void cpy(){
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)vis2[i][j]=vis[i][j];
}

bool disconnected(){
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(!vis2[i][j])return true;
	return false;
}

void DFS2(int sx, int sy){
	vis2[sx][sy]=1;
	for(int i=0;i<4;i++){
		int nx=sx+dr[i], ny=sy+dc[i];
		if(can(nx,ny) && !vis2[nx][ny]){
			DFS2(nx,ny);
		}
	}
}

bool able(int x, int y, int depth, int nxt_cp){
	if(x==rws[nxt_cp] && y==cols[nxt_cp]) return depth==checkIns[nxt_cp];

	for(int i=0;i<4;i++)
	{
		if(i==nxt_cp)continue;
		if(x==rws[i] && y==cols[i]) return false;
	}

	int dist = abs(x-rws[nxt_cp]) + abs(y-cols[nxt_cp]) ;
	
	return depth+dist<=checkIns[nxt_cp];
}

void DFS(int x, int y, int depth, int nxt_cp){
///	cout<<x<<" "<<y<<" "<<depth<<endl;
	
	vis[x][y]=1;
	
	if(depth==checkIns[nxt_cp]){
		if(nxt_cp==3)ans++;
		else nxt_cp++;
	}
	
	for(int i=0;i<4;i++){
		int nx=x+dr[i], ny=y+dc[i];

		if(can(nx,ny) && !vis[nx][ny]  && able(nx, ny, depth+1, nxt_cp)){
			cpy();
			DFS2(0, 1);
			if(disconnected())continue;
			DFS(nx, ny, depth+1, nxt_cp);
		}
	}
	vis[x][y]=0;
}

int main(){
	int K=0, tot;
	cols[3]=1;
	rws[3]=0;
	while(scanf("%d%d", &n,&m)!=EOF && n && m){
	
		memset(vis, 0, sizeof vis);
	
		tot=n*m;
		checkIns[3]=tot;
		
		for(int i=0;i<3;i++){
			scanf("%d%d", &rws[i],&cols[i]);
			checkIns[i]=((i+1)*tot)/4;
		}
		
		ans=0;
		DFS(0,0,1,0);
		
		printf("Case %d: %d\n",++K,ans);
	}
	return 0;
}