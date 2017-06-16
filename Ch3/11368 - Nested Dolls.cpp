#include<bits/stdc++.h>
using namespace std;
pair<int,int> A[20002];
int L[20002];

struct comp {
    bool operator()(const std::pair<int,int> &a, const std::pair<int,int> &b) {
    	if(a.second==b.second)return a.first<b.first;
        return a.second>b.second;
    }
};


int main()
{
	int t,m,ans;
	scanf("%d",&t);

	while(t--)
	{
		scanf("%d",&m);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&A[i].first,&A[i].second);
			L[i]=1;
		}
		sort(A,A+m,comp());
		
		for(int i=m-1;i>=0;i--)
		{
			if(!L[i])continue;
			for(int j=i-1;j>=0;j--)
			{
				if(A[j].second>A[i].second && A[j].first>A[i].first && L[j]){
					L[j]=0;
					A[i]=A[j];
				}
			}
		}
	//	for(int i=0;i<m;i++)cout<<A[i].first<<" "<<A[i].second<<" "<<L[i]<<endl;
		ans=0;
		for(int i=0;i<m;i++)ans+=L[i];
		cout<<ans<<endl;
		
	
	}
	return 0;
}
