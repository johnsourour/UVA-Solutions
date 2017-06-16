#include<bits/stdc++.h>
using namespace std;

int n,b,m,t;
vector<pair<int,int> >areas;
vector<int>towers;
int current,mx,sol;

int count(int a)
{
	int n = 0;
	while(a)
	{
		n++;
		a-=(a&(-a));
	}
	return n;
}
int main()
{
	int K = 1;
	scanf("%d%d",&n,&b);
	while(n||b)
	{
		mx=-1e9;
		towers.clear();
		areas.clear();
		for(int i=0;i<n;i++)
		{
			scanf("%d",&t);
			towers.push_back(t);
		}
		scanf("%d",&m);
		areas.resize(m);
		for(int i=0;i<m;i++)
		{
			scanf("%d",&t);
			for(int j=0;j<t;j++)
			{
				int p;
				scanf("%d",&p);
				areas[i].first|=1<<(p-1);
			}
			scanf("%d",&areas[i].second);
		}
		int customers;
		for(int k=1;k<(1<<(n));k++)
		if(count(k)==b)
		{
			customers=0;
			for(int i=0;i<n;i++)
				if(k&(1<<i))
				{
					customers+=towers[i];
				}
			for(int i=0;i<m;i++)
			{
				int tmp = areas[i].first&k;
				if(tmp>1)
				customers-=(count(tmp)-1)*areas[i].second;

			}
			if(customers>mx)
			{
				mx=customers;
				sol = k;
			}
		}
		printf("Case Number  %d\n",K);
		printf("Number of Customers: %d\n",mx);
		printf("Locations recommended:");
		for(int i=0;i<n;i++)
			if(sol&(1<<i))
			printf(" %d",i+1);
		printf("\n\n");
		K++;
		scanf("%d%d",&n,&b);
	}
	return 0;
}
