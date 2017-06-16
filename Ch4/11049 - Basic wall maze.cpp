#include<bits/stdc++.h>
using namespace std;
struct point
#define R 6
#define C 6
{
	int x,y;
};
int grid[6][6], hwalls[7][6], vwalls[6][7];
int par[6][6];
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
char dir[]={'N','S','W','E'};
void printPath(int x, int y)
{
	if(par[x][y]==-1)return;
	printPath(x-dr[par[x][y]],y-dc[par[x][y]]);
	cout<<dir[par[x][y]];
}
bool can(int px, int py, int x,int y)
{
	if(x<0 || y<0 ||  x>=R || y>=C || grid[x][y]!=-1)return false;
	if(py==y)
	{
		if(px<x)
		{
			if(hwalls[x][y]==-1)return false;
			return true;
		}
		else 
		{
			if(hwalls[px][y]==-1)return false;
			return true;
		}
	}
	else
	{
		if(py<y)
		{
			if(vwalls[x][y]==-1)return false;
			return true;
		}
		else 
		{
			if(vwalls[x][py]==-1)return false;
			return true;
		}
	}
	return true;
}
void BFS(point s, point d)
{
	queue<point>q;
	q.push(s);
	grid[s.x][s.y]=0;
	while(!q.empty())
	{
		point f=q.front();q.pop();
		for(int i=0;i<4;i++)
		{
			int nx=f.x+dr[i],ny=f.y+dc[i];
			point np;
			np.x=nx;np.y=ny;
			if(can(f.x,f.y,nx,ny))
			{
				par[nx][ny]=i;
				if(nx==d.x && ny==d.y)return;
				grid[nx][ny]=0;
				q.push(np);
			}
		}
		
	}
	
}
int main()
{
	char c;
	int x,y,xx,yy;
	point S,D;
	scanf("%d%d",&x,&y);
	while(x||y)
	{
		memset(hwalls,0,sizeof hwalls);	
		memset(vwalls,0,sizeof vwalls);
		memset(grid,-1,sizeof grid);
		memset(par,-1,sizeof par);
		S.x=y-1;S.y=x-1;
		scanf("%d%d",&x,&y);
		D.x=y-1;D.y=x-1;
		for(int i=0;i<3;i++)
		{
			scanf("%d%d",&y,&x);
			scanf("%d%d",&yy,&xx);
			if(x==xx)
			{
				for(int k=y+1;k<=yy;k++)
				hwalls[x][k-1]=-1;
			}
			else 
			{
				for(int k=x+1;k<=xx;k++)
				vwalls[k-1][y]=-1;
			}
		}
		BFS(S,D);
		printPath(D.x,D.y);
		printf("\n");
	scanf("%d%d",&x,&y);
	}
}
