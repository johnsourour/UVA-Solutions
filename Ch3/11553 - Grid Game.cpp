#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,c,mx,sum;
	scanf("%d",&t);
	vector<vector<int> > grid;
	vector<int> iperm;
	while(t--)
	{
		scanf("%d",&n);
		grid.clear();
		grid.resize(n);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%d",&c);	
				grid[i].push_back(c);
			}
		}
		mx=1e9;
		iperm.clear();
		for(int i=0;i<n;i++){iperm.push_back(i);}
		do
		{
			
			sum=0;
			for(int i=0;i<n;i++)
			{
				sum+=grid[i][iperm[i]];
				
			}
			mx=min(mx,sum);
		
		}while(next_permutation(iperm.begin(),iperm.end()));
		printf("%d\n",mx);
	}
	
	return 0;
}
