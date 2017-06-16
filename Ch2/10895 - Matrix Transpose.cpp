#include <bits/stdc++.h>
using namespace std;
int main() {
	int m,n,v,t;
	char in[85];
	vector<vector<pair<int,int> > > adjList;
	vector<int> y;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		adjList.clear();
		adjList.resize(n);
		for(int r=0;r<m;r++)
		{
			y.clear();
			scanf("%d",&v);
			for(int i=0;i<v;i++)
			{
				scanf("%d",&t);
				y.push_back(t-1);
			}
			for(int i=0;i<v;i++)
			{
				scanf("%d",&t);
				adjList[y[i]].push_back(make_pair(r+1,t));
			}
			
		}
		printf("%d %d\n",n,m);
		for(int r=0;r<n;r++)
		{
			y.clear();
			printf("%d",adjList[r].size());
			for(int i=0;i<adjList[r].size();i++)printf(" %d",adjList[r][i].first);
			printf("\n");
			for(int i=0;i<adjList[r].size();i++)
			{
				printf("%d",adjList[r][i].second);
				if(i!=adjList[r].size()-1)printf(" ");
			}
			printf("\n");
		}
		
	}
	return 0;
}
