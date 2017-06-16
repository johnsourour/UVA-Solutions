#include<bits/stdc++.h>
using namespace std;
int price,n;
int C[8][2];
double adjMat[8][8];
double T[8][256];
int  nxt[8][256];
double DP(int i, int mask)
{
	if(mask==(1<<n)-1)return 0.0;	
	if(T[i][mask]!=0.0)return T[i][mask];
	double ans=100000000.0;
	for(int k=0;k<n;k++)
	{
		if(mask & (1<<k))continue; 
		double tmp=adjMat[i][k];
		tmp+=DP(k, mask | (1<<k));
		if(tmp<ans)
		{
			ans=tmp;
			nxt[i][mask]=k;
		}
	}
	T[i][mask]=ans;
	return ans;
	
}
int main()
{
	int NET=1;
	scanf("%d",&n);
	while(n)
	{
		memset(T,0.0,sizeof T);
		
		memset(nxt,-1,sizeof nxt);
		memset(adjMat,100000000.0,sizeof adjMat);
		for(int i=0;i<n;i++)	
			scanf("%d%d",&C[i][0],&C[i][1]);
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
			{
				adjMat[i][j]=adjMat[j][i]=sqrt(pow((C[i][0]-C[j][0]),2)+pow((C[i][1]-C[j][1]),2))+16.0;
			
			}
			double ans=10000000.0,tmp;
			int start;
		for(int i=0;i<n;i++){
			tmp=DP(i,1<<i);
			if(tmp<ans)
			{
				ans=tmp;
				start=i;
				
			}
		}
		printf("**********************************************************\nNetwork #%d\n", NET++);
		int mask=(1<<start);
		for(int i=0;i<n-1;i++)
		{
		
			int next=nxt[start][mask];
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n",C[start][0],C[start][1],C[next][0],C[next][1],adjMat[start][next]);
			start=next;
			mask=mask |(1<<next) ;
			
		}
		printf("Number of feet of cable required is %.2f.\n",ans);
	
		scanf("%d",&n);
	}

	return 0;
}
