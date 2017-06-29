#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define MAX_P 105
#define MAX_V 210
#define INF 1e9
int res[MAX_V][MAX_V],res2[MAX_V][MAX_V], mf, f, s, t, n, penguins;
int x[MAX_P],y[MAX_P];
double D;
vi p; 
void augment(int v, int minEdge) 
{ 
	if (v == s) { f = minEdge; return; } 
	else if (p[v] != -1) { 
		augment(p[v], min(minEdge, res2[p[v]][v]));
		res2[p[v]][v] -= f; res2[v][p[v]] += f; 
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
				if (res2[u][v] > 0 && dist[v] == INF){
					dist[v] = dist[u] + 1; q.push(v); p[v] = u;} 
		}
		augment(t, INF); 
		if (f == 0) break; 
		mf += f; 
	}
}
int out(int i)
{
	return i+MAX_P;
}
double dist(int i, int j)
{
	return sqrt(pow((x[i]-x[j]),2)+pow((y[i]-y[j]),2));
}
void init()
{
	int np,fl;
	memset(res,0,sizeof res);
	penguins=0;
	scanf("%d%lf",&n,&D);
	s=MAX_V-2;t=MAX_V-1;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&x[i],&y[i],&np,&fl);
		if(np)
		{
			res[s][i]=np;
			penguins+=np;
		}
		res[i][out(i)]=fl;
		for (int j = i-1; j >=0; j--)
        {
            if (dist(i,j) <= D)
            {
            	res[out(i)][j]=res[out(j)][i]=INF;
            }
        }
	}
}
void solve()
{
	string ans="";
	for(int i=0;i<n;i++)
	{
		res[i][t]=INF;
		copy(&res[0][0], &res[0][0]+MAX_V*MAX_V,&res2[0][0]);
		EdmondsKarp();
		if(mf==penguins)
		{
			if(ans!="")ans+=" ";
			ans+=to_string(i);
		}
		res[i][t]=0;
	}
	if(ans=="")ans+="-1";
	printf("%s\n",ans.c_str());
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		init();
		solve();
	
	}
	
	return 0;
}
