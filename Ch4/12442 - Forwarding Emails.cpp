#include<bits/stdc++.h>
using namespace std;
int adjList[50002];
int mem[50002];
bool V[50002];
int dfs(int x)
{
	int cnt=1;
	V[x]=true;

	if(adjList[x]==-1)cnt=1;
	else if(!V[adjList[x]])cnt+=dfs(adjList[x]);
mem[x]=cnt;
	V[x]=false;
	return cnt;

}
int main()
{	
	int mx,ans,T,N,u,v,K=1; scanf("%d",&T);
	while(T--)
	{
		memset(mem, -1, sizeof mem);
		memset(adjList, -1, sizeof adjList);
		scanf("%d",&N);
		for(int i=0;i<N;i++)
		{
			scanf("%d%d",&u,&v);
			adjList[u-1]=v-1;
		}
		mx=0;
		for(int i=0;i<N;i++)
		{
			int res;
			if(mem[i]!=-1)res=mem[i];
		 	else res=dfs(i);
			if(res>mx){
				mx=res;
				ans=i;
			}
		}
		printf("Case %d: %d\n",K++,ans+1);
	}
	return 0;
}
