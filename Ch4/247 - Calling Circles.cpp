#include<bits/stdc++.h>
using namespace std;
#define UNVISITED -1
vector<int> dfs_num, dfs_low, S;
vector<bool> V; 
vector<string> customers;
map<string,int> custMap;
vector<vector<int> > adjList;
int dfsNumberCounter;
void tarjanSCC(int u) 
{
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	S.push_back(u); 
	V[u] = true;
	for (int x:adjList[u]) 
	{
		if (dfs_num[x] == UNVISITED)
			tarjanSCC(x);
		if (V[x])
			dfs_low[u] = min(dfs_low[u], dfs_low[x]); 
	}
	if (dfs_low[u] == dfs_num[u])
	{ 
			while (1) 
			{
				int v = S.back(); S.pop_back(); V[v] = false;
				printf("%s", customers[v].c_str());
				if (u == v) break; 
				else printf(", ");
			}
			printf("\n");
	}
}
int main()
{
	int n,m,f,t,cnt,K=1;
	string c1,c2;
	scanf("%d%d",&n,&m);
	while(n||m)
	{
		S.clear();
		customers.clear();
		custMap.clear();
		adjList.clear();
		dfs_num.clear();
		dfs_low.clear();
		V.clear();
		adjList.resize(n);
		dfs_num.resize(n, UNVISITED); 
		dfs_low.resize(n); 
		V.resize(n);
		dfsNumberCounter = cnt = 0;
		for(int i=0;i<m;i++)
		{
			cin>>c1>>c2;
			if(custMap.find(c1)==custMap.end())
			{
				custMap.insert(make_pair(c1,cnt));
				customers.push_back(c1);
				f=cnt;
				cnt++;
			}
			else f=custMap[c1];
			if(custMap.find(c2)==custMap.end())
			{
				custMap.insert(make_pair(c2,cnt));
				customers.push_back(c2);
				t=cnt;
				cnt++;
			}
			else t=custMap[c2];
			adjList[f].push_back(t);
			
		}
		if(K>1)printf("\n");
		printf("Calling circles for data set %d:\n",K++);
		
		for (int i = 0; i < n; i++)
		  if (dfs_num[i] == UNVISITED)
				tarjanSCC(i);	
			
		scanf("%d%d",&n,&m);		
	}
	return 0;
}
