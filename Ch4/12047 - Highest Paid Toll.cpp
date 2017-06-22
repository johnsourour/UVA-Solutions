#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef pair<int,ii> iii;
int p,mx;
vector<vector<ii> > adjList;
vector<vector<ii> > radjList;
vi rdist,dist;
void dijkstra(int s, int e, int t)
{
	 
	priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s));
	while (!pq.empty())
	{ 
		ii front = pq.top(); pq.pop(); 
		int d = front.first, u = front.second;
		
		if(t==0){
			if (d > dist[u]) continue;
			
			for (ii v:adjList[u]) 
			{
				if (dist[u] + v.second < dist[v.first]) 
				{
					dist[v.first] = dist[u] + v.second;
					pq.push(ii(dist[v.first],v.first));
				} 
			}
		}
		else
		{
			if (d > rdist[u]) continue;	
			for (ii v:radjList[u]) 
			{
				if (rdist[u] + v.second < rdist[v.first]) 
				{
					rdist[v.first] = rdist[u] + v.second;
					pq.push(ii(rdist[v.first],v.first));
				} 
			}
		}
	}
}
int main()
{
	int T,N,M,s,t,x,y,w;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d%d",&N,&M,&s,&t,&p);
		adjList.clear();
		adjList.resize(N);
		radjList.clear();
		radjList.resize(N);
		int ans=-1;
		for(int i=0;i<M;i++)
		{
			scanf("%d%d%d",&x,&y,&w);
			x--;y--;
			adjList[x].push_back(ii(y,w));
			radjList[y].push_back(ii(x,w));
		}
		s--;t--;
		dist.clear(); dist.resize(adjList.size(), INF); dist[s] = 0;
		rdist.clear(); rdist.resize(adjList.size(), INF); rdist[t] = 0;
		dijkstra(s,t,0);
		dijkstra(t,s,1);
		for(int i=0;i<N;i++)
		{
			for(ii a:adjList[i])
			if(dist[i]+rdist[a.first]+a.second<=p)ans=max(ans,a.second);
			for(ii a:radjList[i])
			if(dist[a.first]+rdist[i]+a.second<=p)ans=max(ans,a.second);
		}
		if(ans<INF)printf("%d\n",ans);
		else printf("-1\n");
		
		
	}
	return 0;
}
