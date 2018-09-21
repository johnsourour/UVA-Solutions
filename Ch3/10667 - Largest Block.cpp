#include<bits/stdc++.h>
using namespace std;
#define MAX 105
int grid[MAX][MAX];
int main()
{
	int s,b,t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&s,&b);
		for(int i=1;i<=s;i++)
			for(int j=1;j<=s;j++)grid[i][j]=1;
		int r1,r2,c1,c2;
		while(b--){
			scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
			
			for(int i=r1;i<=r2;i++)
			for(int j=c1;j<=c2;j++)grid[i][j]=0;
			
		}
		for(int i=1;i<=s;i++)
			for(int j=1;j<=s;j++)
			{
				if(i > 1) grid[i][j] += grid[i - 1][j];
				if(j > 1) grid[i][j] += grid[i][j - 1];
				if(i > 1 && j > 1) grid[i][j] -= grid[i - 1][j - 1];
			}
		int cur,len,wid,mx=0;

		for(int i=1;i<=s;i++)
			for(int j=1;j<=s;j++)
			{
				for(int x=i;x<=s;x++)
					for(int y=j;y<=s;y++)
					{
						len = y-j+1, wid = x-i+1;
						cur=grid[x][y];
						if(i > 1) cur -= grid[i - 1][y];
						if(j > 1) cur -= grid[x][j - 1];
						if(i > 1 && j > 1) cur+= grid[i - 1][j - 1];
						//cout<<cur<< " "<<len<<" "<<wid<<endl;
					 
						if(cur==len*wid)
							mx=max(cur,mx);
						
					}
			}
		
		printf("%d\n",mx);
	}

	
	
	
}
