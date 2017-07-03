#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
int grid[80][80],n;
int T[80][80][6][4];
bool found;
int walk(int x, int y, int n_left, int dir)
{
	if(x<0||y<0||x>=n||y>=n || n_left<0)return -INF;
	if(n_left==0 &&grid[x][y]<0)return -INF;
	if(x==n-1 && y==n-1)
	{
		found=true;
		return grid[x][y];
	}
	if(T[x][y][n_left][dir]==-1)
	{
		int a,b,c,tmp=n_left;
		a=b=c=-INF;
		if(grid[x][y]<0)tmp--;
		a=walk(x+1,y,tmp,2)+grid[x][y];
		if(dir!=0)b=walk(x,y+1,tmp,1)+grid[x][y];	
		if(dir!=1)c=walk(x,y-1,tmp,0)+grid[x][y];
		T[x][y][n_left][dir]=max(a,max(b,c));
	}
	return T[x][y][n_left][dir];
}
int main()
{
	int k,C=1,ans;
	while(scanf("%d%d",&n,&k) && (n||k))
	{
		memset(T,-1,sizeof T);
		found=false;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			scanf("%d",&grid[i][j]);
		ans=walk(0,0,k,1);
		printf("Case %d: ",C++);
		if(found)
		printf("%d\n",ans);
		else printf("impossible\n");
	}

	return 0;
}
