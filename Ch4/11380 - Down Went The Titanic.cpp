#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define MAX_V 1802
#define ORIG 30
#define hi 1000
#define INF 1e9
int res[MAX_V][MAX_V], mf, f, s, t, X, Y, P; 
char  grid[30][30];
int dr[]={-1,1,0,0};
int dc[]={0,0,1,-1};
vi p; 
int togrid(int x, int y)
{
	return ((x)*ORIG)+y;
}
void augment(int v, int minEdge) 
{ 
	if (v == s) { f = minEdge; return; } 
	else if (p[v] != -1) { 
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f; res[v][p[v]] += f; 
	}
}
void EdmondKarps()
{
	mf = 0; 
	while (1) 
	{ 
		f = 0;
		vi dist(MAX_V, INF); dist[s] = 0; queue<int> q; q.push(s);
		p.assign(MAX_V, -1);
		while (!q.empty()) 
		{
			int u = q.front(); q.pop();
			if (u == t) break; 
			for (int v = 0; v < MAX_V; v++) 
				if (res[u][v] > 0 && dist[v] == INF){
					dist[v] = dist[u] + 1; q.push(v); p[v] = u;} 
		}
		augment(t, INF); 
		if (f == 0) break; 
		mf += f; 
	}
}
bool can(int x, int y)
{
	if(x<0||x>=X||y<0||y>=Y || grid[x][y]=='~' )return false;
	return true;
}
void connect(int x, int y, int intern)
{
	int cell=togrid(x,y);
	int inside=cell+900;
	for(int i=0;i<4;i++)
	{
		int nx=x+dr[i],ny=y+dc[i];
		if(can(nx,ny))
		{
			res[cell][inside]=intern;
			res[inside][togrid(nx,ny)]=hi;
		}
		if(grid[x][y]=='*')
		{
			res[s][cell]=1;
		}
		else if(grid[x][y]=='#')res[inside][t]=P;
	}
}
void init()
{
	memset(res, 0, sizeof res);
	for(int i=0;i<X;i++)for(int j=0;j<Y;j++)
	{
		if(grid[i][j]!='~')
		{
			if(grid[i][j]=='@'||grid[i][j]=='#')
			connect(i,j,INF);
			else 
			connect(i,j,1);
			
		}
	}
	
}
int main()
{
	s=MAX_V-2;t=MAX_V-1;
	while(scanf("%d%d%d",&X,&Y,&P)!=EOF)
	{
		for(int i=0;i<X;i++)for(int j=0;j<Y;j++)scanf(" %c",&grid[i][j]);
		init();
		EdmondKarps();
		printf("%d\n",mf);
	}
	return 0;
}
