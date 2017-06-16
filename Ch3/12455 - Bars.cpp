#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,p,k,sum;
	vector<int> bars;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%d",&p);
		bars.clear();
		bars.resize(p);
		for(int i=0;i<p;i++)
		{
			scanf("%d",&k);
			bars[i]=k;
		}
		bool flag=false;
		for(int i=0;i<(1<<p);i++)
		{
			sum=0;
			for(int j=0;j<p;j++)
			{
				if(i & (1<<j))
				sum+=bars[j];
			}
			if(sum==n){
				flag=true;
				break;
			}
		}
		if(flag)printf("YES\n");
		else printf("NO\n");
	}
	
	return 0;
}
