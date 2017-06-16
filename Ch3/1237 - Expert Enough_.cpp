#include <bits/stdc++.h>
using namespace std;
int main() 
{
	vector<pair<string,pair<int,int> > >cars;
	int T,Q,P,D,L,H;
	char name[25];
	scanf("%d",&T);
	while(T--)
	{
		cars.clear();
		scanf("%d",&D);
		while(D--)
		{
			scanf("%s%d%d",&name[0],&L,&H,sizeof name);
			cars.push_back(make_pair(name,make_pair(L,H)));
		}
		scanf("%d",&Q);
		while(Q--)
		{
			scanf("%d",&P);
			int i=0;
			string f;
			bool found=false;
			while(i<cars.size())
			{
				if(cars[i].second.first <= P &&cars[i].second.second >= P)
				{
					if(!found){found=true;f=cars[i].first;}
					else {found=false;break;}
				}
				i++;
			}
			if(!found)printf("UNDETERMINED\n");
			else printf("%s\n",f.c_str());
			
		}
		if(T!=0)printf("\n");
		
	}

	return 0;
}
