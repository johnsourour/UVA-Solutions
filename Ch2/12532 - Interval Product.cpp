#include<bits/stdc++.h>
using namespace std;
vector<int> ft,ft1;//n+1 assigned to 0
int n;
int LSOne(int b)
{
	return b & (-b);
}
int rsq(int b,int t)
{
	int sum=0;
	while(b>0)
	{
		if(t==0)sum+=ft[b];
		else sum+=ft1[b];
		b-=LSOne(b);
	}
	return sum;
}
int rsq(int a, int b,int t)
{
	return (rsq(b,t) - (a == 1 ? 0 : rsq(a - 1,t)));
}
void adjust(int k, int v, int t)
{
	while(k<n+1)
	{
		if(t==0)ft[k]+=v;
		else ft1[k]+=v;
		k+=LSOne(k);
	}
}
int main()
{
	vector<int> d;
	int K,t,a,b;
	char c;
	while(scanf("%d%d",&n,&K)!=EOF)
	{
		d.clear();
		for(int i=0;i<n;i++)
		{
	
			scanf("%d",&t);
			d.push_back(t);
		}
		ft.clear();
		ft.resize(n+1);
		ft1.clear();
		ft1.resize(n+1);	
		for(int i=0;i<d.size();i++){
		if(d[i]<0)adjust(i+1,1,1);
		if(d[i]==0)adjust(i+1,1,0);
		
		}
		while(K--)
		{
			scanf(" %c%d%d",&c,&a,&b);
			if(c=='C')
			{
				if(b<0)
				{
					if((d[a-1])>=0)adjust(a,1,1);
					if((d[a-1])==0)adjust(a,-1,0);
						
				}
				else if(b==0)
				{
					if((d[a-1])!=0)adjust(a,1,0);
					if((d[a-1])<0)adjust(a,-1,1);
				}
				else
				{
					if((d[a-1])<0)adjust(a,-1,1);

					if((d[a-1])==0)adjust(a,-1,0);
				}
					
				d[a-1]=b;
			}
			else
			{
				int R1,R;
				R=rsq(a,b,0);
				R1=rsq(a,b,1);
				if(R>0)printf("%c",'0');
				else if(R1%2==1)printf("%c",'-');
				else printf("%c",'+');
			}
		}
		printf("\n");
	}
	
	
	return 0;
}
	
