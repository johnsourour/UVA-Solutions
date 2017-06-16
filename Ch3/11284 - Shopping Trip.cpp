#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
int N,M,P;
double adjMat[51][51],T[13][1<<13];
pair<int,double> S[13];

double DP(int pos, int mask)
{
	if(mask==(1<<P)-1)return -adjMat[0][S[pos].first];
	if(T[pos][mask]!=-1)return T[pos][mask];
	
	double ans=-adjMat[0][S[pos].first];

	for(int i=0;i<P;i++)
	{
		if(mask & (1<<i))continue;
		ans=max(ans,S[i].second-adjMat[S[i].first][S[pos].first]+DP(i,mask|(1<<i)));
	}
	T[pos][mask]=ans;
	return T[pos][mask];
}

int main()
{
	int x,y,K;
	double tmp;
	scanf("%d",&K);
	while(K--)
	{
		scanf("%d%d",&N,&M);
		N++;
		fill(&T[0][0], &T[13][0], -1);
		fill(&adjMat[0][0], &adjMat[51][0], INF);

		for(int i=0;i<M;i++)
		{
			scanf("%d%d%lf",&x,&y,&tmp);
			tmp=min(tmp,adjMat[x][y]);
			adjMat[x][y]=adjMat[y][x]=tmp;
			
		}
		for(int k = 0; k < N; k++)adjMat[k][k]=0;
		for(int k = 0; k < N; k++)
    		for(int i = 0; i < N; i++)
    			for(int j = 0; j < N; j++)
    				adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
		scanf("%d",&P);
		P++;
		S[0]=make_pair(0,0);
		for(int i=1;i<P;i++)
		{
			scanf("%d%lf",&x,&tmp);
			S[i]=make_pair(x,tmp);
		}
		double ans=DP(0,1);
		if(ans>0.009)
			printf("Daniel can save $%.2f\n", ans);
       		else
            		printf("Don't leave the house\n");
	}
	return 0;
}
