#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef pair<double,ii> dii;
vector<dii> seq;
struct comp
{
	bool operator()(const dii &a,const dii &b)
	{
		return a.first<=b.first;
	}
};
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
void generate(int n)
{
	seq.clear();
	seq.push_back(dii(1.0,ii(1,1)));
	for(int i=n;i>1;i--)
	{
		for(int j=n-1;j>0;j--)
		{
			if(gcd(j,i)==1)
			{
			//	cout<<i<<" "<<j<<endl;
				double tmp=(double)j/(double)i;
				seq.push_back(dii(tmp,ii(j,i)));
			}
		}
	}
}
int main()
{
	int n,k;
	
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		generate(n);
		sort(seq.begin(),seq.end(),comp());
	//	for(dii f:seq)cout<<f.first<<" "<<f.second.first<<"/"<<f.second.second<<endl;
	k--;
		printf("%d/%d\n",seq[k].second.first,seq[k].second.second);
	}
}
