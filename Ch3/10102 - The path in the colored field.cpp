#include <bits/stdc++.h>
using namespace std;

int main() {
	int M,t,mn,mx;
	vector<pair<int,int> > ones;
	vector<pair<int,int> > threes;
	char r[INT_MAX];
	while(scanf("%d",&M)!=EOF)
	{
		ones.clear();
		threes.clear();
		for(int i=0;i<M;i++)
		{
			scanf("%s",&r[0],sizeof r);
			for(int j=0;j<M;j++)
			{
				t=r[j]-'0';
				if(t==1)ones.push_back(make_pair(i,j));
				if(t==3)threes.push_back(make_pair(i,j));
			}
		}
	
		mx=-1e9;
		int dist;
		for(pair<int,int> i:ones)
		{	mn=1e9;
			for(pair<int,int> j:threes)
			{
				dist=(abs(j.first-i.first)+abs(j.second-i.second));
				mn=min(mn,dist);
			}
			mx=max(mx,mn);
		}
		printf("%d\n",mx);
		
	}
	return 0;
}
