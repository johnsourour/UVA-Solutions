#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
vector<int> dist;
int T[605][300],n;
int camp(int pos, int n_left)
{
	if(pos>=n)return 0;
	if(n_left==0)
	{
		int tot=0;
		for(int i=pos;i<n;i++)tot+=dist[i];
		return tot;
	}
	if(T[pos][n_left]==-1)
	{
		int ans=INF,walk=dist[pos];
		for(int i=pos+1;i<n;i++)
		{
			ans=min(ans,max(walk,camp(i,n_left-1)));
			walk+=dist[i];
		}
		T[pos][n_left]=ans;
	}
	return T[pos][n_left];
}
int main()
{
	int K,cnt=0;
	while(scanf("%d%d",&n,&K)!=EOF)
	{
		memset(T,-1,sizeof T);
			n++;
		dist.clear();
		dist.resize(n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&dist[i]);
		}
	
		printf("%d\n",camp(0,K));
	}

	return 0;
}
