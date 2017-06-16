#include <bits/stdc++.h>
using namespace std;
int l;

queue<pair<int,int> > leftc,rightc;
int simulate(bool start)
{	
	
	int size,k=0;
	while((!leftc.empty() || !rightc.empty()))
	{
		size=l;
		if(start)
		{
			while(!leftc.empty() && size-leftc.front().second>=0)
			{
			
				size-=leftc.front().second;
				leftc.pop();
			}
		}
		else
		{
			while(!rightc.empty() && size-rightc.front().second>=0)
			{
				size-=rightc.front().second;
				rightc.pop();
			}
			
		}
	//	cout<<k<<endl;
		start=!start;
		k++;
	}
	return k;
}
int main() {
	int R,m,i;
	char c[10];
	string s;
	scanf("%d",&R);
	while(R--)
	{
		while(!leftc.empty())leftc.pop();
		while(!rightc.empty())rightc.pop();
		int j=1;
		scanf("%d%d",&l,&m);
		l=100*l;
		for(int h=0;h<m;h++)
		{
			scanf("%d",&i);
			scanf("%s",&c[0],sizeof c);
			s=c;	
			if(s=="left")leftc.push(make_pair(h,i));
			else rightc.push(make_pair(h,i));
			
		}
		
			printf("%d\n",simulate(true));
		
		
	}
	return 0;
}
