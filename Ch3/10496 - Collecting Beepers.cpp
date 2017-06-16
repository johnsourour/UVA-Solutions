#include<bits/stdc++.h>
using namespace std;
int X[11],Y[11],n,m,b,adjMat[11][11];
int T[11][1<<11];
int DP(int pos, int mask)
{
	if(mask == (1<<b)-1)return adjMat[pos][0];
	if(T[pos][mask]!=-1)return T[pos][mask];
	int ans=1e9;
	for(int i=1;i<b;i++)
	{
		if(mask & (1<<i))continue;
		ans=min(ans, adjMat[pos][i]+DP(i,mask | (1<<i)));
	}
	T[pos][mask]=ans;
	return T[pos][mask];
		
}
int main()
{
	int S;
	scanf("%d",&S);
	while(S--)
	{
		memset(T,-1,sizeof T);
		memset(adjMat,1e9,sizeof adjMat);
		scanf("%d%d",&n,&m);
		scanf("%d%d",&X[0],&Y[0]);
		scanf("%d",&b);
		b++;
		for(int i=1;i<b;i++)
			scanf("%d%d",&X[i],&Y[i]);
	
		for(int i=0;i<b;i++)
			for(int j=i+1;j<b;j++)
				adjMat[i][j]=adjMat[j][i]=abs(X[i]-X[j])+abs(Y[i]-Y[j]);
				
		printf("The shortest path has length %d\n",DP(0,1));
			
	}
	return 0;
}
