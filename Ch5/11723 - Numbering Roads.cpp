#include<bits/stdc++.h>
using namespace std;
int main()
{
	double N,R;
	int ans,K=1;
	scanf("%lf%lf",&R,&N);
	while(N||R)
	{
		ans=0;
		if(N<R)
		{
			ans=ceil((R-N)/N);
		}
		printf("Case %d: ",K++);
		if(ans<=26)
			printf("%d\n",ans);
		else
		printf("impossible\n");
		
		scanf("%lf%lf",&R,&N);
	}
	return 0;
}
