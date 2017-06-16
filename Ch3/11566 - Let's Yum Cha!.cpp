#include<bits/stdc++.h>
using namespace std;
int N,x,T,K,tmp;
int P[105],F[105];
int M[205][25][1005];
double DP(int id,int count, int cost)
{
	if(cost<0)return -1e9;
	if(cost==0 || count>=2*N) return 0;
	if(id>=2*K) return 0;
	
	
	if(M[id][count][cost]!=-1) return M[id][count][cost];
	double a=DP(id+1,count+1,cost-P[id%K])+F[id%K];
	double b=DP(id+1,count,cost);
	M[id][count][cost]=max(a,b);
	return M[id][count][cost];
	

}
int main()
{
	scanf("%d%d%d%d",&N,&x,&T,&K);
	while(N || x || T || K)
	{
		N++;
		for(int i=0;i<K;i++)
		{
			scanf("%d",&P[i]);
			int s=0;
			for(int f=0;f<N;f++)
			{
				scanf("%d",&tmp);
				s+=tmp;
			}
			F[i]=s;
		}
		memset(M, -1, sizeof M);
	   int mx = floor(double(x * N) / 1.1 +1e-6) - N * T;
		printf("%.2f\n",DP(0,0,mx)/N);
		
		scanf("%d%d%d%d",&N,&x,&T,&K);		
	}
	
	return 0;
}
