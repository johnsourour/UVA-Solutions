#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef vector<int> vi;
typedef pair<int,int> ii;
vector<vector<pair<int,int> > > adjList;
int V;
int dijkstra(int s, int e)
{
	vi dist(V, INF); dist[s] = 0; 
	priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s));
	while (!pq.empty())
	{ // main loop
		ii front = pq.top(); pq.pop(); 
		int d = front.first, u = front.second;
		if (d > dist[u]) continue;
		for (ii v:adjList[u]) 
		{
			if (dist[u] + v.second < dist[v.first]) 
			{
				dist[v.first] = dist[u] + v.second;
				pq.push(ii(dist[v.first], v.first));
			} 
		}
	}
	return dist[e];
}
int main()
{
	int N,S,T,E,f,t,w,K=1;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d%d%d%d",&V,&E,&S,&T);
		adjList.clear();
		adjList.resize(V);
		while(E--)
		{
			scanf("%d%d%d",&f,&t,&w);
			adjList[f].push_back(ii(t,w));
			adjList[t].push_back(ii(f,w));
		}
		printf("Case #%d: ",K++);
		int ans=dijkstra(S,T);
		if(ans==INF)printf("unreachable\n");
		else printf("%d\n",ans);
	}
	return 0;
}
