#include<bits/stdc++.h>
using namespace std;
int adjMat[105][105];
#define INF 1e9
int main()
{
	int x,y,K=1,mx;
	double tot,cnt;
	scanf("%d%d",&x,&y);
	while(x||y)
	{
		tot=cnt=0;
		mx=0;
		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)adjMat[i][j]=INF;
		while(x||y)
		{
			adjMat[x-1][y-1]=1;
			mx=max(mx,max(x,y));
			scanf("%d%d",&x,&y);
		}
		for (int k = 0; k < mx; k++) 
			for (int i = 0; i < mx; i++)
				for (int j = 0; j < mx; j++)
					adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]); 
		for (int i = 0; i < mx; i++)
			for (int j = 0; j < mx; j++)
					if(i!=j && adjMat[i][j]!=INF){
						tot+=adjMat[i][j]; 
						cnt++;
					}
		printf("Case %d: average length between pages = %.3f clicks\n",K++,tot/cnt);
		scanf("%d%d",&x,&y);
	}
	return 0;
	
}
