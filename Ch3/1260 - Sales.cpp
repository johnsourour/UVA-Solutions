#include <bits/stdc++.h>
using namespace std;

int main() {
	int T,n,g,sum;
	scanf("%d",&T);
	vector<int> A;
	while(T--)
	{
		scanf("%d",&n);
		A.clear();
		for(int i=0;i<n;i++)
		{
			scanf("%d",&g);
			A.push_back(g);
		}
		
		sum=0;
		for(int i=1;i<n;i++)
		{
			for(int j=i-1;j>=0;j--)
			{
				if(A[j]<=A[i])sum++;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
