#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
int adjMat[1000][1000],dist[1000][1000];
int R,C;
bool can(int i,int j)
{
	if(i<0 || i>=R || j<0 || j>=C)return false;
	return true;
}

int dijkstra(ii s, ii e)
{
	
	dist[s.first][s.second] = adjMat[s.first][s.second]; 
	priority_queue< iii, vector<iii>, greater<iii> > pq; pq.push(iii(adjMat[s.first][s.second],s));
	while (!pq.empty())
	{ // main loop
		iii front = pq.top(); pq.pop(); 
		int d = front.first;
		ii u = front.second;
		if (d > dist[u.first][u.second]) continue;
		for (int i=0;i<4;i++) 
		{
			int nx=u.first+dr[i],ny=u.second+dc[i];
			
			if(!can(nx,ny))continue;
			if (dist[u.first][u.second] + adjMat[nx][ny] < dist[nx][ny]) 
			{
				dist[nx][ny] = dist[u.first][u.second] + adjMat[nx][ny] ;
				pq.push(iii(dist[nx][ny],ii(nx,ny)));
			} 
		}
	}
	return dist[e.first][e.second];
}
int main()
{
	int N;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d%d",&R,&C);
		for(int i=0;i<R;i++)
			for(int j=0;j<C;j++){dist[i][j]=INF;scanf("%d",&adjMat[i][j]);}
			
		int ans=dijkstra(ii(0,0),ii(R-1,C-1));
		printf("%d\n",ans);
	}
	return 0;
}
