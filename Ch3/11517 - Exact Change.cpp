#include<bits/stdc++.h>
using namespace std;
int price,n;
int C[105];
pair<int,int> T[105][10005];
pair<int,int>  DP(int i, int amount)
{
	
	if(amount>=price)return make_pair(0,0);
	if(i==n)return make_pair(1e9,1e9);
	
	
	if(T[i][amount]!=make_pair(-1,-1))return T[i][amount];
	pair<int,int> a=DP(i+1,amount+C[i]);
	pair<int,int> b=DP(i+1,amount);
	a.second++;
	a.first+=C[i];
	T[i][amount]=min(a,b);
	return T[i][amount];
	
}
int main()
{
	int K,mm;
	scanf("%d",&K);
	while(K--)
	{
		memset(T,-1,sizeof T);
		scanf("%d%d",&price,&n);
	//		cout<<price<<endl;
		for(int i=0;i<n;i++)scanf("%d",&C[i]);	
		pair<int,int> ans=DP(0,0);
	
		printf("%d %d\n",ans.first,ans.second);
	}

	return 0;
}
