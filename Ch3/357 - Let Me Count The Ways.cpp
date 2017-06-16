#include<bits/stdc++.h>
using namespace std;
int N=5;
int C[5]={1,5,10,25,50};
long long  M[6][30005];
long long  DP(int i, int rem)
{
	if(i==N)return 0;
	if(rem==0)return 1;
	if(rem<0)return 0;
	if(M[i][rem]!=-1)return M[i][rem];
	long long  a=DP(i,rem-C[i]);
	long long  b=DP(i+1,rem);
	 M[i][rem]=a+b;
	return M[i][rem];

}
int main()
{
	memset(M, -1, sizeof M);
	int i=0;
	while(scanf("%d",&i)!=EOF)
	{
		
		long long ans=DP(0,i);
		if(ans>1)
		printf("There are %lld ways to produce %d cents change.\n",ans,i);
		else
		printf("There is only 1 way to produce %d cents change.\n",i);
		
	}
	
	return 0;
}
