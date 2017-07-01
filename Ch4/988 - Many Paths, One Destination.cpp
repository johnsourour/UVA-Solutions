#include<bits/stdc++.h>
using namespace std;

vector<int> dist,inDeg,death;
vector<vector<int> > adjList;
int main()
{
	int n,m,t,k=0;
	while(scanf("%d",&n)!=EOF)
	{
		if(k)printf("\n");
		k++;
		dist.clear();
		dist.resize(n);
		adjList.clear();
		adjList.resize(n);
		inDeg.clear();
		death.clear();
		inDeg.resize(n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&m);
			if(!m)death.push_back(i);
			while(m--)
			{
				scanf("%d",&t);
				adjList[i].push_back(t);
				inDeg[t]++;
			}
			
		}
		priority_queue<int> Q;
		dist[0]=1;
		for(int i=0;i<n;i++)if(!inDeg[i])Q.push(i);
		while(!Q.empty())
		{
			//for(int i=0;i<n;i++)cout<<dist[i]<<" ";
			//cout<<endl;
			int u=Q.top();Q.pop();
			
			for(int v:adjList[u])
			{
				dist[v]+=dist[u];
				if(--inDeg[v]==0)
				{
					Q.push(v);
				}
			}
		}
		int ans=0;
		for(int k:death)ans+=dist[k];
		printf("%d\n",ans);
		
		
	}
	
	return 0;
}
