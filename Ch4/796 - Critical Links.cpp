#include<bits/stdc++.h>
using namespace std;
#define UNVISITED -1
vector<vector<int> > adjList;
vector<int> dfs_num, dfs_low, dfs_parent;
vector<pair<int,int> > bridges;
int dfsRoot, dfsNumberCounter, rootChildren;
void Bridges(int u) 
{
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	for (int x:adjList[u]) 
	{
		if (dfs_num[x] == UNVISITED)
		{
			dfs_parent[x] = u;
			if (u == dfsRoot) rootChildren++; 
				Bridges(x);
			if (dfs_low[x] > dfs_num[u])
				bridges.push_back(make_pair(min(u,x),max(u,x)));
			dfs_low[u] = min(dfs_low[u], dfs_low[x]);
		}
		else if (x != dfs_parent[u]) 
			dfs_low[u] = min(dfs_low[u], dfs_num[x]);
	} 
}
int main()
{
	int N,S;
	
	while(scanf("%d",&N)!=EOF)
	{
		
		dfs_num.clear(); 
		dfs_low.clear(); 
		dfs_parent.clear(); 
		bridges.clear(); 
		adjList.clear();
		adjList.resize(N);
		dfs_num.resize(N, UNVISITED); 
		dfs_low.resize(N, 0);
		dfs_parent.resize(N, 0); 
		int f,t;
		for(int i=0;i<N;i++)
		{
			scanf("%d (%d)",&f,&S);
			while(S--)
			{
				scanf("%d",&t);
				adjList[t].push_back(f);
				adjList[f].push_back(t);
			}
		}
		dfsNumberCounter = 0;
	
		for (int i = 0; i < N; i++)
			if (dfs_num[i] == UNVISITED) {
				dfsRoot = i; rootChildren = 0; 
				Bridges(i);
			} 
	
		sort(bridges.begin(),bridges.end());
		printf("%d critical links\n",bridges.size());
		for(pair<int,int> ii:bridges)printf("%d - %d\n",ii.first,ii.second);
		printf("\n");
	}
}
