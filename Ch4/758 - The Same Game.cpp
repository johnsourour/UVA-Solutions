#include<bits/stdc++.h>
using namespace std;
#define MAX 15
char grid[MAX][MAX];
int ccnt[MAX][MAX];
bool V[MAX][MAX];
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
int min_row,min_col,RR;
void display(int s)
{
	if(!s)	for(int i=0;i<RR;i++){for(int j=0;j<MAX;j++)cout<<grid[i][j]<<" ";cout<<endl;}
	else
		for(int i=0;i<RR;i++){for(int j=0;j<MAX;j++)cout<<ccnt[i][j]<<" ";cout<<endl;}
	cout<<endl;
}
void compress(){
	
	//squeeze rows
	for(int j=0;j<MAX;j++)
	{
		for(int i=0;i<RR;i++)
		{
			if(grid[i][j]==' ')
			{
				
				for(int ii=i-1;ii>=0;ii-- )
				{
					grid[ii+1][j]=grid[ii][j];
					grid[ii][j]=' ';
					
				}
			}
		}
		
	}
	//squeez cols;
	int mxx=MAX;
	for(int j=0;j<mxx;j++)
	{
		bool all=true;
		
		for(int i=0;i<RR && all;i++)
		{
			if(grid[i][j]!=' ')all=false;
		}
		if(all)
		{
			for(int i=0;i<RR;i++)
			for(int jj=j;jj<MAX-1;jj++)
			{
			grid[i][jj]=grid[i][jj+1];
			grid[i][jj+1]=' ';
			}
			j--;
			mxx--;
		}
		
	}
}
int floodfill(int r, int c, char c1) 
{
	
	if (r < 0 || r >= RR || c < 0 || c >= MAX) return 0; 
	if (grid[r][c] != c1 || V[r][c]) return 0; 
	V[r][c]=true;
	int ans = 1; 
	for (int d = 0; d < 4; d++)
		ans += floodfill(r + dr[d], c + dc[d], c1);
		
	if(c<min_col)
	{
		min_col=c;
		min_row=r;
	}
	else if(min_col == c)
	{
		min_row=max(r,min_row);
	}
	return ans; 
}
void floodfill2(int r, int c, char c1, char c2) 
{
	
	if (r < 0 || r >= RR || c < 0 || c >= MAX) return; 
	if (grid[r][c] != c1 || V[r][c]) return; 
	V[r][c]=true; 
	grid[r][c]=c2;
		ccnt[r][c]=0;
	for (int d = 0; d < 4; d++)
		floodfill2(r + dr[d], c + dc[d], c1, c2);
}
void floodfill3(int r, int c, char c1, int c2) 
{
	
	if (r < 0 || r >= RR || c < 0 || c >= MAX) return; 
	if (grid[r][c] != c1 || V[r][c]) return; 
	V[r][c]=true;
	ccnt[r][c]=c2;
	for (int d = 0; d < 4; d++)
		floodfill3(r + dr[d], c + dc[d], c1, c2);
}
int main()
{
	int n,K=1;
	cin>>n;
	string s;
	
	getline(cin,s);
	getline(cin,s);
	while(n--)
	{
		int ii=0;
		while(getline(cin,s) && s.length()>0)
		{
			for(int j=0;j<MAX;j++){grid[ii][j]=s.at(j);}
			
			ii++;
		}
		RR=ii;
		int turn=1,tot=0,balls=RR*MAX;
		printf("Game %d:\n\n",K++);
		while(1)
		{
			int mx=0;
			memset(ccnt,0,sizeof ccnt);
			int cur_min_row,cur_min_col;
			cur_min_row=cur_min_col=MAX+1;
			for(int i=0;i<RR;i++)
			for(int j=0;j<MAX;j++)
			{
			
				if(ccnt[i][j]>0 || grid[i][j]==' ')continue;
				min_row=i;
				min_col=j;
				
				memset(V,false,sizeof V);
				int cnt=floodfill(i,j,grid[i][j]);
				memset(V,false,sizeof V);
				floodfill3(i,j,grid[i][j],cnt);
				
				if(cnt>mx)
				{
					mx=cnt;
					cur_min_row=min_row;
					cur_min_col=min_col;
				}
				else if(cnt==mx)
				{
					
					if(min_col<cur_min_col)
					{
						cur_min_col=min_col;
						cur_min_row=min_row;
					}
					else if(min_col == cur_min_col)
					{
						cur_min_row=max(cur_min_row,min_row);
					}
				}
			}
			
			if(mx<=1)break;
			int score=(mx-2)*(mx-2);
			tot+=score;
			balls-=mx;
			int rr=cur_min_row,cc=cur_min_col;
			printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n",turn++,RR-rr,cc+1,mx,grid[rr][cc],score);
			memset(V,false,sizeof V);
			floodfill2(rr,cc,grid[rr][cc],' ');
		//	display(0);
		//	display(1);
			compress();
		}
		if(!balls)tot+=1000;
		printf("Final score: %d, with %d balls remaining.\n",tot,balls);
		if(n)printf("\n");
	}
}
