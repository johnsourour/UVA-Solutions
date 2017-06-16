#include<bits/stdc++.h>
using namespace std;
int coins[45][2];
int T[45][301][301];
int m,s;
int DP(int id, int conv, int info)
{
	int mod=(conv*conv)+(info*info);
	if(mod==s)return 0;
	if(mod>s || id==m)return 1e9;
	
	if(T[id][conv][info]!=-1)return T[id][conv][info];

	int a=DP(id+1,conv,info);
	int b=1+DP(id,conv+coins[id][0],info+coins[id][1]);

	T[id][conv][info]=min(a,b);
	return T[id][conv][info];
	
}
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		memset(T, -1, sizeof T);
		scanf("%d%d",&m,&s);
		s*=s;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&coins[i][0],&coins[i][1]);
		}
		int ans = DP(0,0,0);
		if(ans>300)printf("not possible\n");
		else printf("%d\n",ans);
		
		
	}
	return 0;
}
