#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > adjList;
vector<bool> seen;
int E,day;
int BFS(int s)
{
	seen.clear();
	seen.resize(E);
	queue<pair<int,int> > q;
	vector<int> days;
	days.push_back(1);
	q.push(make_pair(s,0));
	int ans=0,cnt;
	seen[s]=true;
	while(!q.empty())
	{
		pair<int,int> f=q.front();q.pop();
		
		cnt=0;
		for(int i:adjList[f.first])
		{
			if(!seen[i])
			{
				seen[i]=true;
				cnt++;
				q.push(make_pair(i,f.second+1));
			}
		}
		if(f.second+1>=days.size())
		{
			days.push_back(cnt);
		}
		else days[f.second+1]+=cnt;
		if(days[f.second+1]>ans){
			ans=days[f.second+1];
			day=f.second+1;
		}
	}
	return ans;
}
int main()
{
	int T,n,s;
	while(scanf("%d",&E)!=EOF)
	{
		adjList.clear();
		adjList.resize(E);
		for(int i=0;i<E;i++)
		{
			scanf("%d",&n);
			adjList[i].resize(n);
			for(int j=0;j<n;j++)scanf("%d",&adjList[i][j]);
		}
		scanf("%d",&T);
		
		while(T--)
		{
			scanf("%d",&s);
			int ans=BFS(s);
			if(ans)printf("%d %d\n",ans,day);
			else printf("0\n");
		}
	}
	return 0;
}
