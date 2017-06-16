#include <bits/stdc++.h>
using namespace std;
int timeN,n,t;

queue<pair<int,int> > leftc,rightc,ferryc;
vector<int> cars;
void simulate(bool start)
{	
	
	
	while((!leftc.empty() || !rightc.empty()))
	{
		int first=1e9;
		if(!leftc.empty())first=leftc.front().second;
		if(!rightc.empty())first=min(first,rightc.front().second);
		timeN=max(timeN,first);
		if(start)
		{
			while(ferryc.size()<n && !leftc.empty() &&leftc.front().second<=timeN)
			{
				ferryc.push(leftc.front());
				leftc.pop();
			}
		}
		else
		{
			while(ferryc.size()<n &&!rightc.empty() && rightc.front().second<=timeN)
			{
				ferryc.push(rightc.front());
				rightc.pop();
			}
			
		}
		timeN+=t;
		start=!start;
		while(!ferryc.empty())
		{
			cars[ferryc.front().first]=timeN;
			ferryc.pop();
		}
	}
}
int main() {
	int R,m,i;
	char c[10];
	string s;
	scanf("%d",&R);
	while(R--)
	{
		while(!ferryc.empty())ferryc.pop();
		while(!leftc.empty())leftc.pop();
		while(!rightc.empty())rightc.pop();
		cars.clear();
		scanf("%d%d%d",&n,&t,&m);
		cars.resize(m);
		for(int h=0;h<m;h++)
		{
			scanf("%d",&i);
			scanf("%s",&c[0],sizeof c);
		
			s=c;
			timeN=0;	
			if(s=="left")leftc.push(make_pair(h,i));
			else rightc.push(make_pair(h,i));
				
		}
		simulate(true);
		for(int i:cars)
		{
			printf("%d\n",i);
		}
		if(R!=0)printf("\n");
		
	}
	return 0;
}
