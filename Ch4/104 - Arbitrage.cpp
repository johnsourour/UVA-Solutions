#include<bits/stdc++.h>
using namespace std;
double adjMat[21][21][21];
int p[21][21][21];
void printPath(int i, int j, int s) {
	if (s<=0) 
		printf("%d %d",i+1,j+1);
	else
	{
		printPath(i,p[i][j][s],s-1);
		printf(" %d",j+1);
	
	}
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		memset(adjMat, 0.0,sizeof adjMat);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				if(i!=j)
				{
					scanf("%lf",&adjMat[i][j][0]);
				}
				else
				adjMat[i][j][0]=1.0;
			
			}
	bool found=false;
	int ind,st;
		for(int s=1;s<n && !found;s++){
			for (int k = 0; k < n && !found; k++){
				for (int i = 0; i < n && !found; i++){
					for (int j = 0; j < n && !found; j++){
						if ((adjMat[i][k][s-1] * adjMat[k][j][0]) > adjMat[i][j][s]) 
						{
							adjMat[i][j][s] = adjMat[i][k][s-1] * adjMat[k][j][0];
							p[i][j][s] = k ;
							if(i==j && adjMat[i][j][s]>1.01)
							{
								found=true;
								st=s;
								ind=i;
							}
						}
						
					}
				}
			}
		}
		if(found)
		{
	
		printPath(ind,ind,st);
		cout<<endl;
		}
		else cout<<"no arbitrage sequence exists"<<endl;
		
	}
	
}
