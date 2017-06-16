#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T,N,K=1,D,t,cur,cnt,mx,tmp;
	char type;
	vector<pair<int,int> > stones;
	vector<bool> hit;
	scanf("%d",&T);
	while(T--)
	{
		
		scanf("%d%d",&N,&D);
		stones.clear();
		stones.resize(N);
		hit.clear();
		hit.resize(N);
		for(int i=0;i<N;i++)
		{
			scanf(" %c-%d",&type,&t);
		
			if(type=='B')stones[i]=make_pair(1,t);
			else stones[i]=make_pair(0,t);
		}
		cur=tmp=mx=cnt=0;
		if(stones.size()==0)stones.push_back(make_pair(1,D));
		for(int i=0;i<stones.size();i++)
		{
			tmp=stones[i].second;
			int l=tmp-cur;
			if(stones[i].first==0)
			{
				cnt++;
				if(cnt<=1)
				{
					stones.erase(stones.begin()+i);
					i--;
					cur=tmp;
					
				}
				else 
				{
					cnt=0;
				}
			}
			else cur=tmp;
			if(l>mx)mx=l;
		
		
			
		}
		if(D-cur>mx)mx=D-cur;
		cur=0;
		if(stones.size()==0)stones.push_back(make_pair(1,D));
		for(int i=0;i<stones.size();i++)
		{
			tmp=stones[i].second;
			if(tmp-cur>mx)mx=tmp-cur;
			cur=tmp;
		}
		if(D-cur>mx)mx=D-cur;
		printf("Case %d: %d\n",K,mx);
		K++;
	}
	return 0;
}
