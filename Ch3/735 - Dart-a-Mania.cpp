#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int>V;
	set<vector<int> >avail;
	set<int> ss;
	string p="";
	int s,perm,comb;
	for(int i=0;i<21;i++)
	{
		if(!ss.count(i)){V.push_back(i);ss.insert(i);}
		if(!ss.count(2*i)){V.push_back(2*i);ss.insert(2*i);}
		if(!ss.count(3*i)){V.push_back(3*i);ss.insert(3*i);}
	}
	for(int i=0;i<70;i++)p+='*';
	V.push_back(50);
	scanf("%d",&s);
	while(s>0)
	{
		comb=0;
		perm=0;
		avail.clear();
		for(int i=0;i<V.size();i++)
		{
			for(int j=0;j<V.size();j++)
			{	
				for(int k=0;k<V.size();k++)
				{
					if(s==V[i]+V[j]+V[k])
					{
						perm++;
						vector<int> temp={V[i],V[j],V[k]};
						sort(temp.begin(),temp.end());
						if(!avail.count(temp)){
							avail.insert(temp);
							comb++;
						}
					}
				}
			}
		}
		if(perm>0)
		{
			printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n",s,comb);
			printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n",s,perm);
		}
		else 
		printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n",s);
		
		scanf("%d",&s);
		printf("%s\n",p.c_str());
	}
	printf("END OF OUTPUT\n");
	return 0;
}
