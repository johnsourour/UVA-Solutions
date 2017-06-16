#include <bits/stdc++.h>
using namespace std;
vector<stack<char> > vs;
void addCont(char c)
{
	int i=0;
	bool flag=false;
	while(i<vs.size() && !flag)
	{
		if(c-'A'>=vs[i].top()-'A'){vs[i].push(c);flag=true;}
		i++;
	}
	if(!flag)
	{
		stack<char> t;
		t.push(c);
		vs.push_back(t);
	}
}
int main() {
	char c[1005];
	int K=1;
	scanf("%s",&c[0],sizeof c);
	string s;
	s=c;
	while(s!="end")
	{	vs.clear();
		for(int i=s.length()-1;i>=0;i--)
		{
			addCont(s.at(i));
		}
		printf("Case %d: %d\n",K,vs.size());
		scanf("%s",&c[0],sizeof c);
		s=c;
		K++;
	}
	return 0;
}
