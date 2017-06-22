#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int,int> ii;
typedef vector<int> vi;
vector<vector<int> > adjList;
int V;
vi dist, busy;
int distance(int f, int t)
{
	int	s=busy[f],d=busy[t];
	return (d-s)*(d-s)*(d-s);
}
bool BellmanFord(int s)
{
	dist.clear();
	dist.resize(V, INF); 
	dist[s] = 0;
	for (int i = 0; i < V ; i++)
	for (int u = 0; u < V; u++) {
		if(dist[u]==INF)continue;
		for (int e:adjList[u]) {
			int d=distance(u,e);
			if (dist[e] > dist[u] + d)
			{
				if(i==V-1)dist[e]=-INF;
				else	dist[e] = dist[u] + d;
			}
		}
	}
}
int main()
{
	int s,q,r,K=1,x,y;
	while(scanf("%d",&V)==1)
	{
		adjList.clear();
		if(V)adjList.resize(V);
		busy.clear();
		if(V)busy.resize(V);
		for(int i=0;i<V;i++)
		{
			scanf("%d",&busy[i]);
		}
		scanf("%d",&r);
		while(r--)
		{
			scanf("%d%d",&x,&y);x--;y--;
			adjList[x].push_back(y);
			
		}
		scanf("%d",&q);
		printf("Set #%d\n",K++);
		if(V)BellmanFord(0);
		while(q--)
		{
			scanf("%d",&s);
			s--;
		if(s>=V || dist[s]<3 || dist[s]>=INF)printf("?\n");
		else 
		printf("%d\n",dist[s]);
			
		}
		
	}
	return 0;
	
}
