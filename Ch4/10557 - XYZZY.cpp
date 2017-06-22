#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define val 100
typedef pair<int,int> ii;
typedef vector<int> vi;
vector<vector<ii> > adjList;
int V;
vi dist;
vector<bool> seen;
bool canReach(int s)
{
	if(s==V-1)return true;
	if(seen[s])return false;
	seen[s]=true;
	for(ii a:adjList[s])
	{
		if(canReach(a.first))return true;
	}
	return false;
}
bool BellmanFord(int s)
{
	dist.clear();
	dist.resize(V, INF); 
	dist[s] = 0;
	for (int i = 0; i < V ; i++)
	for (int u = 0; u < V; u++) {
		for (ii e:adjList[u]) {
			if (dist[e.first] > dist[u] + e.second && dist[u] + e.second <val)
			{
				if(i!=V-1)dist[e.first] = dist[u] + e.second;
				else
				{
					seen.clear();
					seen.resize(V);
					return canReach(e.first);
				}
			}
		}
	}
	return dist[V-1]<val ;
}
int main()
{
	int e,n,t;
	scanf("%d",&V);
	while(V!=-1)
	{
		adjList.clear();
		if(V)adjList.resize(V);
		for(int i=0;i<V;i++)
		{
			
			scanf("%d%d",&e,&n);
			while(n--)
			{
				scanf("%d",&t);t--;
			adjList[i].push_back(ii(t,-e));
			
			}
			
		}
		bool flag=true;
		if(V)flag=BellmanFord(0);
		if(flag)printf("winnable\n");
		else printf("hopeless\n");
		
		scanf("%d",&V);
		
	}
	return 0;
	
}
