#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N,T;
	double ans,D,S;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		S=D=0.0;
		if(N>1)
		{
			S=4.0*(double)(N-1.0);
			D=sqrt(2)*(double)(pow(N-2,2));
		}
		ans=D+S;
		printf("%.3lf\n",ans);
		if(T)printf("\n");
		
	}

}
