#include<bits/stdc++.h>
using namespace std;
#define MAX_V 98
#define INF 1e9
typedef vector<int> vi;
typedef pair<int,int> ii;
int res[MAX_V][MAX_V], mf, f, s, t, M, W; 
vi p, scomp; 
vector<bool> capped, reached;
vector<vector<ii> > adjList;

void augment(int v, int minEdge) 
{
	if (v == s) { f = minEdge; return; } 
	else if (p[v] != -1) { 
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f; res[v][p[v]] += f; 
	}
}
void EdmondsKarp()
{
	mf = 0; 
	while (1) 
	{ 
		f = 0;
		vi dist(MAX_V, INF); dist[s] = 0; queue<int> q; q.push(s);
		p.assign(MAX_V, -1);
		while (!q.empty()) 
		{
			int u = q.front(); q.pop();
			if (u == t) break; 
			for (int v = 0; v < MAX_V; v++) 
				if (res[u][v] > 0 && dist[v] == INF){
					dist[v] = dist[u] + 1; q.push(v); p[v] = u;} 
		}
		augment(t, INF); 
		if (f == 0) break; 
		mf += f; 
	}
}
int out(int n)
{
	return n+M-1;	
}
int main()
{
	scanf("%d%d",&M,&W);
	int id,id2,cost;
	while(M||W)
	{
		scomp.clear();
		capped.clear();
		capped.resize(M);
		reached.clear();
		reached.resize(2*M);
		adjList.clear();
		adjList.resize(2*M);
		memset(res, 0, sizeof res);
		s=0,t=M-1;
		for(int i=2;i<M;i++)
		{
			scanf("%d%d",&id,&cost);id--;
			if(cost){
				res[id][out(id)]=cost;
				adjList[out(id)].push_back(ii(id,cost));
				adjList[id].push_back(ii(out(id),cost));
			
			}
		}
		while(W--)
		{
			scanf("%d%d%d",&id,&id2,&cost);id--;id2--;
			int in1=id,in2=id2,out1,out2;
			if(id==s || id==t)out1=id;
			else out1=out(id);
			if(id2==s || id2==t)out2=id2;
			else out2=out(id2);
			res[out2][in1]=cost;
			adjList[out2].push_back(ii(in1,cost));
			adjList[in1].push_back(ii(out2,cost));
			
			res[out1][in2]=cost;
			adjList[out1].push_back(ii(in2,cost));
			adjList[in2].push_back(ii(out1,cost));
		
		}
		EdmondsKarp();
		printf("%d\n",mf);
		scanf("%d%d",&M,&W);	
	}
}
