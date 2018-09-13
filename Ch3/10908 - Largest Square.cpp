#include <bits/stdc++.h>
using namespace std;
#define MAX 105
int M,N;
char grid[MAX][MAX];
bool can(char color, int x, int y){
	if(x<0 || y<0 || x>=M || y>=N || grid[x][y]!=color)return false;
	return true;
}
int visit(int x, int y){
	 bool ok=true;
	 int ans=1, k=1;
	 char color=grid[x][y];
	 while(ok){		
	 //	cout<<k<<endl;
		for(int i=x-k;i<=x+k && ok;i++)
		for(int j=y-k;j<=y+k && ok;j++){
		//	cout<<i<<" "<<j<<endl;
			if(!can(color,i,j))ok=false;
		}
		if(ok)ans+=2;
		else return ans;
		k++;
	 }
}
int main() {
	int T, Q, tmp;
	int mx;
	scanf("%d",&T);
	while(T--){
		mx=0;
		scanf("%d%d%d",&M,&N,&Q);
		cout<<M<<" "<<N<<" "<<Q<<endl;
		for(int i=0;i<M;i++)for(int j=0;j<N;j++)scanf(" %c",&grid[i][j]);
		while(Q--){
			int i,j;
			scanf("%d%d",&i,&j);
			//i--;j--;
			mx=visit(i,j);
			cout<<mx<<endl;
		}
		
	}
	return 0;
}