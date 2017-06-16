#include<bits/stdc++.h>
using namespace std;

int A[52], T[52][52], n, l;
int DP(int left, int right)
{
	if(left+1==right)return 0;
	if(T[left][right]!=-1)return T[left][right];
	int ans=1e9;
	for(int i=left+1;i<=right-1;i++)
		ans=min(ans,DP(left,i)+DP(i,right));
T[left][right]=ans+A[right]-A[left];
	return T[left][right];
}

int main()
{
	scanf("%d",&l);
	
	while(l)
	{
		scanf("%d",&n);
		A[0]=0;
		A[n+1]=l;
		for(int i=1;i<=n;i++)scanf("%d",&A[i]);
		memset(T,-1,sizeof T);
		printf("The minimum cutting is %d.\n",DP(0,n+1));
		scanf("%d",&l);
	}
	return 0;
}
