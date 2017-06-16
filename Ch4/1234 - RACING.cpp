#include<bits/stdc++.h>
using namespace std;

long long tot,mx;
vector<bool> taken;
vector<vector<pair<int,int> > > adjList;
priority_queue<pair<int,long long> > pq; 
void process(int s) 
{ 
	taken[s] = true;
	for (pair<int,int> v : adjList[s]) 
	{
		if (!taken[v.first]) pq.push(make_pair(v.second, -v.first));
	}
} 
int main()
{
	int c,V,E,f,t,w;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d%d",&V,&E);
		adjList.clear();
		adjList.resize(V);
		taken.clear();
		taken.resize(V);
		mx = tot = 0;
		for(int i=0;i<E;i++)
		{
			scanf("%d%d%d",&f,&t,&w);
			f--;t--;
			tot+=w;
			adjList[f].push_back(make_pair(t,w));
			adjList[t].push_back(make_pair(f,w));
		}
		process(0); 
		while (!pq.empty())
		{ 
			pair<int,int> front = pq.top(); pq.pop();
			int u = -front.second, w = front.first; 
			if (!taken[u]) 
				mx += w, 
			process(u); 
		}
		printf("%lld\n", tot - mx);
	}
}
