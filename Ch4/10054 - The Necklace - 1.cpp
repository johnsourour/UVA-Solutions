#include<bits/stdc++.h>
using namespace std;
#define MAX_BEADS 52
typedef pair<int,int> ii;
list<ii> cyc; 
int adjMat[MAX_BEADS][MAX_BEADS];
int cnt[MAX_BEADS];
void EulerTour(list<ii>::iterator i,int u) 
{
	for (int k=0;k<MAX_BEADS;k++) 
	{
		if (adjMat[u][k]!=0) 
		{ 
			adjMat[u][k]--;
			adjMat[k][u]--;
			EulerTour(cyc.insert(i,ii(k+1,u+1)),k);
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
		memset(adjMat, 0, sizeof adjMat);
		memset(cnt, 0, sizeof cnt);
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&f,&t);
			f--;t--;
			adjMat[f][t]++;
			adjMat[t][f]++;
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
			for (list<ii>::iterator it=cyc.begin();it!=cyc.end();++it)
			{
				printf("%d %d\n",(*it).first,(*it).second);
				
			}
		}
		if(T)printf("\n");
	}

	return 0;
}
