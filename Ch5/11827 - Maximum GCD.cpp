#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int main()
{
	int n,T;
	string s;
	vector<int> num;
	scanf("%d",&T);
	getline(cin,s);
	while(T--)
	{
		num.clear();
		getline(cin,s);
		istringstream iss(s);
		while(iss>>n)num.push_back(n);
		int mx=0;
		for(int i=0;i<num.size();i++)
		{
			for(int j=i+1;j<num.size();j++)
			{
				mx=max(mx,gcd(num[i],num[j]));
			}
		}
		printf("%d\n",mx);
	}
}
