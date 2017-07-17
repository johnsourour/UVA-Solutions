#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> coef;
ll evaluate(int x)
{
	ll tot=0,cur=1,n=1;
	for(int i=coef.size()-2;i>=0;i--)
	{
		tot+=coef[i]*cur*n;
		cur*=x;
		n++;
	}
	return tot;
}
int main()
{
	string s,tmp;
	int val,var;
	char c;
	while(getline(cin,s))
	{
		coef.clear();
		var=stoi(s);
	
		getline(cin,s);
		istringstream in2(s);
		while(in2>>val)coef.push_back(val);
		
		printf("%lld\n",evaluate(var));
		
	}
}
