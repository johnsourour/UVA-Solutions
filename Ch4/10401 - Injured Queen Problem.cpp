#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dist[15][15];

int main()
{
	char c[20],cur;
	int n,prev;
	string s;
	ll ans;
	bool all,valid;
	while(scanf("%s",&c[0],sizeof c)!=EOF)
	{
		s=c;
		n=s.length();
		prev=1e9;
		all=false;
		valid=true;
		if(s.at(0)=='?')
			for(int i=0;i<n;i++)dist[i][0]=1;
		else
		{
			for(int i=0;i<n;i++)dist[i][0]=0;
			if(s.at(0)>='1'&& s.at(0)<='9')
			{
				dist[s.at(0)-'1'][0]=1;
				prev=s.at(0)-'1';
			}
			else 
			{
				dist[s.at(0)-'A'+9][0]=1;
				prev=s.at(0)-'A'+9;
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=1;j<n;j++)dist[i][j]=0;
		}
		for(int j=1;j<n;j++)
		{
			cur=s.at(j);
			if(cur=='?')
			{
				for(int k=0;k<n;k++)
				for(int l=0;l<n;l++)
				{
					if(abs(l-k)>1)
					dist[l][j]+=dist[k][j-1];
				}
				
				prev=1e9;
			}
			else if(cur>='1'&& cur<='9')
			{
			
				if(abs(cur-'1'-prev)<=1)
				{
				
					valid=false;
					break;
				}
				
				prev=cur-'1';
				for(int k=0;k<n;k++)
				if(abs(cur-'1'-k)>1)
				{
					dist[cur-'1'][j]+=dist[k][j-1];
				}
			}
			else{
				if(abs(cur-'A'+9-prev)<=1){
					valid=false;
					break;
				}
				prev=cur-'A'+9;
				for(int k=0;k<n;k++)
				if(abs(cur-'A'+9-k)>1)
					dist[cur-'A'+9][j]+=dist[k][j-1];
			}
		
		}
		ans=0;
		if(valid)	for(int i=0;i<n;i++)ans+=dist[i][n-1];
		printf("%lld\n",ans);
	}
	
	return 0;
}
