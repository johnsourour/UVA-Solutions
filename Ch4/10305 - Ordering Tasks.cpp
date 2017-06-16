#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > adjList;
vector<bool> V;
vector<int> ts;
void dfs(int i)
{
	V[i]=true;
	for(int x:adjList[i])
	{
		if(!V[x])dfs(x);
	}
	ts.push_back(i+1);
}
int main()
{
	int m, n,u,v;
	scanf("%d%d",&n,&m);
	while(m||n)
	{
		ts.clear();
		V.clear();
		V.resize(n);
		adjList.clear();
		adjList.resize(n);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&u,&v);
			adjList[u-1].push_back(v-1);
		}
		for(int i=0;i<n;i++)
		{
			if(!V[i])
			dfs(i);
		}
		for(int i=n-1;i>0;i--)printf("%d ",ts[i]);
		printf("%d\n",ts[0]);
		scanf("%d%d",&n,&m);
	}
	
	return 0;	
}
