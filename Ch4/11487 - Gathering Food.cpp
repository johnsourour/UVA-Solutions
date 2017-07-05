#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
#define INF 1e9
#define MOD 20437
int n;
int grid[11][11],dist[11][11],paths[11][11];
bool V[11][11];
ii pts[28];
int dr[]={-1,0,1,0};
int dc[]={0,1,0,-1};
bool can(int x, int y, int t)
{
	if(x<0||y<0||x>=n||y>=n||grid[x][y]==-1 || grid[x][y]>t ||V[x][y])return false;
	else return true;
}
void bfs(ii from, ii to, int target)
{
	queue<iii> q;
	q.push(iii(0,from));
	memset(V, false, sizeof V);
	int mn=0,cnt=0;
	while(!q.empty())
	{
		iii f=q.front();q.pop();
		int lev=f.first; ii u=f.second;
		V[u.first][u.second]=true;
		if(cnt &&lev==mn)break;
		for(int i=0;i<4;i++)
		{
			int nx=u.first+dr[i],ny=u.second+dc[i];
			if(can(nx,ny,target))
			{
				if(to==ii(nx,ny))
				{
					mn=lev+1;
					cnt++;
				}
				else
				{
					q.push(iii(lev+1,ii(nx,ny)));
				}
			}
		}
		
	}
	paths[to.first][to.second]=(cnt%MOD);
	dist[to.first][to.second]=mn;
}
int main()
{

	char c;
	int K=1,tot,prod,cnt;
	scanf("%d",&n);
	
	while(n)
	{
		memset(dist, 0, sizeof dist);
		memset(paths, 0, sizeof paths);
		cnt=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				scanf(" %c",&c);
				if(c=='#')grid[i][j]=-1;
				else if(c=='.')grid[i][j]=0;
				else 
				{
					grid[i][j]=c-'A'+1;
					pts[c-'A']=ii(i,j);
					cnt++;
				}
			}
		tot=0;
		prod=1;
		dist[pts[0].first][pts[0].second]=1;

		for(int i=0;i<cnt-1;i++)
		{
			bfs(pts[i],pts[i+1],i+2);
			
			prod=(prod*paths[pts[i+1].first][pts[i+1].second])%MOD;
			tot+=dist[pts[i+1].first][pts[i+1].second];
			if(prod==0)break;
		}
		
		printf("Case %d: ",K++);
		if(prod)
		printf("%d %d\n",tot,prod);
		else printf("Impossible\n");
		scanf("%d",&n);
	}

	return 0;
}
