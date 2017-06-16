#include<bits/stdc++.h>
using namespace std;
int r,c,K;
bool cur;
vector<vector<int> >VD;
void scanB(int x1,int x2, int y1, int y2)
{
	if(x1>=c || x2>=c || y2>=r || y1>=r ||x1>x2 || y1>y2)return;
	int si=x1;
	int	sj=y1;
	bool zero=false,one=false;
	while (sj <= y2 && (!zero || !one))
	{
		si = x1;
		while (si <= x2)
		{
			if (VD[sj][si] == 0)zero = true;
			else one = true;
			si++;
		}
		sj++;
	}
	if(K==50){printf("\n");K=0;}
	if(zero && !one){
		printf("0");
		K++;
	return;}
	else if(one && !zero){
		printf("1");
		K++;
		return;}
		
	printf("D");
	K++;
	int midx=(x1+x2)/2;
	int midy=(y1+y2)/2;
	scanB(x1,midx,y1,midy);
	scanB(midx+1,x2,y1,midy);
	scanB(x1,midx,midy+1,y2);
	scanB(midx+1,x2,midy+1,y2);
	
}
void scanD(int x1,int x2, int y1, int y2)
{
	if(x1>=c || x2>=c || y2>=r || y1>=r ||x1>x2 || y1>y2)return;
	char cc;	do{
			scanf("%c",&cc);
			}while(cc=='\n');
	if(cc=='1')
	{ 
		for(int i=y1;i<=y2;i++)
		{
			for(int j=x1;j<=x2;j++)
			{
			
				VD[i][j]=1;
			}
		}
		return;
	}
	else if(cc=='D')
	{
		int midx=(x1+x2)/2;
	int midy=(y1+y2)/2;
	scanD(x1,midx,y1,midy);
	scanD(midx+1,x2,y1,midy);
	scanD(x1,midx,midy+1,y2);
	scanD(midx+1,x2,midy+1,y2);
	}
	else 
	return;
	
}
int main()
{
int cnt;
	char in,tmp;
	scanf(" %c",&in);
	while(in!='#')
	{
		scanf("%d%d",&r,&c);
		VD.clear();
		cur=false;
		K=0;
		VD.resize(r);
		if(in=='B'){
		printf("D%4d%4d\n",r,c);
			int cnt = 0;
			for (int i = 0; i<r; i++)
			for (int j = 0; j < c; j++)
			{
			do{
			scanf("%c",&tmp);
			}while(tmp=='\n');
			
				if(tmp=='0')VD[i].push_back(0);
				else VD[i].push_back(1);
				cnt++;
			}
		scanB(0,c-1,0,r-1);
		
		if(K)printf("\n");
		}
		else 
		{
		for(int k=0;k<r;k++)VD[k].resize(c);
		printf("B%4d%4d\n",r,c);
		scanD(0,c-1,0,r-1);
		cnt=0;
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
			printf("%d",VD[i][j]);
			cnt++;
			if(cnt==50){printf("\n");cnt=0;};
				
			}
			
		
		}
		if(cnt)printf("\n");
		}
		
		scanf(" %c",&in);
	}
	return 0;
}
