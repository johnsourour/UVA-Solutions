#include<bits/stdc++.h>
using namespace std;
int N;
int B[1001][2];
int T[1001][3001];
int DP(int count, int load)
{
	if(load<0)return -1e9;
	if(count==N)return 0;
	int &v=T[count][load];
	if(v==-1)
	{
		v=max(max(0,DP(count+1,load)),1+DP(count+1,min(load-B[count][0],B[count][1])));
	}
	return v;
}
int main()
{
	scanf("%d",&N);
	while(N)
	{
		memset(T,-1,sizeof T);
		for(int i=0;i<N;i++)scanf("%d%d",&B[i][0],&B[i][1]);
		int ans=0;
		for(int i=0;i<N;i++)
		{
			ans=max(ans,1+DP(i+1,B[i][1]));
		}
		printf("%d\n",ans);
		scanf("%d",&N);
		
	}
	return 0;
}
