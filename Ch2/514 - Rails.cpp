#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,nn,t;
	stack<int>a;
	vector<int>b;
	scanf("%d",&n);
	while(n)
	{
		while(true)
		{
			while(!a.empty())a.pop();
			b.clear();
			scanf("%d",&nn);
			if(nn==0)break;
			b.push_back(nn);
			int k;
			for(int i=1;i<n;i++)
			{
				scanf("%d",&k);
				b.push_back(k);
			}
			int i=0,ii=1;
			bool flag=true;
			while(ii<=b.size())
			{
				a.push(ii);
				while(true){
					if(!a.empty() && a.top()==b[i])
					{
						
						a.pop();
						i++;
					}
					else
					 break;
					
				}
				ii++;
				
			}
 
			if(a.empty())printf("Yes\n");
			else printf("No\n");
 
		}
		printf("\n");
		scanf("%d",&n);
	}
	return 0;
}
