#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T,e,v,c1,c2,f,t,extra,ans;
	vector<int> color;
	vector<vector<int> > adjList;
	scanf("%d",&T);
	while(T--)
	{	
		scanf("%d%d",&v,&e);
		extra=ans=0;
		adjList.clear();
		adjList.resize(v);
		color.clear();
		color.resize(v,-1);
		vector<pair<int,int> >ft;
		for(int i=0;i<e;i++)
		{
			scanf("%d%d",&f,&t);
			adjList[f].push_back(t);
			adjList[t].push_back(f);
		
			
		}
  	bool flag=true;
		for(int i=0;i<v;i++)
		{
			if(color[i]!=-1)continue;
			if(adjList[i].size()==0){extra++;continue;}
			queue<int> q;
			c1=c2=0;
			q.push(i);
			color[i]=0;
			c1++;
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
						if(color[x])c2++;
						else c1++;
						q.push(x);
					}
				}
				
			}
			ans+=(c1&&c2?min(c1,c2):max(c1,c2));
		}
	
		if(flag)printf("%d\n",ans+extra);
		else printf("-1\n");
	}
	return 0;	
}
