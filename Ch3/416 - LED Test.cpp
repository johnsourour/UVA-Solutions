#include<bits/stdc++.h>
using namespace std;
int N,cnt;
bool f[7],seg[10][7],match;
bool n[10][7]={{1,1,1,1,1,1,0},{0,1,1,0,0,0,0},{1,1,0,1,1,0,1},
{1,1,1,1,0,0,1},{0,1,1,0,0,1,1},{1,0,1,1,0,1,1},{1,0,1,1,1,1,1},
{1,1,1,0,0,0,0},{1,1,1,1,1,1,1},{1,1,1,1,0,1,1}};
void backtrack(int i)
{
	if(i>=N){match=true;return;}
	int t=0;
	bool flag=true;
	while(t<7 && flag)
	{
		if(!f[t] && seg[i][t])flag=false;
		else if(n[cnt][t]!=seg[i][t])
		{
			if(seg[i][t])flag=false;
			else f[t]=false;
		}
		t++;
	}
	if(flag){cnt--;backtrack(i+1);}
	
	
}
int main()
{
	
	char s[10];
	scanf("%d",&N);
	while(N)
	{
		match=false;
		
		for(int k=0;k<N;k++)
		{
			scanf("%s",&s[0],sizeof s);
			for(int i=0;i<7;i++)
			{
				if(s[i]=='Y')seg[k][i]=true;
				else seg[k][i]=false;
			}
		}
		int i=9;
		while(i>=N-1 && !match)
		{
			int t=0;
			memset(f,1,sizeof f);
			bool flag=true;
			while(t<7 && flag)
			{
				if(n[i][t]!=seg[0][t])
				{
					if(seg[0][t])flag=false;
					else f[t]=false;
				}
				t++;
			}
			cnt=i-1;
			if(flag)backtrack(1);
			i--;
		}
		if(!match)printf("MIS");
		printf("MATCH\n");
		scanf("%d",&N);
	}
	return 0;
}
