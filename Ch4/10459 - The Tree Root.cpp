#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
vector<vector<int> > adjList;
int dist[50005],nxt,mx;
int dfs(int i, int len, int prev)
{
	dist[i]=max(dist[i],len);
	if(dist[i]>mx)
	{
		mx=dist[i];
		nxt=i;
	}
	for(int x:adjList[i])
	{
		if(x!=prev)dfs(x,len+1,i);
	}

}
int main()
{

	int n,m,t;
	vector<int>best,worst;
	while(scanf("%d",&n)!=EOF)
	{
		best.clear();
		worst.clear();
		adjList.clear();
		adjList.resize(n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&m);
			while(m--)
			{
				scanf("%d",&t);t--;
				adjList[i].push_back(t);
			}
		}
		for(int j=0;j<n;j++)
		{
			dist[j]=0;
		}
		nxt=mx=0;
		dfs(nxt,1,-1);
		dfs(nxt,1,-1);
		dfs(nxt,1,-1);
		int mn=1e9;
		for(int i=0;i<n;i++)
		{
			if(dist[i]==mx)worst.push_back(i+1);
			else{
				if(dist[i]<=mn)
				{
					if(dist[i]<mn)
					{
						best.clear();
						mn=dist[i];
					}
					best.push_back(i+1);
				}
			}
		}
		printf("Best Roots  :");for(int x:best)printf(" %d",x);printf("\n");
		printf("Worst Roots :");for(int x:worst)printf(" %d",x);printf("\n");

		
	}

	return 0;
}
