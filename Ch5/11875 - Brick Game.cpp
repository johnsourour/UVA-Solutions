#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T,N,A[12],K=1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		printf("Case %d: ",K++);
		printf("%d\n",A[N/2]);
		
	}
	return 0;
}
