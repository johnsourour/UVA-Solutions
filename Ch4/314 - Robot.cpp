#include<bits/stdc++.h>
using namespace std;
int adjMat[55][55];
int dir[55][55][4];
int R,C;
int dr[4][3]={ {-1,-2,-3}, { 0, 0, 0}, { 1, 2, 3}, { 0, 0, 0}};
int dc[4][3]={ { 0, 0, 0}, { 1, 2, 3}, { 0, 0, 0}, {-1,-2,-3}};
pair<int,pair<int,int> > pp[55][55][4];
void printParent(int d, int x, int y)
{
	if(x==-1){return;}
	printParent(pp[x][y][d].first,pp[x][y][d].second.first,pp[x][y][d].second.second);
	cout<<x<<" "<<y<<" "<<d<<endl;
	
}
bool can(int x, int y)
{
	if(y<=0 || y>C || x<=0 || x>=R || adjMat[x][y] || adjMat[x-1][y]|| adjMat[x][y-1]|| adjMat[x-1][y-1])return false;
	return true;
}
int BFS(int x, int y, int xx, int yy, int d)
{
	queue<pair<pair<int,int>,pair<int,int> > > q;
	if(x==xx && y==yy)return 0;
	if(!can(x,y) || !can(xx,yy))return -1;
	q.push(make_pair(make_pair(x,y),make_pair(d,0)));
	int ans,cur=0;
	dir[x][y][d]=1;
	memset(pp,-1,sizeof pp);
	while(!q.empty())
	{
		pair<pair<int,int>,pair<int,int> > f=q.front();q.pop();
		for(int i=1;i<=3;i+=2)
		{
			int nx=f.first.first,ny=f.first.second,nd=(f.second.first+i)%4;
			if(!dir[nx][ny][nd])
			{
				if(nx==xx && ny==yy)return f.second.second+1;
				dir[nx][ny][nd]=1;
			//	pp[nx][ny][nd]=make_pair(f.second.first,make_pair(f.first.first,f.first.second));
			
				q.push(make_pair(make_pair(nx,ny),make_pair(nd,f.second.second+1)));
			}
			
		}
		for(int i=0;i<3;i++)
		{
			int nx=f.first.first+dr[f.second.first][i],ny=f.first.second+dc[f.second.first][i];
			
			if(can(nx,ny))
			{	
				if(dir[nx][ny][f.second.first])continue;
				if(nx==xx && ny==yy)return f.second.second+1;
			//	pp[nx][ny][f.second.first]=make_pair(f.second.first,make_pair(f.first.first,f.first.second));
				dir[nx][ny][f.second.first]=1;
				q.push(make_pair(make_pair(nx,ny),make_pair(f.second.first,f.second.second+1)));
			}
			else break;
		}
		
		
	}
	return -1;
}
int main()
{
	int d,x,t,y,xx,yy;
	string s;
	char c[10];

	scanf("%d%d",&R,&C);
	while(R||C)
	{
		memset(dir,0,sizeof dir);
		for(int i=0;i<R;i++)
			for(int j=0;j<C;j++)
				{
					scanf("%d",&adjMat[i][j]);
				}
		scanf("%d%d%d%d",&x,&y,&xx,&yy);
		scanf("%s",&c[0],sizeof c);
		s=c;
		if(s=="north")d=0;
		else if(s=="east")d=1;
		else if(s=="south")d=2;
		else d=3;
		
		printf("%d\n",BFS(x,y,xx,yy,d));

		scanf("%d%d",&R,&C);
	}
	return 0;
}
