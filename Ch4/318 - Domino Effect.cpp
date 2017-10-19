#include<bits/stdc++.h>
using namespace std;
#define MAX 505
#define INF 1e9
typedef pair<int,int> ii;
typedef pair<ii,double> iii;
int cost[MAX][MAX];
bool V[MAX][MAX];
int dist[MAX],n,m,parent[MAX];
int main()
{
	int K=1;
	while(cin>>n>>m && (n||m))
	{
		for(int i=1;i<n;i++){dist[i]=INF;parent[i]=-1;}
	
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)cost[i][j]=INF;
		
			for(int i=0;i<m;i++)
		{
			int f,t,w;
			cin>>f>>t>>w;
			f--;t--;
			cost[f][t]=cost[t][f]=w;
			
		}
		priority_queue< ii, vector<ii>, greater<ii> > pq;
		pq.push(ii(0,0));
		vector<iii> bet;
		while(!pq.empty())
		{
			ii front = pq.top(); pq.pop(); 
			int d = front.first, u = front.second;
			if (d > dist[u]) continue;
			for (int i=0;i<n;i++) 
			{
				if (dist[u] + cost[u][i]< dist[i]) 
				{
					dist[i] = dist[u] +cost[u][i];
					pq.push(ii(dist[i], i));
					parent[i]=u;
				} 
			}
		}
		
		for(int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++) 
			{
				if(cost[j][i]==INF || parent[i]==j)continue;
				if(dist[i]-dist[j]<cost[i][j] && dist[i]-dist[j]>=0)
				{
				double dd=(cost[i][j]-dist[i]+dist[j])/2.0;
				bet.push_back(iii(ii(i,j),dd+max(dist[i],dist[j])));
				}
			}
			
		}
		double mx=0;
		int mxat=0,mxat2;
		bool bb=false;
		for(int i=0;i<n;i++){
			if(dist[i]>mx){
				mx=dist[i];
				mxat=i;
			}
		}
		for(iii pp:bet)
		{
			if(pp.second>mx){
				mx=pp.second;
				mxat=min(pp.first.first,pp.first.second);
				mxat2=max(pp.first.first,pp.first.second);
				
				bb=true;
			}
		}
		
		
		printf("System #%d\n",K++);
		if(!bb)
		{
			printf("The last domino falls after %.1lf seconds, at key domino %d.\n\n",mx,mxat+1);	
		}
		else
		{
			printf("The last domino falls after %.1lf seconds, between key dominoes %d and %d.\n\n",mx,min(mxat+1,mxat2+1),max(mxat+1,mxat2+1))	;
		}
	}
	return 0;
}
