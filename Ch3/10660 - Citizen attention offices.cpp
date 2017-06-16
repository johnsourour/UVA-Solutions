#include <bits/stdc++.h>
using namespace std;
int main() {
	int t,n,i,j,v,mn,mna,mnb,mnc,mnd,mne,ia,ib,ic,id,ie,mnx,dist;
	scanf("%d",&t);
	vector<pair<int,pair<int,int> > > filled;
	while(t--)
	{
		filled.clear();
		scanf("%d",&n);
		while(n--)
		{
			scanf("%d%d%d",&i,&j,&v);
			filled.push_back(make_pair(v,make_pair(i,j)));
		}
		mn=1e9;
		for(int a=0;a<21;a++)
			for(int b=a+1;b<22;b++)
				for(int c=b+1;c<23;c++)
					for(int d=c+1;d<24;d++)
						for(int e=d+1;e<25;e++)
						{
							dist=0;
							for(pair<int,pair<int,int> > P:filled)
							{
								mna=(abs(P.second.first-(a/5))+abs(P.second.second-(a%5)));
								mnb=(abs(P.second.first-(b/5))+abs(P.second.second-(b%5)));
								mnc=(abs(P.second.first-(c/5))+abs(P.second.second-(c%5)));
								mnd=(abs(P.second.first-(d/5))+abs(P.second.second-(d%5)));
								mne=(abs(P.second.first-(e/5))+abs(P.second.second-(e%5)));
								mnx=min(mna,min(mnb,min(mnc,min(mnd,mne))));
								dist+=(P.first*mnx);
								
								}
								if(mn>dist)
								{
								mn=dist;
								ia=a;
								ib=b;
								ic=c;
								id=d;
								ie=e;
								
							}
							
						
						}
						printf("%d %d %d %d %d\n",ia,ib,ic,id,ie);
						
	}
	return 0;
}
