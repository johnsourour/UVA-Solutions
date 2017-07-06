#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
vector<vector<int> > adjList,adjList2;
bool V[27];
int bfs(int s, int s2)
{
	ii last;
	memset(V, false, sizeof V);
	queue<ii> q;
	adjList2.clear();
	adjList2.resize(adjList.size());
	
	q.push(ii(s,0));
	V[s]=true;
	if(s2!=-1)
	{
		q.push(ii(s2,0));
		V[s2]=true;
		adjList2[s].push_back(s2);
		adjList2[s2].push_back(s);
	}
	while(!q.empty())
	{
		ii v=q.front();q.pop();
		int i=v.first;
		for(int x:adjList[i])
		{
			if(!V[x])
			{
				V[x]=true;
				q.push(ii(x,v.second+1));
				adjList2[x].push_back(i);
				adjList2[i].push_back(x);
			}
		}
		last=v;
		
	}
	memset(V, false, sizeof V);
	q.push(ii(last.first,0));
	V[last.first]=true;
	while(!q.empty())
	{
		ii v=q.front();q.pop();

		int i=v.first;
		for(int x:adjList2[i])
		{
			if(!V[x])
			{
				V[x]=true;
				q.push(ii(x,v.second+1));
				
			}
		}
		last=v;
	}
	return last.second;
}
int main()
{

	int n,m,T,f,t,K=1;
	scanf("%d",&T);
	vector<ii> edges;
	while(T--)
	{
		scanf("%d%d",&n,&m);
		adjList.clear();
		adjList.resize(n);
		edges.clear();
		while(m--)
		{
			scanf("%d%d",&f,&t);
			adjList[t].push_back(f);
			adjList[f].push_back(t);
			edges.push_back(ii(f,t));
		}
		int ans=1e9;
		for(int i=0;i<n;i++)
		{
			ans=min(ans,bfs(i,-1));
		}
		for(ii e:edges)
		{
			ans=min(ans,bfs(e.first,e.second));
		}
		printf("Case #%d:\n%d\n\n",K++,ans);

		
	}

	return 0;
}
