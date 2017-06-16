#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int mx=0,n,r,cor;
	vector<pair<unsigned short,int> >c;
	vector<pair<unsigned short,int> >p;
	unsigned short sint;
	while(scanf("%d",&n)!=EOF){
		r=pow(2,n);
		mx=0;
		sint=0;
		c.clear();
		p.clear();
		c.resize(r);
		p.resize(r);
		for(int i=0;i<r;i++)
		{
			scanf("%d",&cor);
			p[i]=(make_pair(sint,cor));
			sint++;
		}
		for(int i=0;i<r;i++)
		{
			c[i].first=p[i].first;
			for(int j=0;j<r;j++)
			{
				int cc=(p[i].first ^ p[j].first);
				if((cc & (cc - 1)) == 0 && i!=j)
				{
					c[i].second+=p[j].second;
				}
			}
			mx=max(mx,c[i].second);
		}
		for(int i=0;i<r;i++)
		{
		
			for(int j=0;j<r;j++)
			{
				int cc=(p[i].first ^ p[j].first);
				if((cc & (cc - 1)) == 0 && i!=j)
				{
					mx=max(mx,c[i].second+c[j].second);
				}
			}
			
		}
		printf("%d\n",mx);
	}
	
	return 0;
}
