#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int grid[100][100],dist[100][100],inDeg[100][100],R,C;

int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
bool lower(int i, int j, int x, int y)
{
	if(i<0||i>=R||j<0||j>=C)return false;
	if(x<0||x>=R||y<0||y>=C)return false;
	return grid[i][j]<grid[x][y];
}
int getInDeg(int i, int j)
{
	int sum=0;
	for(int k=0;k<4;k++)
	{
		if(lower(i,j,i+dr[k],j+dc[k]))sum++;
	}
	return sum;
}
void print()
{
	for(int i=0;i<R;i++)
		{
			for(int j=0;j<C;j++)
			{
				cout<<dist[i][j]<<" ";
			}
			cout<<endl;
		}
			cout<<endl;
		for(int i=0;i<R;i++)
		{
			for(int j=0;j<C;j++)
			{
				cout<<inDeg[i][j]<<" ";
			}
			cout<<endl;
		}
}
int main()
{
	int T;

	scanf("%d",&T);
	string name;
	char ss[500];
	while(T--)
	{
		scanf("%s",&ss[0],sizeof ss);
		name=ss;
		priority_queue<ii> Q;
		scanf("%d%d",&R,&C);
		for(int i=0;i<R;i++)
		{
			for(int j=0;j<C;j++)
			{
				scanf("%d",&grid[i][j]);
				dist[i][j]=0;
				inDeg[i][j]=0;
			}
		}
		for(int i=0;i<R;i++)
		{
			for(int j=0;j<C;j++)
			{
				inDeg[i][j]=getInDeg(i,j);
				if(!inDeg[i][j])
				{ 
					dist[i][j]=1;
					Q.push(ii(1,(i*C)+j));
				}
			}
		}
		
	
		int ans=-1e9;
		while(Q.size())
		{
			ii front = Q.top(); Q.pop();
			int v=front.second;
			int curx=v/C,cury=v%C;
			for(int i = 0;i<4;i++)
			{
				int nx=curx+dr[i],ny=cury+dc[i];
				if(lower(nx,ny,curx,cury))
				{
					dist[nx][ny]=max(dist[nx][ny],1+dist[curx][cury]);
					if(--inDeg[nx][ny] == 0)
						Q.push(ii(dist[nx][ny],((nx*C)+ny)));
				}
			}
			ans=max(ans,dist[curx][cury]);
		}
		printf("%s: %d\n",name.c_str(),ans);
		
	
	}
	
	return 0;
}
