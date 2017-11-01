#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
#define UNVISITED -1
#define MAX 1002
int V;
vector<vector<int> >adjList;
vector<int> dfs_num, dfs_low, dfs_parent;
vector<bool> articulation_vertex;
bool adjMat[MAX][MAX];
int dfsRoot, dfsNumberCounter, rootChildren;
void articulationPointAndBridge(int u) 
{
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++; 
	for (int v:adjList[u]) 
	{
		if(!adjMat[u][v])continue;
		if (dfs_num[v] == UNVISITED)
		{ 
			dfs_parent[v] = u;
			articulationPointAndBridge(v) ;
			
			if (u == dfsRoot) rootChildren++; // special case if u is a root
			if (dfs_low[v] <= dfs_num[u]) // for bridge
				adjMat[v][u]=false;
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		
		}
		else if (v != dfs_parent[u]) 
		{
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
			adjMat[v][u]=false;
		}
	} 
}
int main()
{
	int E,f,t, K=1;
	while(cin>>V>>E && V)
	{
		adjList.clear();
		adjList.resize(V);
		memset(adjMat, false, sizeof adjMat);
		for(int i=0;i<E;i++)
		{
			cin>>f>>t;f--;t--;
			adjMat[f][t]=adjMat[t][f]=true;
			adjList[f].push_back(t);
			adjList[t].push_back(f);
		}
		dfsNumberCounter = 0;
		dfs_num.assign(V, UNVISITED); 
		dfs_low.assign(V, 0);
		dfs_parent.assign(V, 0); 
		printf("%d\n\n",K++);
		for (int i = 0; i < V; i++)
			if (dfs_num[i] == UNVISITED) {
				dfsRoot = i; rootChildren = 0; 
				articulationPointAndBridge(i);
			}
		for(int i=0;i<V;i++)
			for(int j=0;j<V;j++)
			{
				if(adjMat[i][j])cout<<i+1<<" "<<j+1<<endl;
			}
		printf("#\n");
	}
}
