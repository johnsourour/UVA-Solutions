#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m,t,cl,K=1;
	vector<int> A;
	scanf("%d",&n);
	while(n)
	{
		A.clear();
		printf("Case %d:\n",K);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&t);
			A.push_back(t);
		}
		scanf("%d",&m);
		while(m--)
		{
			cl=1e9;
			scanf("%d",&t);
			for(int i=0;i<n-1;i++)
			{
				for(int j=i+1;j<n;j++)
				{
					if(abs(t-(A[i]+A[j]))<abs(t-cl)){
						cl=A[i]+A[j];
					}
				}
			}
			printf("Closest sum to %d is %d.\n",t,cl);
		}
		K++;
		scanf("%d",&n);
	}
	return 0;
}
