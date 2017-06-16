#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m,s,e,rec,i;
	bool conflict;
	scanf("%d%d",&n,&m);
	bitset<1000001> bs;
	while(n||m)
	{
		bs.reset();
		conflict=false;
		while(n--)
		{
			scanf("%d%d",&s,&e);
			i=s;
			while(i<e && !conflict)
			{
				if(bs[i]==0)
				bs[i]=1;
				else conflict=true;
				i++;
				
			}	
		}
		while(m--)
		{
			scanf("%d%d%d",&s,&e,&rec);
			i=0;
			while(s<1e6 && !conflict)
			{
				i=s;
				while(i<e &&!conflict)
				{
					if(!bs[i])
					bs[i]=1;
					else conflict=true;
					i++;
				}
				s+=rec;
				e=min(e+rec,1000000);
			}
		}
		if(conflict)printf("CONFLICT\n");
		else printf("NO CONFLICT\n");
		
		scanf("%d%d",&n,&m);
	}
	return 0;
}
