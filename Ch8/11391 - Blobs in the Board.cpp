#include<bits/stdc++.h>
using namespace std;

int n, r, c;
#define MAX (1<<16) - 1
#define DIR 8
int mem[MAX];

int dr[DIR]={1, -1, 0, 0, 1, -1, 1, -1};
int dc[DIR]={0, 0, -1, 1, 1, -1, -1, 1};
int lim;
bool done(int cur){
	int ans=0;
	for(int i=0;i<lim*lim;i++)if(cur & (1<<i))ans++;
	return ans==1;
}
bool can(int x, int y){
	if(x<0 || y<0 || x>=r || y>=c)return false;
	return true;
}

int DP(int cur){
	if(mem[cur]!=-1)return mem[cur];
	if(done(cur))return mem[cur]=1;
	int ans=0;
	for(int i=0;i<lim*lim;i++){
		if(cur & (1<<i)){
			int x = i/lim, y = i%lim;
			for(int k=0;k<DIR;k++){
				int nx = x+dr[k], ny = y + dc[k], npos = (nx*lim) + ny;
				int sx = nx + dr[k], sy = ny + dc[k], spos = (sx*lim) + sy;
				
				if(can(nx, ny) && can(sx, sy) && (cur & (1<<npos)) && (!(cur & (1<<spos)))){
					int neg = ~((1<<i) | (1<<npos));
					int nxt = (cur & neg) | (1<<spos);
					ans += DP(nxt);
				}
			}
		}
	}
	return mem[cur]=ans;
}
int main(){
	int TC, K=0, x, y;
	scanf("%d", &TC);
	while(TC--){
		scanf("%d%d%d", &r, &c, &n);
		memset(mem, -1, sizeof mem);
		int start=0;
		
		lim = max(r,c);
		for(int i=0;i<n;i++){
			scanf("%d%d", &x, &y);
			x--;y--;
			int pos = (x*lim)+y;
			start|=(1<<pos);
		}
		int ans = DP(start);
		printf("Case %d: %d\n", ++K, ans);
		
		
	}
	return 0;
}