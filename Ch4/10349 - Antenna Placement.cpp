#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
char grid[42][12];
vi match, vis; 
vector<vi> adjList;
map<ii,int> pts;
vector<ii> ls;
int n, V, R, C, cnt;
int Aug(int l) 
{ 
	if (vis[l]) return 0; 
	vis[l] = 1;
	for (int r: adjList[l])
	{
		if (match[r] == -1 || Aug(match[r])) 
		{
			match[r] = l; 
			return 1; 
		}
	} 
	return 0; 
}
void init()
{
	scanf("%d%d",&R,&C);
	pts.clear();
	ls.clear();
	cnt=0;
	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++)
		{
			scanf(" %c",&grid[i][j]);
			if(grid[i][j]=='*')pts.insert(iii(ii(i,j),cnt++));
		}
	adjList.clear();
	adjList.resize(cnt);
	for(map<ii,int>::iterator it=pts.begin();it!=pts.end();++it)
	{
		ii p=(*it).first;
		if((p.first+p.second)%2==1)continue;
		ls.push_back(p);
		for(int k=0;k<4;k++)
		{
			ii tmp=ii(p.first+dr[k],p.second+dc[k]);
			if(pts.find(tmp)!=pts.end())
			{
				adjList[pts[p]].push_back(pts[tmp]);
			}
		}
	}
	n=ls.size();
	match.assign(cnt, -1); 
}
int MCBM()
{
	int tot=0;
	for (int l = 0; l < n; l++) { 
		vis.assign(cnt, 0); 
		tot += Aug(pts[ls[l]]);
	}
	return tot;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		init();
		printf("%d\n",cnt-MCBM());
		
	}
	return 0;
}
