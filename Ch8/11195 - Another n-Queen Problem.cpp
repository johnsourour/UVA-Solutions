#include <bits/stdc++.h>
using namespace std;
#define MAX 20

int grid[MAX];

int n,ans, done;

void solve(int i, int row, int ld, int rd){
	if(row==done){
		ans++;
		return;
	}
	if(i>=n)return;
	int avail = done & (~(row | grid[i] | rd | ld));

	while(avail){
		int lsb = avail & -avail;
		avail-=lsb;
		solve(i+1, row | lsb, (ld | lsb) << 1, (rd | lsb) >> 1);
	}
	return;
}
int main() {
	int C=0;
	string tmp;
	while(cin>>n && n){
		memset(grid, 0, sizeof grid);
		ans=0;
		done = (1<<n)-1;
		for(int i=0;i<n;i++){
			cin>>tmp;
			for(int j=0;j<n;j++){
				int on = tmp[n-1-j]=='*';
				grid[i]|=(on<<j);
			}
		}
		solve(0,0,0,0);
		printf("Case %d: %d\n",++C,ans);
	}
	return 0;
}