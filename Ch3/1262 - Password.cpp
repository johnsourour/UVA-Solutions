#include<bits/stdc++.h>
using namespace std;
int k,cur;
vector<vector<char> > grid1,grid2;
vector<char> acur,ans;
set<char> sa1;
bool found;
char g1[6][5],g2[6][5];
void backtrack(int u)
{
	if(u==5)
	{
		cur++;
		if(cur==k){ans=acur;found=true;}
		return;
	}
	int i=0;
	while(i<6 && !found)
	{
		char tmp=grid1[u][i];
		int j=0;
		bool flag=sa1.count(tmp);
		while(j<6 && !found && !flag)
		{
			
			if(tmp==grid2[u][j])
			{
			
				acur.push_back(tmp);
				sa1.clear();
				backtrack(u+1);
				acur.pop_back();
				flag=true;
				
			}
			
			j++;
		}
		sa1.insert(tmp);
		
		i++;
	}
	sa1.clear();
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&k);
		grid1.clear();
		grid1.resize(5);
		grid2.clear();
		grid2.resize(5);
		ans.clear();
		sa1.clear();
		cur=0;
		bool asc=(k<=3888);
		if(!asc)k=7776-k;
		found=false;
		for(int i=0;i<6;i++)
		{
			scanf("%s",&g1[i][0],sizeof g1[i]);
		}
		for(int i=0;i<6;i++)
		{
			scanf("%s",&g2[i][0],sizeof g2[i]);
		}
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<6;j++)
			{
				grid1[i].push_back(g1[j][i]);
			}
			if(asc)sort(grid1[i].begin(),grid1[i].end());
			else sort(grid1[i].begin(),grid1[i].end(),greater<char>());
		}
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<6;j++)
			{
				grid2[i].push_back(g2[j][i]);
			}
			if(asc)sort(grid2[i].begin(),grid2[i].end());
			else sort(grid2[i].begin(),grid2[i].end(),greater<char>());
		}
	
		backtrack(0);
		if(!found)printf("NO");
		else for(char c:ans)printf("%c",c);
		printf("\n");
	}
	return 0;
}
