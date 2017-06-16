#include<bits/stdc++.h>
using namespace std;



int main()
{
	int v,f,t;
	vector<int> color;
	vector<vector<int> > adjList;
	scanf("%d",&v);
	while(v)
	{	
		adjList.clear();
		adjList.resize(v);
		color.clear();
		color.resize(v,-1);
		scanf("%d%d",&f,&t);
		while(f||t){
			f--;t--;
			adjList[f].push_back(t);
			adjList[t].push_back(f);
		scanf("%d%d",&f,&t);
		}
		bool flag=true;
		queue<int> q;
		q.push(0);
		color[0]=0;
		while(!q.empty() && flag)
		{
			int u=q.front();q.pop();
			for(int x:adjList[u])
			{
				if(color[x]==color[u])
				{
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
		if(!flag)printf("NO\n");
		else printf("YES\n");
		scanf("%d",&v);
	}
	return 0;	
}
