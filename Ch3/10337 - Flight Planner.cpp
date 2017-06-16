#include<bits/stdc++.h>
using namespace std;
#define h 10
#define hold 30
#define climb 60
#define sink 20
int dist;
int A[10][1005], T[10][1005];
int DP(int alt, int X)
{
	if(alt<0 || alt>9 || X>dist)return 1e9;
	if(X==dist)
	{
		if(alt==0)return 0;
		return 1e9;
	}
	if(T[alt][X]!=-1)return T[alt][X];
	
	int a=hold+DP(alt,X+1);
	int b=sink+DP(alt-1,X+1);
	int c=climb+DP(alt+1,X+1);
	
	T[alt][X]=min(a,min(b,c))-A[alt][X];
	return T[alt][X];
}

int main()
{
	int K;
	scanf("%d",&K);
	
	while(K--)
	{
		scanf("%d",&dist);
		dist/=100;
		for(int i=h-1;i>=0;i--)
		for(int j=0;j<dist;j++)scanf("%d",&A[i][j]);
		memset(T,-1,sizeof T);
		printf("%d\n\n",DP(0,0));
	}
	return 0;
}
