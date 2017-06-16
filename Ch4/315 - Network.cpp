#include<bits/stdc++.h>
using namespace std;
#define UNVISITED -1
vector<vector<int> > adjList;
vector<int> dfs_num, dfs_low, dfs_parent;
vector<bool> articulation_vertex;
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
			articulation_vertex[u] = true;
			dfs_low[u] = min(dfs_low[u], dfs_low[x]);
		}
		else if (x != dfs_parent[u]) 
			dfs_low[u] = min(dfs_low[u], dfs_num[x]);
	} 
}
int main()
{
	int N,ans;
	string s,ss;
	scanf("%d",&N);
	while(N)
	{
		
		dfs_num.clear(); 
		dfs_low.clear(); 
		dfs_parent.clear(); 
		articulation_vertex.clear(); 
		adjList.clear();
		adjList.resize(N);
		dfs_num.resize(N, UNVISITED); 
		dfs_low.resize(N, 0);
		dfs_parent.resize(N, 0); 
		articulation_vertex.resize(N, false);
		ans=0;
		getline(cin, s);
	
		int i=0;
		while(i<N)
		{
			getline(cin, s);
			if(s.at(0)=='0')break;
			int t,f;
			ss="";
			while(s.at(0)!=' '){ss+=s.at(0);s.erase(0,1);}
			f=stoi(ss);
			
			f--;
			s.erase(0,1);
			while(s.length()>0)
			{
				ss="";
				while(s.length()> 0 && s.at(0)!=' '){ss+=s.at(0);s.erase(0,1);}
				t=stoi(ss);
				t--;
				s.erase(0,1);
				adjList[t].push_back(f);
				adjList[f].push_back(t);
				
			}
			i++;
		}
		if(i==N)getline(cin, s);
		dfsNumberCounter = 0;
	
		for (int i = 0; i < N; i++)
			if (dfs_num[i] == UNVISITED) {
				dfsRoot = i; rootChildren = 0; 
				articulationPoint(i);
				articulation_vertex[dfsRoot] = (rootChildren > 1); 
			} 
	

		for (int i = 0; i < N; i++)
			if (articulation_vertex[i])
				ans++;
		
		printf("%d\n",ans);
		scanf("%d",&N);
	}
}
