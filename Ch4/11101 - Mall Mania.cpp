#include<bits/stdc++.h>
using namespace std;
queue<pair<int,pair<int,int> > >q;
int dr[]={-1,1,0,0};
int dc[]={0,0,1,-1};
int grid[2005][2005];
bool can(int x, int y)
{
	if(x<0||y<0||x>2000||y>2000 || grid[x][y]!=-1)return false;
	return true;
}
bool arrived(int x, int y)
{
	if(x>=0 && y>=0 && x<=2000 && y<=2000 && grid[x][y]==1)return true;
	return false;
}
int BFS()
{
	while(!q.empty())
	{
		pair<int,pair<int,int> > f=q.front();q.pop();
		for(int i=0;i<4;i++)
		{
			int nx=f.second.first+dr[i],ny=f.second.second+dc[i];
		
			if(can(nx,ny))
			{
				grid[nx][ny]=0;
				q.push(make_pair(f.first+1,make_pair(nx,ny)));
				
			}
			else if(arrived(nx,ny))return f.first+1;
		}
	}
}
int main()
{
	int m1,m2,x,y;
	vector<int> dest;
	scanf("%d",&m1);
	while(m1)
	{
		q=queue<pair<int,pair<int,int> > >();
		memset(grid, -1, sizeof grid);
		for(int i=0;i<m1;i++)
		{
			scanf("%d%d",&x,&y);
			
			grid[x][y]=0;
			q.push(make_pair(0,make_pair(x,y)));
		}
		scanf("%d",&m2);
		for(int i=0;i<m2;i++)
		{
			scanf("%d%d",&x,&y);
			grid[x][y]=1;
		}
		printf("%d\n",BFS());
		scanf("%d",&m1);
	}
}
