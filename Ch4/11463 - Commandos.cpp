#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
int adjMat[105][105];
int main()
{
	int T,N,R,s,d,K=1,mn;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&R);
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				{
					if(i!=j)adjMat[i][j]=INF;
					else adjMat[i][j]=0;
				}
				
		while(R--)
		{
			scanf("%d%d",&s,&d);
			adjMat[s][d]=adjMat[d][s]=1;
		}
		scanf("%d%d",&s,&d);
		mn=-1e9;
		for(int k=0;k<N;k++)
			for(int i=0;i<N;i++)
				for(int j=0;j<N;j++)
					adjMat[i][j]=min(adjMat[i][k]+adjMat[k][j],adjMat[i][j]);
				for(int k=0;k<N;k++)mn=max(mn,adjMat[s][k]+adjMat[k][d]);
		printf("Case %d: %d\n",K++,mn);
					
					
	}
	return 0;
	
}
