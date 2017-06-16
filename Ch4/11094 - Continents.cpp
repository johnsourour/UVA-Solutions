#include<bits/stdc++.h>
using namespace std;
int dr[] = {1,0,-1, 0}; 
int dc[] = {0,1, 0,-1};
int M,N;
char grid[25][25];
int floodfill(int r, int c, char c1, char c2) 
{
	if (r < 0 || r >= M) return 0; 
	if(c<0)c=N-1;
	if(c>=N)c=0;
	if (grid[r][c] != c1) return 0; 
	
	int ans = 1; 
	grid[r][c] = c2; 
	for (int d = 0; d < 4; d++)
		ans += floodfill(r + dr[d], c + dc[d], c1, c2);
	return ans; 
}
int main()
{
	int mx,x,y;
	char l,w;
	while(scanf("%d%d",&M,&N)!=EOF)
	{
		mx=0;
		l=w=NULL;
		for(int i=0;i<M;i++)
		{
			for(int j=0;j<N;j++)
			{
				scanf(" %c",&grid[i][j]);
				if(w==NULL)w=grid[i][j];
				else if(w!=grid[i][j])l=grid[i][j];
			}
		}
		scanf("%d%d",&x,&y);
		if(l==NULL)l=w+1;
		if(grid[x][y]!=l)swap(l,w);
		
	//	cout<<l<<w<<endl;
		floodfill(x,y,l,w);
	
		for(int i=0;i<M;i++)
		{
			for(int j=0;j<N;j++)
			{
				
				if(grid[i][j]==l)
					mx=max(mx,floodfill(i,j,l,w));
			//	cout<<grid[i][j];
			}
			//cout<<endl;
		}
		printf("%d\n",mx);
	}
	return 0;
}
