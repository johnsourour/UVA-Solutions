#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
int adjMatY[28][28],adjMatO[28][28];
int main()
{
	int N,w;
	char I,M,age,type,s,e;
	scanf("%d",&N);
	while(N)
	{
		for(int i=0;i<28;i++)
			for(int j=0;j<28;j++)
			{
				if(i!=j)adjMatY[i][j]=adjMatO[i][j]=INF;
				else adjMatY[i][j]=adjMatO[i][j]=0;
			}
	
		for(int i=0;i<N;i++)
		{
			scanf(" %c %c %c %c %d",&age,&type,&s,&e,&w);
		//	cout<<age<<type<<s<<e<<w<<endl;
			if(s==e)continue;
			if(age=='Y')
			{
				if(type=='B')adjMatY[e-'A'][s-'A']=w;
				adjMatY[s-'A'][e-'A']=w;
			}
			else
			{
				if(type=='B')adjMatO[e-'A'][s-'A']=w;
				adjMatO[s-'A'][e-'A']=w;
			}
		}
			for (int k = 0; k < 28; k++) 
				for (int i = 0; i < 28; i++)
					for (int j = 0; j < 28; j++)
						{
							adjMatY[i][j] = min(adjMatY[i][j], adjMatY[i][k] + adjMatY[k][j]);
							adjMatO[i][j] = min(adjMatO[i][j], adjMatO[i][k] + adjMatO[k][j]);
						}
							scanf(" %c %c",&I,&M);
	
		{
			bool flag=false;
			int mn;
			vector<int> places;
			mn=1e9;
			for (int k = 0; k < 28; k++) 
			{
				if(adjMatY[I-'A'][k]!=INF && adjMatO[M-'A'][k]!=INF)
				{
					if(adjMatY[I-'A'][k]+ adjMatO[M-'A'][k]<mn)
					{
						mn=adjMatY[I-'A'][k]+ adjMatO[M-'A'][k];
						places.clear();
						places.push_back(k);
					}
					else if(adjMatY[I-'A'][k]+ adjMatO[M-'A'][k]==mn)
					{
						places.push_back(k);
					}
					flag=true;
				}
			}
			if(!flag)printf("You will never meet.\n");
			else 
			{
				printf("%d",mn);
				sort(places.begin(),places.end());
				for(int i:places)printf(" %c",'A'+i);
				printf("\n");
			}
		}
		scanf("%d",&N);
	}
	return 0;
	
}
