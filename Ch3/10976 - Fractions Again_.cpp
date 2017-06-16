#include <bits/stdc++.h>
using namespace std;
int main() 
{
	int k;
	vector<pair<int,int> >sol;
	while(scanf("%d",&k)!=EOF)
	{
		sol.clear();
		for(int i=k+1;i<=2*k;i++)
		{
			if((i*k)%(i-k)==0)sol.push_back(make_pair((i*k)/(i-k),i));
		}
		printf("%d\n",sol.size());
		for(pair<int,int> i:sol)
		{
			printf("1/%d = 1/%d + 1/%d\n",k,i.first,i.second);
		}
	}

	return 0;
}
