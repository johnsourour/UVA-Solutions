#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 100000
int main()
{
	int T,K=1;
	ll N;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld",&N);
		printf("Case %d: ",K++);
		if((N*(N-1))%4==0)
		printf("%lld\n",(N*(N-1))/4);
		else 
		printf("%lld/%d\n",(N*(N-1))/2,2);
		
	}

}
