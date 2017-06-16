#include<bits/stdc++.h>
using namespace std;

int main()
{	
	int N,t;
	long long mx,cur;
	scanf("%d",&N);
	while(N)
	{
		mx=-1;
		cur=0;
		for(int i=0;i<N;i++)
		{
			scanf("%d",&t);
			cur+=t;
			if(cur<0)cur=0;
		
			if(cur>mx)mx=cur;
		}
		
	
		if(mx>0)printf("The maximum winning streak is %lld.\n",mx);
		else printf("Losing streak.\n");
		scanf("%d",&N);
	}
	return 0;
}
