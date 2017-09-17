#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX INT_MAX
vector<ll> in,fib;
map<ll,int> mp;
vector<bool> v;
vector<char> out;

void gen()
{
	int cur=0;
	fib.push_back(1);
	mp[1]=cur++;
	fib.push_back(2);
	mp[2]=cur++;
	ll nxt;
	while(true)
	{
		nxt=fib[cur-1]+fib[cur-2];
		if(nxt>=MAX)break;
		fib.push_back((int)nxt);
		mp[(int)nxt]=cur++;	
	}
	v.resize(fib.size());
}
int main()
{
	int T,n;
	cin>>T;
	gen();
	string txt,num;
	while(T--)
	{
		cin>>n;
		in.clear();
		in.resize(n);
		v.clear();
		v.resize(fib.size());
		
		for(int i=0;i<n;i++)cin>>in[i];
		getline(cin,txt);
		getline(cin,txt);
		int i=0,nn=n;
		
		out.clear();
		out.resize(v.size());
		for(char c:txt)
		{
			if(isupper(c))
			{
				//cout<<c<<" "<<mp[in[i]]<<endl;
				out[mp[in[i]]]=c;
				v[mp[in[i]]]=true;
				n=max(n,mp[in[i]]+1);
				i++;
			}
			if(i==nn)break;
		}
		for(int i=0;i<n;i++)
		{
			if(!v[i]){
			cout<<" ";	
				
			}
			else 
			{
				cout<<out[i];
			}
		}
		cout<<endl;
		
	}
}
