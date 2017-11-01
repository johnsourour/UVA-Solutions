#include<bits/stdc++.h>
using namespace std;
vector<vector<int> >adjList;
vector<int> ts;
vector<bool> V;
void dfs(int s, bool t)
{
	V[s]=true;
	for(int x:adjList[s])
	{
		if(!V[x])dfs(x,t);
	}
	if(t)ts.push_back(s);
}

int main()
{
	int n,m,T,K=1,f,t;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		adjList.clear();
		adjList.resize(n);
		for(int i=0;i<m;i++)
		{
			cin>>f>>t;f--;t--;
			adjList[f].push_back(t);
		}
		int comp = 0;
		V.assign(n, 0);
		ts.clear();
		for (int i = 0; i < n; i++)
			if (!V[i]) 
			{
				dfs(i,1);
			}
		reverse(ts.begin(),ts.end());
		V.assign(n, 0);
		for(int i:ts)
		{	
			if (!V[i]) 
			{
				comp++;
				dfs(i,0);
			}
			
		}
		printf("Case %d: %d\n",K++,comp);
	
	}
}
