#include<bits/stdc++.h>
using namespace std;
#define MAX 205
#define INF 1e9
vector<vector<int> >adjList;
vector<int> seen;
int V[MAX];
void dfs(int s)
{
	seen[s]=true;
	for(int x:adjList[s])
	{
	
		if(!seen[x])dfs(x);
	}
}
int cur;
int dfs2(int s)
{
	int ans=V[s];
	cur++;
	seen[s]=true;
	for(int x:adjList[s])
	{
		if(!seen[x])ans+=dfs2(x);
	}
	return ans;
}
void remove(int s)
{
	V[s]=2;
	seen[s]=true;
	for(int x:adjList[s])
	{
		if(!seen[x])remove(x);
	}
}
int main()
{
	int m,n,t,k;
	cin>>m;
	while(m--)
	{
		cin>>n;
		adjList.clear();
		adjList.resize(n);
		seen.clear();
		seen.resize(n);
		int f=-1;
		for(int i=0;i<n;i++)
		{
			V[i]=INF;
			int k;
			cin>>k;
			while(k--){
				cin>>t;
				if(t>n)continue;
				t--;
				adjList[i].push_back(t);
				adjList[t].push_back(i);
			}
		}
		vector<int> comp;
		for(int i=0;i<n;i++)
		{
			if(!seen[i])
			{
				comp.push_back(i);
				dfs(i);
			}
		}
		bool isBipartite=true;
		queue<int> q;
		for(int v:comp)
		{
			
			V[v]=0;
			q.push(v);
		}
		vector<int> mark;
		while(!q.empty())
		{	
			int v=q.front();q.pop();
			for(int x:adjList[v])
			{
				if(V[x]==INF)
				{
					V[x]=1-V[v];
					q.push(x);
				}
				else if(V[x]==V[v]){
					mark.push_back(x);
					
					break;
				}
			}
			
		}
		seen.clear();
		seen.resize(n);
		int tot=0;
		for(int v:mark)remove(v);
		seen.clear();
		seen.resize(n);
		for(int v:comp)
		{
			
			if(V[v]==2)continue;
			if(!seen[v])
			{
				cur=0;
				int cnt = dfs2(v);
				tot+=max(cur-cnt,cnt);
			}
		}
		if(!isBipartite)tot=0;
		cout<<tot<<endl;
		
	}
	
}
