#include<bits/stdc++.h>
using namespace std;

int main()
{	
	int T,t,N,A[2005],I[2005],D[2005],mx,lis,lds;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)
		{
			scanf("%d",&A[i]);
			I[i]=D[i]=1;
		}
	
		mx=0;
		for(int i=N-1;i>=0;i--)
		{
			lis= I[i]+1;
			lds= D[i]+1;
			
			for(int j=i-1;j>=0;j--)
			{
				if(A[i]>A[j])
				{
					I[j]=max(lis,I[j]);
					
				}
				if(A[i]<A[j])
				{
					D[j]=max(lds,D[j]);
				}
				
			}
		}
		for(int i=N-1;i>=0;i--){
		//	cout<<D[i]<<" "<<I[i]<<endl;
			mx=max(mx,I[i]+D[i]-1);
			}
		printf("%d\n",mx);
	}
	
	return 0;
}
