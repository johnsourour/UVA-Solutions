#include <bits/stdc++.h>
using namespace std;
int ret;
vector<vector<int> > c;
vector<vector<int> > p;
void f()
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			c[i][j]=0;
			if(i>0)c[i][j]=(c[i][j]+p[i-1][j])%2;
			if(i<2)c[i][j]=(c[i][j]+p[i+1][j])%2;
			if(j>0)c[i][j]=(c[i][j]+p[i][j-1])%2;
			if(j<2)c[i][j]=(c[i][j]+p[i][j+1])%2;
		}
	}
}
bool k()
{	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			p[i][j]=c[i][j];
		}
	}
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(c[i][j]==1)
				return false;
			
		}
	}

	return true;
}
int main() {
	int C;
	scanf("%d",&C);
	while(C--)
	{
		p.clear();
		p.resize(3);
		c.clear();
		c.resize(3);
		char d;
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				scanf(" %c",&d);
				c[i].push_back(d-'0');
				p[i].push_back(d-'0');
			}
		}
		
		bool done=false;
		
		ret=-1;
		done=k();
		while(!done)
		{
			f();
			done=k();
			
			ret++;
		}
		printf("%d\n",ret);
		
	}
	return 0;
}
