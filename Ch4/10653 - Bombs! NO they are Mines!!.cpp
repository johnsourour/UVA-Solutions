#include<bits/stdc++.h>
using namespace std;
int adjMat[1005][1005];
int R,C;
int dr[]={-1,1,0,0};
int dc[]={0,0,1,-1};
bool can(int x, int y)
{
	if(y<0 || y>=C || x<0 || x>=R || adjMat[x][y]==1)return false;
	return true;
}
int BFS(int x, int y, int xx, int yy)
{
	queue<pair<pair<int,int>,int> > q;
	q.push(make_pair(make_pair(x,y),0));
	int ans;
	adjMat[x][y]=1;
	while(!q.empty())
	{
		pair<pair<int,int>,int> f=q.front();q.pop();
		for(int i=0;i<4;i++)
		{
			int nx=f.first.first+dr[i],ny=f.first.second+dc[i];
			//cout<<nx<<" "<<ny<<endl;
			if(can(nx,ny))
			{
				adjMat[nx][ny]=1;
				if(nx==xx && ny==yy)return f.second+1;
				q.push(make_pair(make_pair(nx,ny),f.second+1));
			}
		}
	}
	return ans;
}
int main()
{
	int n,x,y,c,xx,yy;
	scanf("%d%d",&R,&C);
	while(R||C)
	{
		memset(adjMat,0,sizeof adjMat);
		scanf("%d",&n);
		while(n--)
		{
			scanf("%d%d",&x,&c);
			while(c--)
			{
			
				scanf("%d",&y);
				adjMat[x][y]=1;
			}
		}
		scanf("%d%d%d%d",&x,&y,&xx,&yy);
		printf("%d\n",BFS(x,y,xx,yy));
		scanf("%d%d",&R,&C);
	}
	return 0;
}
