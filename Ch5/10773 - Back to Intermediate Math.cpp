#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T,K=1;
	double d,v,u,t1,t2;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lf%lf%lf",&d,&v,&u);
		printf("Case %d: ",K++);
		if(v && u &&v<u)
		{
			t1=d/u;
			t2=d/sqrt(pow(u,2)-pow(v,2));
			printf("%.3lf\n",fabs(t1-t2));
		}
		else printf("can't determine\n");
	}
	return 0;
}
