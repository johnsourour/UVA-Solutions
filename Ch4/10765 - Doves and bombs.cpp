#include<bits/stdc++.h>
using namespace std;
#define UNVISITED -1
struct comp
{
	bool operator()(const pair<int,int> &a, const pair<int,int> &b)
	{
		if(a.second==b.second)return a.first<b.first;
		else return a.second>b.second;
	}
};
vector<pair<int,int> >ans;
vector<vector<int> > adjList;
vector<int> dfs_num, dfs_low, dfs_parent, articulation_vertex;
int dfsRoot, dfsNumberCounter, rootChildren;
void articulationPoint(int u) 
{
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	for (int x:adjList[u]) 
	{
		if (dfs_num[x] == UNVISITED)
		{
			dfs_parent[x] = u;
			if (u == dfsRoot) rootChildren++; 
				articulationPoint(x);
			if (dfs_low[x] >= dfs_num[u])
			articulation_vertex[u]++;
			dfs_low[u] = min(dfs_low[u], dfs_low[x]);
		}
		else if (x != dfs_parent[u]) 
			dfs_low[u] = min(dfs_low[u], dfs_num[x]);
	} 
}
int main()
{
	int N,f,t,M;
	scanf("%d%d",&N,&M);
	while(N || M)
	{
		
		dfs_num.clear(); 
		dfs_low.clear(); 
		dfs_parent.clear(); 
		articulation_vertex.clear(); 
		adjList.clear();
		adjList.resize(N);
		dfs_num.resize(N, UNVISITED); 
		dfs_low.resize(N);
		dfs_parent.resize(N); 
		articulation_vertex.resize(N);
		ans.clear();
		scanf("%d%d",&f,&t);
		while(f!=-1 && t!=-1)
		{
			adjList[t].push_back(f);
			adjList[f].push_back(t);
			scanf("%d%d",&f,&t);
		}
		dfsNumberCounter = 0;
	
		for (int i = 0; i < N; i++)
			if (dfs_num[i] == UNVISITED) {
				dfsRoot = i; rootChildren = 0; 
				articulationPoint(i);
				articulation_vertex[dfsRoot] = (rootChildren>1); 
				
			} 
	for(int i=0;i<N;i++)
	{
		articulation_vertex[i]++;
		ans.push_back(make_pair(i,articulation_vertex[i]));
	}
	sort(ans.begin(),ans.end(),comp());
	for(int i=0;i<M;i++)printf("%d %d\n",ans[i].first,ans[i].second);
	printf("\n");	
			scanf("%d%d",&N,&M);
	}
}
