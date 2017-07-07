#include<bits/stdc++.h>
using namespace std;
#define MAX_BEADS 52
typedef pair<int,int> ii;
list<int> cyc; 
vector<vector<ii> > adjList;
int cnt[MAX_BEADS];
void EulerTour(list<int>::iterator i, int u) 
{
	for (vector<ii>::iterator it = adjList[u].begin(); it != adjList[u].end(); it++)
	{
		if (it->second) 
		{ 
			it->second = 0; 
			for (vector<ii>::iterator it2 = adjList[it->first].begin(); it2 != adjList[it->first].end(); it2++) 
			{
				
				if (it2->first == u && it2->second)
				{
					it2->second = 0;
					break;
				}
			}
		EulerTour(cyc.insert(i, u), (it->first));
		}
	}
}
int main()
{
	int T,n,K=1,f,t;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		cyc.clear();
		adjList.clear();
		adjList.resize(MAX_BEADS);
		memset(cnt, 0, sizeof cnt);
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&f,&t);
			f--;t--;
			adjList[f].push_back(ii(t,1));
			adjList[t].push_back(ii(f,1));
			cnt[f]++;cnt[t]++;
		}
		bool possible=true;
		int first=-1;
		for(int i=0;i<MAX_BEADS && possible ;i++)
		{
			if(cnt[i]!=0 && first==-1)first=i;
			if(cnt[i]%2==1)
			{
				possible=false;
			}
		}
		printf("Case #%d\n",K++);
		if(!possible)printf("some beads may be lost\n");
		else
		{
			EulerTour(cyc.begin(),first);
			for (list<int>::iterator it=cyc.begin();it!=cyc.end();++it)
			{
				first++;
				printf("%d %d\n",first,(*it)+1);
				first=*it;				
			}
		}
		if(T)printf("\n");
	}

	return 0;
}
