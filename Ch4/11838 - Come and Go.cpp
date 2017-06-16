#include<bits/stdc++.h>
using namespace std;
#define UNVISITED -1
vector<int> dfs_num,dfs_low,S;
vector<bool>V;
vector<vector<int> > adjList;
int dfsNumberCounter, numSCC;
void tarjanSCC(int u)
{
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	V[u]=true;
	S.push_back(u);
	for(int x:adjList[u])
	{
		
		if(dfs_num[x] == UNVISITED)
			tarjanSCC(x);
		
		if(V[x])
			dfs_low[u]=min(dfs_low[x],dfs_low[u]);
	}
	if(dfs_low[u]==dfs_num[u])
	{
		numSCC++;
		while (1) 
		{
			int v = S.back(); S.pop_back(); V[v] = false;
			if (u == v) break; 
		}
	}
}
int main()
{
	int N,M,f,t,p;
	scanf("%d%d",&N,&M);
	while(N||M)
	{
		dfsNumberCounter = numSCC = 0;
		adjList.clear();
		S.clear();
		dfs_num.clear();
		dfs_low.clear();
		V.clear();
		adjList.resize(N);
		dfs_num.resize(N, UNVISITED);
		dfs_low.resize(N);
		V.resize(N);
		for(int i=0;i<M;i++)
		{
			scanf("%d%d%d",&f,&t,&p);
			f--;t--;
			adjList[f].push_back(t);
			if(p==2)adjList[t].push_back(f);
		
		}
		
		for (int i = 0; i < N; i++)
			if (dfs_num[i]==UNVISITED)
			tarjanSCC(i);
	
	
	
		printf("%d\n",numSCC==1?1:0);
		scanf("%d%d",&N,&M);	
					
	}
	return 0;
}
