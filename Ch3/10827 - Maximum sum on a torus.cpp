#include<bits/stdc++.h>
using namespace std;

int main()
{	
	int M[160][160],N,T,mx,cur;
	scanf("%d",&T);
	while(T--)
	{
		mx=-1e9;
		scanf("%d",&N);
		for(int i=0;i<N*2;i++)
			for(int j=0;j<N*2;j++)
			{
				scanf("%d",&M[i][j]);
				M[i][j+N]=M[i+N][j]=M[i+N][j+N]=M[i][j];
				
				
			}
			for(int i=0;i<N*2;i++)
			for(int j=0;j<N*2;j++)
			{
					if(i > 0)M[i][j]+=M[i-1][j];
					if(j > 0)M[i][j]+=M[i][j-1];
					if(i > 0 && j > 0)M[i][j]-=M[i-1][j-1];
			}
		
			for(int i=0;i<N*2;i++)
				for(int j=0;j<N*2;j++)
					for(int x=i;x<min(N+i,2*N);x++)
						for(int y=j;y<min(N+j,2*N);y++)
						{
							cur=M[x][y];
							if(i > 0) cur -= M[i - 1][y];
							if(j > 0) cur -= M[x][j - 1];
							if(i > 0 && j > 0) cur+= M[i - 1][j - 1];
							mx=max(cur,mx);
							
						}
			printf("%d\n",mx);
			
	}
	return 0;
}
