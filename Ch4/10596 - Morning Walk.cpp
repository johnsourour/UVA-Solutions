#include<bits/stdc++.h>
using namespace std;
#define MAX 200
int deg[MAX];
bool V[MAX];
vector<vector<int> > adjList;
void dfs(int s)
{

	for(int x:adjList[s])
	{
		if(!V[x])
		{
			V[x]=true;
			dfs(x);}
	}
}
int main()
{
	int N,R,f,t;
	bool possible;
	while(scanf("%d%d",&N,&R)!=EOF)
	{
		for(int i=0;i<N;i++)
		{
			deg[i]=0;
			V[i]=true;
		}
		adjList.clear();
		adjList.resize(N);
		for(int i=0;i<R;i++)
		{
			scanf("%d%d",&f,&t);
			deg[f]++;deg[t]++;
			adjList[f].push_back(t);
			adjList[t].push_back(f);
			V[t]=V[f]=0;
		}
		possible=true;
		int cnt=0;
		for(int i=0;i<N && possible;i++)
		{
			if(!V[i])
			{
				V[i]=true;
				dfs(i);
				cnt++;
				if(cnt>1)
				possible=false;
			}
			if(deg[i]%2==1)possible=false;
		}
		if(!possible ||cnt!=1)printf("Not ");
		printf("Possible\n");
		
	}

	return 0;
}
