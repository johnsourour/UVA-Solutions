#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF && n)
	{
		int s=sqrt(n);
		if(s*s==n)printf("yes\n");
		else printf("no\n");
	}
}
