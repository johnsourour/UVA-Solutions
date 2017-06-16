#include<bits/stdc++.h>
using namespace std;
int m,n;
int C[105],F[105];
int T[105][10005];
int DP(int id, int rem)
{
	if(rem < 0 && m < 1800)
        return -1e9;
    if(rem < -200)
        return -1e9;
    if(id == n) {
        if(rem < 0 && m-rem <= 2000)
            return -1e9;
        return 0;
    }
	
	if(T[id][rem]!=-1)return T[id][rem];
	int a=DP(id+1,rem-C[id])+F[id];
	int b=DP(id+1,rem);
	T[id][rem]=max(a,b);
	return T[id][rem];
}
int main()
{
	while(	scanf("%d%d",&m,&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&C[i],&F[i]);
		}
		memset(T, -1, sizeof T);
		printf("%d\n",DP(0,m));
		
			
	}
	return 0;
}
