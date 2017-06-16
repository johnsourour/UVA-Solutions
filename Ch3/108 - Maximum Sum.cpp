#include<bits/stdc++.h>
using namespace std;
int main()
{	
	int N,mx,cur;
	int M[105][105];
	while(scanf("%d",&N)!=EOF)
	{
		mx=0;
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
			{
				scanf("%d",&M[i][j]);
				mx+=M[i][j];
				if(j > 0) M[i][j] += M[i][j - 1];
			}
			for(int l=0;l<N;l++)
				for(int r=l;r<N;r++)
				{
					cur=0;
					for(int x=0;x<N;x++)
						{
							if(l > 0) cur+=M[x][r] - M[x][l-1];
							else cur+=M[x][r];
							if(cur<0) cur=0;
							mx=max(cur,mx);					
						}
				}
			printf("%d\n",mx);
			
	}
	return 0;
}
