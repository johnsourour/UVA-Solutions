#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
vi match, vis, L, R; 
vector<vi> adjList;
int n,m;
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
	scanf("%d",&n);
	L.clear();L.resize(n);
	for(int i=0;i<n;i++)scanf("%d",&L[i]);
	scanf("%d",&m);
	R.clear();R.resize(m);
	for(int i=0;i<m;i++)scanf("%d",&R[i]);
	adjList.clear();
	adjList.resize(n+m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			if(L[i])
			{
				if( !R[j] || (R[j]%L[i])==0)
				{
					//cout<<L[i]<<" "<<R[j]<<endl;
					adjList[i].push_back(j+n);
				}
			}
			else if(!R[j]) 	adjList[i].push_back(j+n);
		}
	match.assign(n+m, -1); 
}
int MCBM()
{
	int tot=0;
	for (int l = 0; l < n; l++) { 
		vis.assign(n, 0); 
		tot += Aug(l);
	}
	return tot;
}
int main()
{
	int T, K=1;
	scanf("%d",&T);
	while(T--)
	{
		init();
		printf("Case %d: %d\n",K++,MCBM());
		
	}
	return 0;
}
