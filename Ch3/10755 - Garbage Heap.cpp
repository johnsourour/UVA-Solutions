#include<bits/stdc++.h>
using namespace std;
long long M[20][20][20];
int main()
{	
	int T,A,B,C;
	long long mx,subPara;
	scanf("%d",&T);
	while(T--)
	{
		mx=0;
		scanf("%d%d%d",&A,&B,&C);
		for (int i = 0; i < A; i++) 
			for (int j = 0; j < B; j++) 
				for (int k = 0; k < C; k++){
					scanf("%lld", &M[i][j][k]);
					mx+=M[i][j][k];
					if (i > 0) M[i][j][k] += M[i - 1][j][k]; 
					if (j > 0) M[i][j][k] += M[i][j - 1][k]; 
					if (k > 0) M[i][j][k] += M[i][j][k - 1]; 
					if (i > 0 && j > 0 && k > 0) M[i][j][k] += M[i - 1][j - 1][k - 1]; 
					if (i > 0 && j > 0) M[i][j][k] -= M[i - 1][j - 1][k]; 
					if (i > 0 && k > 0) M[i][j][k] -= M[i - 1][j][k - 1]; 
					if (k > 0 && j > 0) M[i][j][k] -= M[i][j - 1][k - 1]; 
				
				}
				
			for (int i = 0; i < A; i++) for (int j = 0; j < B; j++)for (int c = 0; c < C; c++) 
			for (int k = i; k < A; k++) for (int l = j; l < B; l++) for (int d = c; d < C; d++) { 
			subPara = M[k][l][d]; 
			if (i > 0) subPara -= M[i - 1][l][d]; 
			if (j > 0) subPara -= M[k][j - 1][d]; 
			if (c > 0) subPara -= M[k][l][c - 1]; 
			if (i > 0 && j > 0 && c > 0) subPara -= M[i - 1][j - 1][c - 1]; 
			if (i > 0 && j > 0) subPara += M[i - 1][j - 1][d];
			if (i > 0 && c > 0) subPara += M[i - 1][l][c - 1]; 
			if (j > 0 && c > 0) subPara += M[k][j - 1][c - 1]; 
			if(subPara>mx)mx=subPara;
			}
			printf("%lld\n",mx);
			if(T)printf("\n");
	}
	return 0;
}
