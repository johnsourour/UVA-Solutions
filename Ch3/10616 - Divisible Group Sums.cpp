#include<bits/stdc++.h>
using namespace std;
long long A[205],N,Q,M,D,S=1;
int T[205][205][15];
int DP(int id,int cur, int count)
{
	if(count==M){
	
		return cur==0;
	}
	
	if(T[id][cur][count]!=-1)return T[id][cur][count];
	if(id==N)return 0;
	int a=DP(id+1,(cur+A[id])%D,count+1);
	int b=DP(id+1,cur,count);
	return T[id][cur][count]=a+b;
}
int main()
{	
	scanf("%d%d",&N,&Q);
	int qu;
	while(N||Q)
	{
	//	cout<<1<<endl;
		for(int i=0;i<N;i++)
		{
			scanf("%lld",&A[i]);
		}
		printf("SET %d:\n",S++);
		for(int i=0;i<Q;i++)
		{
			memset(T, -1, sizeof T);
			scanf("%d%d",&D,&M);
			printf("QUERY %d: %d\n",i+1,DP(0,0,0));
		}
		
		scanf("%d%d",&N,&Q);	
	}
	return 0;
}
