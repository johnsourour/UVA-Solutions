#include<bits/stdc++.h>
using namespace std;

#define MAX_STEPS 45
typedef unsigned long long ll;

#define MAX_STEPS 45
#define EMPTY 15
#define INF 1e9

int dr[4]={1,-1,0,0};
int dc[4]={0,0,-1,1};
char dir[4]={'D','U','L','R'};
int grid[4][4];
int p[MAX_STEPS];

int lim, next_lim;

map<ll, int> vis;

bool done(){
	for(int i=0;i<4;i++)for(int j=0;j<4;j++)if(grid[i][j]!=(i*4)+j)return false;
	return true;
}

ll state(){
	ll ret=0;
	for(int i=0;i<4;i++)for(int j=0;j<4;j++){
		ret<<=4;
		ret+=grid[i][j];
	}
	return ret;
}

bool can(int i, int j){
	if(i<0 || j<0 || j>=4 || i>=4)return false;
	return true;
}

int eucl_dist(int i, int j, int x, int y){
	return abs((grid[i][j]/4)-x)+abs((grid[i][j]%4)-y);
}

int h(){
	int ans=0;
	for(int i=0;i<4;i++)for(int j=0;j<4;j++)if(grid[i][j]!=EMPTY)ans+=eucl_dist(i, j, i, j);
	return ans;
}
int delta_h(int x1, int y1, int x2, int y2){
	return eucl_dist(x2, y2, x1, y1) - eucl_dist(x2, y2, x2, y2);
}

void swap(int x1, int y1, int x2, int y2){
	swap(grid[x1][y1], grid[x2][y2]);
}

bool DLS(int h, int g){
//	cout<<h<<" "<<g<<endl;
	if(g+h>lim){
		next_lim = min(next_lim, g+h);
		return false;
	}
	if(done())return true;
	
	ll cur=state();
	
	if(vis.find(cur)!=vis.end() && vis[cur] <= g)return false;
	
	vis[cur]=g;
	
	int i,j;
	bool found=false;
	for(i=0;i<4 && !found;i++)for(j=0;j<4 && !found;j++)if(grid[i][j]==EMPTY)found=true;
	j--;i--;
//	for(int k=0;k<4;k++){for(int kk=0;kk<4;kk++)cout<<grid[k][kk]<<" ";cout<<endl;}
//	cout<<" found at "<<i<<" "<<j<<endl;
	for(int d = 0; d<4;d++){
		int nx = i+dr[d], ny = j+dc[d];
		if(can(nx, ny)){
			int diff = delta_h(i, j, nx, ny);
			swap(i, j, nx, ny);
			p[g+1]=d;
			if(DLS(h+diff, g+1)){
				return true;
			}
			swap(i, j, nx, ny);
		}
	}
	return false;
	
	
}
int IDAS(){
	lim = h();
	while(1){
		next_lim=INF;
		memset(p, -1, sizeof p);
		vis.clear();
		if(DLS(h(), 0)){
			return lim;
		}
		lim = next_lim;
		if(lim>MAX_STEPS){
			return -1;
		}
	}
	return -1;
}

void printAns(int n){
	if(n<=0)return;
	printAns(n-1);
	if(p[n]>=0)cout<<dir[p[n]];
}


int main()
{
	int TC,tmp;
	bool seen[16];
	scanf("%d",&TC);
	while(TC--){
		memset(seen, 0, sizeof seen);
		int sum=0;
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++){ 
				scanf("%d",&tmp); 
				tmp--;
				if(tmp<0){
					tmp=EMPTY;
					sum+=i+1;
				}
				else{
					sum+=count(seen, seen + tmp, false);
					seen[tmp]=true;
				}
				grid[i][j]=tmp;
			}
		
		if(sum%2 == 0){
			int ans = IDAS();
			printAns(ans);
			cout<<endl;
		}
		else{
			printf("This puzzle is not solvable.\n");
			
		}
	}
}
