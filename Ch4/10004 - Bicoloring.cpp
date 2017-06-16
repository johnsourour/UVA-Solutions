#include<bits/stdc++.h>
using namespace std;
int main()
{

	int n,l,u,v;
	vector<vector<int> > adjList;
	vector<int> color;
	scanf("%d",&n);
	while(n)
	{	
		adjList.clear();
		adjList.resize(n);
		color.clear();
		color.resize(n,-1);
		scanf("%d",&l);
		for(int i=0;i<l;i++)
		{
			scanf("%d%d",&u,&v);
			adjList[u].push_back(v);
			adjList[v].push_back(u);
		}
		queue<int> q;
		q.push(0);
		color[0]=0;
		bool flag=true;
		while(!q.empty() && flag)
		{
			int u=q.front();q.pop();
			for(int x:adjList[u])
			{
				if(color[x]==color[u]){
					flag=false;
					break;
				}
				else if(color[x]==-1)
				{
					color[x]=1-color[u];
					q.push(x);
				}
			}
		}
		if(flag)printf("BICOLORABLE.\n");
		else printf("NOT BICOLORABLE.\n");
		scanf("%d",&n);
	}
	return 0;	
}
