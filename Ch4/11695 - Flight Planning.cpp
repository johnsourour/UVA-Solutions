#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
vector<vector<int> > adjList,adjList2;
ii centers;
int n;
bool V[2507];
int dist[2507],p[2507];
vector<int> path;
void find(int s)
{
	if(p[s]==-1)path.push_back(s);
	else
	{
		find(p[s]);
		path.push_back(s);
	}
}
int bfs2(int s, int cut)
{
	ii last;
	for(int i=0;i<n;i++)
	{
		V[i]=false;
	}
	queue<ii> q;
	q.push(ii(s,0));
	V[s]=true;
	while(!q.empty())
	{
		ii v=q.front();q.pop();
		int i=v.first;
		for(int x:adjList[i])
		{
			if(!V[x] && ii(x,i)!=ii(s,cut) && ii(i,x)!=ii(s,cut))
			{
				V[x]=true;
				q.push(ii(x,v.second+1));
			}
		}
		last=v;
		
	}
	for(int i=0;i<n;i++)
	{
		V[i]=false;
		dist[i]=p[i]=-1;
	}
	q.push(ii(last.first,0));
	V[last.first]=true;
	while(!q.empty())
	{
		ii v=q.front();q.pop();

		int i=v.first;
		for(int x:adjList[i])
		{
			if(!V[x] && ii(x,i)!=ii(s,cut) && ii(i,x)!=ii(s,cut))
			{
				V[x]=true;
				p[x]=i;
				q.push(ii(x,v.second+1));
				
			}
		}
		last=v;
	}
	path.clear();
	find(last.first);
	return path[path.size()/2];
}
int bfs(int s1, int s2)
{
	ii last;
	queue<ii>q;
	centers=ii(bfs2(s1,s2),bfs2(s2,s1));
	adjList2.clear();
	adjList2=adjList;
	adjList2[centers.first].push_back(centers.second);
	adjList2[centers.second].push_back(centers.first);
	if(s1==centers.first && s2==centers.second)
	{
		return 1e9;
	}
	for(int i=0;i<n;i++)
	{
		V[i]=false;
	}
	q.push(ii(s1,0));V[s1]=true;
	while(!q.empty())
	{
		ii v=q.front();q.pop();
		int i=v.first;
		for(int x:adjList2[i])
		{
			if(!V[x] && ii(x,i)!=ii(s1,s2) && ii(i,x)!=ii(s1,s2))
			{
				V[x]=true;
				q.push(ii(x,v.second+1));
			}
		}
		last=v;
		
	}
	for(int i=0;i<n;i++)
	{
		V[i]=false;
	}	q.push(ii(last.first,0));
	V[last.first]=true;
	while(!q.empty())
	{
		ii v=q.front();q.pop();

		int i=v.first;
		for(int x:adjList2[i])
		{
			if(!V[x] && ii(x,i)!=ii(s1,s2) && ii(i,x)!=ii(s1,s2))
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
	int m,T,f,t,K=1;
	vector<ii> edges;
	bool show;
	scanf("%d",&T);
	ii w,b;
	while(T--)
	{
		show=false;
		scanf("%d",&n);
		adjList.clear();
		edges.clear();
		adjList.resize(n);
		for(int i=0;i<n-1;i++)
		{
			scanf("%d%d",&f,&t);
			f--;t--;
			adjList[t].push_back(f);
			adjList[f].push_back(t);
			edges.push_back(ii(f,t));
		}
		int ans=1e9,cur;
		for(ii e:edges)
		{
			cur=bfs(e.first,e.second);
			if(cur<ans)
			{
				ans=cur;
				w=e;
				b=centers;
			}
		}
		printf("%d\n%d %d\n%d %d\n",ans,w.first+1,w.second+1,b.first+1,b.second+1);
	}
	return 0;
}
