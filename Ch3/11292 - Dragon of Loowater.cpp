#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,t,tot;
	scanf("%d%d",&n,&m);
	vector<int>::iterator it;
	vector<int> knights,heads;
	while(n||m)
	{
		heads.clear();
		heads.resize(n);
		knights.clear();
		knights.resize(m);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&t);	
			heads[i]=t;
		}
		for(int i=0;i<m;i++)
		{
			scanf("%d",&t);	
			knights[i]=t;
		}
		sort(knights.begin(),knights.end());
		int i=0,k=0,cur,s;
		tot=0;
		bool doomed=false;
		if(knights[m-1]<heads[n-1] || m<n)doomed=true;
		while(i<n && !doomed)
		{
			cur=heads[i];
			it=lower_bound(knights.begin(),knights.end(),cur);
			s=it-knights.begin();
			if(s>=knights.size())doomed=true;
			else {tot+=knights[s];knights.erase(it);}
			i++;
			
		}
		if(doomed)printf("Loowater is doomed!\n");
		else printf("%d\n",tot);
		
		scanf("%d%d",&n,&m);
	}
	return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,t,tot;
	scanf("%d%d",&n,&m);	
	vector<int> knights,heads;
	while(n||m)
	{
		heads.clear();
		heads.resize(n);
		knights.clear();
		knights.resize(m);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&t);	
			heads[i]=t;
		}
		for(int i=0;i<m;i++)
		{
			scanf("%d",&t);	
			knights[i]=t;
		}
		sort(knights.begin(),knights.end());
		sort(heads.begin(),heads.end());
		int i=0,k=0,cur;
		tot=0;
		bool doomed=false;
		if(knights[m-1]<heads[n-1] || m<n)doomed=true;
		while(i<n && !doomed)
		{
			
			doomed=true;
			k=0;
			cur=heads[i];
			while(k<knights.size() && doomed)
			{
				
				if(knights[k]>=cur){
					doomed=false;
					tot+=knights[k];
					knights.erase(knights.begin()+k);
				}
				k++;
			}
			i++;
			
		}
		if(doomed)printf("Loowater is doomed!\n");
		else printf("%d\n",tot);
		
		scanf("%d%d",&n,&m);
	}
	return 0;
}
*/
