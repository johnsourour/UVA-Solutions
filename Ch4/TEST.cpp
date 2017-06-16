#include<bits/stdc++.h>
using namespace std;
struct point
{
	int x,y,z;
};
int L,R,C,grid[35][35][35];
int dr[]={-1,1,0,0,0,0};
int dc[]={0,0,-1,1,0,0};
int dl[]={0,0,0,0,-1,1};
bool can(int x,int y, int z)
{
	if(x<0 || y<0 || z<0 || x>=R || y>=C || z>=L || grid[x][y][z]!=-1)return false;
	return true;
}
int BFS(point s, point d)
{
	queue<pair<point,int> >q;
	q.push(make_pair(s,0));
	while(!q.empty())
	{
		pair<point,int> f=q.front();q.pop();
		for(int i=0;i<6;i++)
		{
			int nx=f.first.x+dr[i],ny=f.first.y+dc[i],nz=f.first.z+dl[i];
			point np;
			np.x=nx;np.y=ny;np.z=nz;
			if(can(nx,ny,nz))
			{
				if(nx==d.x && ny==d.y && nz==d.z)return f.second+1;
				grid[nx][ny][nz]=0;
				q.push(make_pair(np,f.second+1));
			}
		}
		
	}
	
	return -1;
}
int main()
{
	char c;
	scanf("%d%d%d",&L,&R,&C);
	while(L||R||C)
	{
		point S,D;
		for(int k=0;k<L;k++)
			for(int i=0;i<R;i++)	
				for(int j=0;j<C;j++){
					scanf(" %c",&c);
					if(c=='S')
					{
						S.x=i;S.y=j;S.z=k;
						grid[i][j][k]=-1;
					}
					else if(c=='E')
					{
						D.x=i;D.y=j;D.z=k;
						grid[i][j][k]=-1;
					}
					else if(c=='.')
					 grid[i][j][k]=-1;
					else grid[i][j][k]=1;
					
				}
		int ans= BFS(S,D);
		if(ans==-1) printf("Trapped!\n");
		else printf("Escaped in %d minute(s).\n",ans);
		scanf("%d%d%d",&L,&R,&C);
	}
}
