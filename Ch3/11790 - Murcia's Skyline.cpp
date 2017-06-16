#include<bits/stdc++.h>
using namespace std;

int main()
{	
	int T,t,N,W[100000],H[100000],I[100000],D[100000],mxI,mxD,lis,lds,C=1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)
		{
			scanf("%d",&H[i]);
		}
		for(int i=0;i<N;i++)
		{
			scanf("%d",&W[i]);
			I[i]=D[i]=W[i];
		}
	
		mxD=mxI=0;
		for(int i=N-1;i>=0;i--)
		{
			lis =I[i];
			lds =D[i];
			
			for(int j=i-1;j>=0;j--)
			{
				if(H[i]>H[j])
				{
					I[j]=max(lis+W[j],I[j]);
					
				}
				if(H[i]<H[j])
				{
					D[j]=max(lds+W[j],D[j]);
				}
				
			}
		}
		
		for(int i=N-1;i>=0;i--){
		//	cout<<D[i]<<" "<<I[i]<<endl;
			mxD=max(mxD,D[i]);
			mxI=max(mxI,I[i]);
			}
			if(mxI>=mxD)
			printf("Case %d. Increasing (%d). Decreasing (%d).",C++,mxI,mxD);
			else
			printf("Case %d. Decreasing (%d). Increasing (%d).",C++,mxD,mxI);
			printf("\n");
	}
	
	return 0;
}
