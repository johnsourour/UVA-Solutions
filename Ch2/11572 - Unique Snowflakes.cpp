#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	long long c,s,usf,mx;
	map<long long,long long>sf;
	vector<long long> in;
	scanf("%d",&n);
	bool flag=true;
	while(n--)
	{
		scanf("%lld",&c);
		sf.clear();
		in.clear();
		usf=0;
		mx=0;
		while(c--)
		{
			scanf("%lld",&s);
			in.push_back(s);
		}
		int i=0;
		while(i<in.size())
		{
			
			if(sf.find(in[i])==sf.end())
			{
				usf++;
				sf.insert(make_pair(in[i],i));
			}
			else {
				mx=max(mx,usf);
				i=sf[in[i]];
				sf.clear();
				usf=0;
				
			}
			
			i++;
		}
		mx=max(mx,usf);
		printf("%lld\n",mx);
	}
	return 0;
}
