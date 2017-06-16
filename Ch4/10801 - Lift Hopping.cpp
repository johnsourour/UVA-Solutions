#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
vector<vector<iii> > adjList;
int dijkstra(int s,int e)
{
	vi dist(100, INF); dist[s] = 0; 
	priority_queue< iii, vector<iii>, greater<iii> > pq; pq.push(iii(-1,ii(0, s)));
	while (!pq.empty())
	{ // main loop
		iii front = pq.top(); pq.pop(); 
		int el= front.first, d=front.second.first, u = front.second.second;
		if (d > dist[u]) continue;
		for (iii v:adjList[u]) 
		{
		//	cout<<v.first<<" "<<el<<endl;
			int diff=(v.first!=el && el!=-1)?60:0;
			if (dist[u] + v.second.second + diff < dist[v.second.first]) 
			{
				dist[v.second.first] = dist[u] + v.second.second+diff;
				pq.push(iii(v.first,ii(dist[v.second.first], v.second.first)));
			} 
		}
	}
	return dist[e];
}
int main()
{
	int N,k;
	string s;
	vector<int> elev;
	while(scanf("%d%d",&N,&k)!=EOF)
	{
		adjList.clear();
		adjList.resize(100);
		elev.clear();
		elev.resize(N);
		for(int i=0;i<N;i++)
			scanf("%d",&elev[i]);
	
		getline(cin,s);
		
		for(int i=0;i<N;i++)
		{
			getline(cin,s);
			vector<int> tmp;
			while(s.length()>0)
			{
				string num="";
				while(s.length()>0 && s.at(0)!=' '){
					num+=s.at(0);s.erase(0,1);
				}
				if(s.length()>0)s.erase(0,1);
				tmp.push_back(stoi(num));
			}
			for(int x=0;x<tmp.size();x++)
			{
				for(int y=x+1;y<tmp.size();y++)
				{
					adjList[tmp[x]].push_back(iii(i,ii(tmp[y],abs(tmp[x]-tmp[y])*elev[i])));
					adjList[tmp[y]].push_back(iii(i,ii(tmp[x],abs(tmp[x]-tmp[y])*elev[i])));
				}
			}
			
		}
		int ans=dijkstra(0,k);
		if(ans==INF)printf("IMPOSSIBLE\n");
		else printf("%d\n",ans);
	
	}
	return 0;
}
