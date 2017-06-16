#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,k,t,h,l;
	long long total;
	multiset<int> urn;
	multiset<int>::iterator it;
	scanf("%d",&n);
	while(n)
	{
		total=0;
		urn.clear();
		for(int i=0;i<n;i++)
		{
			scanf("%d",&k);
			while(k--)
			{
				scanf("%d",&t);
				urn.insert(t);
			}
			h=*urn.rbegin();
			l=*urn.begin();
			it=urn.end();
			it--;
			urn.erase(it);
			urn.erase(urn.begin());
			total+=(h-l);
		}
		
		printf("%lld\n",total);
		scanf("%d",&n);
	}
	return 0;
}
