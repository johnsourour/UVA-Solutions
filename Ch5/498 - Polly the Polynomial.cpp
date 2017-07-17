#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> coef,var;
ll evaluate(int x)
{
	ll tot=0,cur=1;
	for(int i=coef.size()-1;i>=0;i--)
	{
		tot+=coef[i]*cur;
		cur*=x;
	}
	return tot;
}
int main()
{
	string s,tmp;
	int val;
	char c;
	while(getline(cin,s))
	{
		coef.clear();
		var.clear();
		
	  istringstream in(s);
		while(in>>val)coef.push_back(val);
	
		getline(cin,s);
		istringstream in2(s);
		while(in2>>val)var.push_back(val);
		
    for(int i=0;i<var.size()-1;i++)printf("%lld ",evaluate(var[i]));
		printf("%lld\n",evaluate(var[var.size()-1]));
		
	}
}
