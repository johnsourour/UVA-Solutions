#include<bits/stdc++.h>
using namespace std;

int main()
{	
	int A[105][105],N,M,K,T,mxCost,mxArea,cur,area,C=1;
	scanf("%d",&T);
	while(T--)
	{
		mxCost=mxArea=0;
		scanf("%d%d%d",&N,&M,&K);
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
			{
				scanf("%d",&A[i][j]);
				if(i > 0)A[i][j]+=A[i-1][j];
				if(j > 0)A[i][j]+=A[i][j-1];
				if(i > 0 && j > 0)A[i][j]-=A[i-1][j-1];
			}
			for(int i=0;i<N;i++)
				for(int j=0;j<M;j++)
					for(int x=i;x<N;x++)
						for(int y=j;y<M;y++)
						{
							cur=A[x][y];
							if(i > 0) cur -= A[i - 1][y];
							if(j > 0) cur -= A[x][j - 1];
							if(i > 0 && j > 0) cur+= A[i - 1][j - 1];
							area=(x-i+1)*(y-j+1);
							if(area>mxArea && cur<=K){mxCost=cur;mxArea=area;}
							if(area>=mxArea && cur<=K){mxCost=min(mxCost,cur);mxArea=area;}
							
						}
			printf("Case #%d: %d %d\n",C++,mxArea,mxCost);
			
			
	}
	return 0;
}
