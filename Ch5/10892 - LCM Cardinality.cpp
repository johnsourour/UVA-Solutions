#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
int main()
{
	int N,cur,g;
	vector<int> d;
	while(true)
	{
		scanf("%d",&N);
		if(!N)break;
		d.clear();
		int cnt=0;
		for(int i=1;i<=sqrt(N);i++)
		{
			if(N%i==0)
			{
				d.push_back(i);
				if(i!=sqrt(N))d.push_back(N/i);
			}
		}
		for(int i=0;i<d.size();i++)
			for(int j=i+1;j<d.size();j++)
			{
				if(lcm(d[i],d[j])==N)
				{
				//	cout<<d[i]<<" "<<d[j]<<endl;
					cnt++;
				}
			}
		printf("%d %d\n",N,cnt+1);
	}
}
