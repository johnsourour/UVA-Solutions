#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,t,tot,ans;
	scanf("%d%d%d",&n,&m,&t);
	while(n||m||t)
	{
		n-=7;
		m-=7;
		tot=n*m;
		ans=tot/2;
		if(tot%2 && t)
		{
			ans++;
		}
		printf("%d\n",ans);
		scanf("%d%d%d",&n,&m,&t);
	}

}
