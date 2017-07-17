#include<bits/stdc++.h>
using namespace std;
vector<int> coef;
int main()
{
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF && (n>=0 || k>=0))
	{
		coef.clear();
		coef.resize(n+1);
		for(int i=0;i<=n;i++)scanf("%d",&coef[i]);
		for(int i=coef.size()-1;i>k-1;i--)coef[i-k]-=coef[i];
		int start=min(n,k-1);
		while(start>=0 && !coef[start])start--;
		if(start<0)printf("0\n");
		else
		{
			printf("%d",coef[0]);
			for(int i=1;i<=start;i++)printf(" %d",coef[i]);
			printf("\n");
		}
		
	}
}
