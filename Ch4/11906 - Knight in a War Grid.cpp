#include<bits/stdc++.h>
using namespace std;
int even,odd,M,N,R,C,G[105][105];
bool V[105][105];
void dfs(int x, int y)
{
	V[x][y]=true;
	int tot=0,i,j;
	if(M==0)
	{
		i=x+N;
		j=y;
		if(i>=0 && j>=0 && i<R && j<C && G[i][j]!=-1){tot++;if(!V[i][j])dfs(i,j);}
		i=x-N;
		j=y;
		if(i>=0 && j>=0 && i<R && j<C && G[i][j]!=-1){tot++;if(!V[i][j])dfs(i,j);}
		i=x;
		j=y+N;
		if(i>=0 && j>=0 && i<R && j<C && G[i][j]!=-1){tot++;if(!V[i][j])dfs(i,j);}
		i=x;
		j=y-N;
		if(i>=0 && j>=0 && i<R && j<C && G[i][j]!=-1){tot++;if(!V[i][j])dfs(i,j);}
	}
	else if(N==0)
	{
		i=x+M;
		j=y;
		if(i>=0 && j>=0 && i<R && j<C && G[i][j]!=-1){tot++;if(!V[i][j])dfs(i,j);}
		i=x-M;
		j=y;
		if(i>=0 && j>=0 && i<R && j<C && G[i][j]!=-1){tot++;if(!V[i][j])dfs(i,j);}
		i=x;
		j=y+M;
		if(i>=0 && j>=0 && i<R && j<C && G[i][j]!=-1){tot++;if(!V[i][j])dfs(i,j);}
		i=x;
		j=y-M;
		if(i>=0 && j>=0 && i<R && j<C && G[i][j]!=-1){tot++;if(!V[i][j])dfs(i,j);}
	}
	else if(N==M)
	{
		
		i=x+N;
		j=y+N;
		if(i>=0 && j>=0 && i<R && j<C && G[i][j]!=-1){tot++;if(!V[i][j])dfs(i,j);}
		i=x-N;
		j=y+N;
		if(i>=0 && j>=0 && i<R && j<C && G[i][j]!=-1){tot++;if(!V[i][j])dfs(i,j);}
		i=x+N;
		j=y-N;
		if(i>=0 && j>=0 && i<R && j<C && G[i][j]!=-1){tot++;if(!V[i][j])dfs(i,j);}
		i=x-N;
		j=y-N;
		if(i>=0 && j>=0 && i<R && j<C && G[i][j]!=-1){tot++;if(!V[i][j])dfs(i,j);}
	}
	else
	{
		i=x+N;
		j=y+M;
		if(i>=0 && j>=0 && i<R && j<C && G[i][j]!=-1){tot++;if(!V[i][j])dfs(i,j);}
		i=x-N;
		j=y+M;
		if(i>=0 && j>=0 && i<R && j<C && G[i][j]!=-1){tot++;if(!V[i][j])dfs(i,j);}
		i=x+N;
		j=y-M;
		if(i>=0 && j>=0 && i<R && j<C && G[i][j]!=-1){tot++;if(!V[i][j])dfs(i,j);}
		i=x-N;
		j=y-M;
		if(i>=0 && j>=0 && i<R && j<C && G[i][j]!=-1){tot++;if(!V[i][j])dfs(i,j);}
		i=x+M;
		j=y+N;
		if(i>=0 && j>=0 && i<R && j<C && G[i][j]!=-1){tot++;if(!V[i][j])dfs(i,j);}
		i=x-M;
		j=y+N;
		if(i>=0 && j>=0 && i<R && j<C && G[i][j]!=-1){tot++;if(!V[i][j])dfs(i,j);}
		i=x+M;
		j=y-N;
		if(i>=0 && j>=0 && i<R && j<C && G[i][j]!=-1){tot++;if(!V[i][j])dfs(i,j);}
		i=x-M;
		j=y-N;
		if(i>=0 && j>=0 && i<R && j<C && G[i][j]!=-1){tot++;if(!V[i][j])dfs(i,j);}
	}
	if(tot%2==1)odd++;
	else even++;
}
int main()
{	
	int x,y,T,W,K=1; scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&R,&C,&M,&N);
		memset(G,0,sizeof G);
		memset(V,false,sizeof V);
		 scanf("%d",&W);
		 while(W--)
		 {
		 	scanf("%d%d",&x,&y);
		 	G[x][y]=-1;
		 }
		 
		even=odd=0;
		 dfs(0,0);
		 printf("Case %d: %d %d\n",K++,even,odd);
	}
	return 0;
}
