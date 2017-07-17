#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,ans;
	scanf("%d",&n);
	while(n)
	{
		ans=log(n)/log(2);
		printf("%d\n",ans);
		scanf("%d",&n);
	}
}
