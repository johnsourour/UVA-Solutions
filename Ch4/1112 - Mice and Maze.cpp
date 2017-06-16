#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef vector<int> vi;
typedef pair<int,int> ii;
vector<vector<pair<int,int> > > adjList;
int V;
int dijkstra(int s,int t)
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
	int ans=0;
	for(int i=0;i<V;i++)if(dist[i]<=t)ans++;
	return ans;
}
int main()
{
	int N,M,T,E,f,t,w;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d%d%d%d",&V,&E,&T,&M);
		adjList.clear();
		adjList.resize(V);
		while(M--)
		{
			scanf("%d%d%d",&f,&t,&w);
			adjList[t-1].push_back(ii(f-1,w));
		}
		printf("%d\n",dijkstra(E-1,T));
		if(N)printf("\n");
	}
	return 0;
}
