#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	string s1,s2;
	ll a,b,diff;
	while(cin>>s2)
	{
		sort(s2.begin(),s2.end());
		s1=s2;
		reverse(s2.begin(),s2.end());
		if(s1.at(0)=='0')
		{
			for(int i=1;i<s1.length();i++)if(s1.at(i)!='0')
			{
				swap(s1.at(0),s1.at(i));
				break;
			}
		}
		a=stoll(s1);
		b=stoll(s2);
		if(a<b)swap(a,b);
		diff=a-b;
		printf("%lld - %lld = %lld = 9 * %lld\n",a,b,diff,diff/9);
		
	}
}
