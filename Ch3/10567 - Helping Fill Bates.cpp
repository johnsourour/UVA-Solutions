#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > states;
int ctoi(char c)
{
	if(c>='a' && c<='z')
		return c-'a';
	else
		return 26+(c-'A');	
}
int main()
{
	char bates[1000005],t[105];
	string b,q;
	bool flag;
	int K;
	scanf("%s",&bates[0],sizeof bates);
	states.resize(52);
	b=bates;
	for(int i=0;i<b.length();i++)
	{
		states[ctoi(b.at(i))].push_back(i+1);
	}
	scanf("%d",&K);
	while(K--)
	{
		scanf("%s",&t[0],sizeof t);
		q=t;
		int cur=0,i=0,mn,mx;
		flag=true;
		while(flag && i<q.length())
		{
			if(states[ctoi(q.at(i))].size()==0)flag=false;
			else
			{
				vector<int>::iterator tmp;
				tmp=upper_bound(states[ctoi(q.at(i))].begin(),states[ctoi(q.at(i))].end(),cur);
				if(*tmp==0 || *tmp<cur)flag=false;
				else cur=*tmp;
			}
			if(i==0)mn=cur-1;
			if(i==q.length()-1)mx=cur-1;
			i++;
		}
		if(!flag)printf("Not matched\n");
		else printf("Matched %d %d\n",mn,mx);
	}
	return 0;
}
	
