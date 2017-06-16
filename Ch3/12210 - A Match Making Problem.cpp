#include<bits/stdc++.h>
using namespace std;
int main()
{
	int B,S,t,tot,K=1;
	scanf("%d%d",&B,&S);
	vector<int>::iterator it;
	vector<int> bach,spin;
	while(B||S)
	{
		bach.clear();
		bach.resize(B);
		spin.clear();
		spin.resize(S);
		for(int i=0;i<B;i++)
		{
			scanf("%d",&t);	
			bach[i]=t;
		}
		for(int i=0;i<S;i++)
		{
			scanf("%d",&t);	
			spin[i]=t;
		}
		sort(bach.begin(),bach.end(),greater<int>());
		sort(spin.begin(),spin.end(),greater<int>());
		int i=0,cur,s;
		while(i<B)
		{
			cur=bach[i];
			it=lower_bound(spin.begin(),spin.end(),cur);
			s=it-spin.begin();
			if(s>=spin.size()||spin.size()==0)break;
			else {spin.erase(it);}
			i++;
			
		}
		printf("Case %d: ",K);
		if(B<=S)printf("0\n");
		else printf("%d %d\n",abs(B-S),bach[B-1]);
		K++;
		scanf("%d%d",&B,&S);
	}
	return 0;
}
