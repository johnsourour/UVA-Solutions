#include<bits/stdc++.h>
using namespace std;
int dr[] = {1,-1,0, 0}; 
int dc[] = {0,0, 1,-1};
int N;
char grid[105][105];
int floodfill(int r, int c, char c1, char c2) 
{
	if (r < 0 || r >= N || c < 0 || c >= N) return 0; 
	int ans=1,cur;
	bool h,v;
	h=v=false;
	if (grid[r][c] == c2) return 0; 
	grid[r][c]=c2;
	cur=ans;
	for (int d = 0; d <2; d++)
		ans+=floodfill(r + dr[d], c + dc[d], c1, c2);
	if(ans>cur)v=true;
	cur=ans;
	for (int d = 2; d <4; d++)
		ans+=floodfill(r + dr[d], c + dc[d], c1, c2);
	if(ans>cur)h=true;
	if(h && v) return 2;
	else return 1;
}
int main()
{
	int T,K=1,ans;
	char l,w;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				scanf(" %c",&grid[i][j]);
			}
		}
		ans=0;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				
				if(grid[i][j]=='x')
				{
					ans+=floodfill(i,j,'x','.');
				}
				
			}
			//cout<<endl;
		}
		printf("Case %d: %d\n",K++,ans);
	}
	return 0;
}
