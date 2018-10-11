#include <bits/stdc++.h>
using namespace std;

#define MAX 505

int cell[MAX][MAX][4];
bool vis[MAX][MAX][4];
int R, C;
char dir[4]={'W','N','E','S'};
int dr[4]={0,-1,0,1};
int dc[4]={-1,0,1,0};

bool can(int x1, int y1, int d){
	if(x1<1 || x1>R || y1<1 || y1>C || vis[x1][y1][d])return false;
	return true;
}
struct state{
	int x, y, depth;
	state(int _x, int _y, int _depth){
		x=_x;
		y=_y;
		depth=_depth;
	}

};
	bool operator<(const state &a, const state &b){
		return a.depth<b.depth;
	}
int BFS(){
	queue<state> pq;
	pq.push(state(1,1,0));
	vis[1][1][0]=1;
	while(!pq.empty()){
		state front=pq.front();pq.pop();
		int x=front.x, y=front.y;
		int depth=front.depth;
		if(x==R && y==C)return depth;
		
		for(int i=0;i<4;i++){
			int nx=x+dr[i], ny=y+dc[i];
			if((cell[x][y][(depth%4)] & (1<<i)) && can(nx, ny, ((depth+1)%4))){
				vis[nx][ny][(1+depth)%4]=true;
				pq.push(state(nx,ny,depth+1));
			}
			
		}
	//	cout<<endl;
	}
	
	return -1;
}
void gen(int x, int y){
	for(int i=1;i<4;i++){
		cell[x][y][i] = ((cell[x][y][i-1]<<1) & 15)  | ((cell[x][y][i-1] & (1<<3))>>3);
	}
}
int main(){
	string tmp;
	while(scanf("%d%d",&R,&C)!=EOF){
		memset(vis, 0, sizeof vis);
		memset(cell, 0, sizeof cell);
		for(int i=1;i<=R;i++){
			for(int j=1;j<=C;j++){
				if(i==R && j==C)continue;
				cin>>tmp;
				for(int k=0;k<4;k++)
					if(tmp.find(dir[k])<tmp.length()){
						cell[i][j][0] = cell[i][j][0] | (1<<k);
					}
				gen(i,j);
			}
		}
		int ans = BFS();
		if(ans==-1){
			printf("no path to exit\n");
		}
		else
			printf("%d\n", ans);
	}
	return 0;
	
}