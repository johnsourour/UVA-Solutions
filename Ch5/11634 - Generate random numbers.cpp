#include<bits/stdc++.h>
using namespace std;
int f(int x){
	return ((x*x)/100)%10000;
}
int cnt(string in)
{
	bitset<10010> bs;
	int ans=1,cur=stoi(in);
	bs.set(cur);
	while(1)
	{
		cur=f(cur);
	//	cout<<cur<<endl;
		if(bs.test(cur))break;
		else bs.set(cur);
		ans++;
	}
	return ans;
	
}
int main()
{
	string s;
	while(cin>>s && s!="0")
	{
		printf("%d\n",cnt(s));
	}
}
