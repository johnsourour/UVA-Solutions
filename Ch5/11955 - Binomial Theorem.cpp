#include<bits/stdc++.h>
using namespace std;
#define MAX 51
typedef long long ll;
typedef vector<ll> vi;
vector<vi> biCoef;
void init()
{
	biCoef.resize(MAX);
	for(int i=0;i<MAX;i++)
	{
		biCoef[i].resize(i+1);
		for(int j=0;j<=i;j++)
		{
			if(j==0 || j==i)biCoef[i][j]=1;
			else
			{
				biCoef[i][j]=biCoef[i-1][j]+biCoef[i-1][j-1];
			}
		}
	}
}
void print(int n)
{
	for(int i=45;i<MAX;i++)
	{
		for(ll k:biCoef[i])cout<<k<<" ";
		cout<<endl;
	}
}
int main()
{
	init();
//	print(10);
	string s,var1,var2;
	int N,T,K=1;
	scanf("%d",&T);
	while(T--)
	{
		cin>>s;
		s.erase(0,1);
		var1=var2="";
		bool v=false,v2=false;
		while(s.length()>0)
		{
			char c=s.at(0);
			if(isalpha(c))
			{
				if(!v)var1+=c;
				else var2+=c;
			
			}
			else
			{
				if(!v)v=true;
			
				else 
				{
					s.erase(0,2);
					N=stoi(s);
					break;
				}
			}
			if(s.length()>0)s.erase(0,1);
			
		}
		printf("Case %d: ",K++);
		int f=N-1,l=1;
		printf("%s",var1.c_str());
		if(N>1)printf("^%d",N);
		for(int i=1;i<biCoef[N].size();i++)
		{
			ll ii=biCoef[N][i];
			printf("+");
			if(ii>1)printf("%lld*",ii);
			if(f)
			{
				printf("%s",var1.c_str());
				if(f>1)printf("^%d",f);
				if(l)printf("*");
			}
			if(l)
			{
				printf("%s",var2.c_str());
				if(l>1)printf("^%d",l);
			}
			
			
			l++;f--;
		}
		printf("\n");
	}
	return 0;
}
