#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define MAX_V 105
#define INF 1e9
int res[MAX_V][MAX_V], mf, f, s, t, n; 
vi p; 
void augment(int v, int minEdge) 
{ 
	if (v == s) { f = minEdge; return; } 
	else if (p[v] != -1) { 
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f; res[v][p[v]] += f; 
	}
}
void EdmondKarps()
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

int main()
{
	scanf("%d",&n);
	int m,x,y,w,K=1;
	while(n)
	{
		memset(res, 0, sizeof res);
		p.clear();
		scanf("%d%d%d",&s,&t,&m);s--;t--;
		while(m--)
		{
			scanf("%d%d%d",&x,&y,&w);x--;y--;
			res[x][y]+=w;
			res[y][x]+=w;
		}
		EdmondKarps();
		printf("Network %d\nThe bandwidth is %d.\n\n",K++,mf);
		scanf("%d",&n);	
	}
	return 0;
}
