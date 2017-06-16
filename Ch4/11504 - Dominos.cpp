#include<bits/stdc++.h>
using namespace std;

vector<int> ts;
vector<bool> V; 
vector<vector<int> > adjList;
void dfs(int u) 
{
	V[u] = true;
	for (int x:adjList[u]) 
	{
		if (!V[x])
			dfs(x);
	}
	ts.push_back(u);
}
void dfs2(int u) 
{
	V[u] = true;
	for (int x:adjList[u]) 
	{
		if (!V[x])
			dfs(x);
	}
	
}
int main()
{
	int f,t,T,n,m,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		
		adjList.clear();
	ts.clear();
		V.clear();
		adjList.resize(n);
		V.resize(n);
		ans = 0;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&f,&t);
			f--;t--;
			adjList[f].push_back(t);
		
		}
		for (int i = 0; i < n; i++)
			if (!V[i])
				dfs(i);
		V.clear();
		V.resize(n);
		for(int i=n-1;i>=0;i--)
		{
			if (!V[ts[i]])
			{	dfs2(ts[i]);ans++;}
		}
		
		printf("%d\n",ans);
			
					
	}
	return 0;
}
