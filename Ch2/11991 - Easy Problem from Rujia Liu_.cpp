#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,m,t,tv;
	map<int,vector<int> > adjList; //or use normal adjList with size 1,000,000
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		adjList.clear();
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&t);
			adjList[t-1].push_back(i);
		}
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&tv,&t);
			if(tv<=adjList[t-1].size())printf("%d\n",adjList[t-1][tv-1]);
			else printf("0\n");
		}

		
	}
	return 0;
}
