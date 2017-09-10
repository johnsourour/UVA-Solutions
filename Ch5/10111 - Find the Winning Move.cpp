#include<bits/stdc++.h>
using namespace std;
char grid[4][4];
bool can(int x,int y)
{
	if(x<0||y<0||x>=4||y>=4 || grid[x][y]!='.')return false;
	return true;
}
bool done(int id)
{
	bool ret=false;
	int cnt=0;
	char ch=(id==1)?'o':'x';
//	cout<<ch;
	for(int i=0;i<4 && !ret;i++)
	{
		ret=true;
		for(int j=0;j<4 && ret;j++)
		{
			if(grid[i][j]!=ch)ret=false;
			if(grid[i][j]=='.')cnt++;
		}
	}
	for(int i=0;i<4 && !ret;i++)
	{
		ret=true;
		for(int j=0;j<4 && ret;j++)
		{
			if(grid[j][i]!=ch)ret=false;
			if(grid[i][j]=='.')cnt++;
		}
		
	//	cout<<ret<<endl;
	}
	if(!ret)
	{
		ret=true;
		for(int i=0;i<4 && ret;i++){
		if(grid[i][i]!=ch)ret=false;
		if(grid[i][i]=='.')cnt++;
		}
	}
	if(!ret)
	{
		ret=true;
		for(int i=0;i<4 && ret;i++){
		if(grid[i][3-i]!=ch)ret=false;
		if(grid[i][3-i]=='.')cnt++;
		}
	}
	if(id==2)return cnt==0;
	return ret;
}
bool dis()
{
	for(int i=0;i<4 ;i++)
	{
	for(int j=0;j<4 ;j++)cout<<grid[i][j]<<" ";cout<<endl;}
}
bool backtrack(int x, int y, int id)
{
	bool win=id==1?true:false;
//	dis();
//	cout<<endl;
	if(done(0))return true;
	else if(done(1) )return false;
	else if(done(2)) return false;
	
	char ch=id==1?'o':'x';
	for(int i=0;i<4;i++)
	for(int j=0;j<4;j++)
	{
		if(can(i,j))
		{
			grid[i][j]=ch;
			win=backtrack(i,j,1-id);
			
			grid[i][j]='.';
			if(win && id==0 )return true;
			if(!win && id==1)return false;
		}
	}
	return win;
}
int main()
{
	char c;
	string s;
	while(cin>>c && c!='$')
	{
		for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)cin>>grid[i][j];
		bool win=false;
	int i,j;
		for(i=0;i<4 && !win;i++)
		for(j=0;j<4 && !win;j++)
		{
			if(can(i,j))
			{
				grid[i][j]='x';
				win=backtrack(i,j,1);
				grid[i][j]='.';
			}
		}
		if(!win)cout<<"#####"<<endl;
		else printf("(%d,%d)\n",i-1,j-1);
		
		
	}
}
