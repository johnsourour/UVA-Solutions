#include<bits/stdc++.h>
using namespace std;
char qwerty[128] = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>? ";
char dvorak[128]   = "`123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg'~!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\" ";
map<char,char> mp;
void gen()
{
	for(int i=0;i<128;i++)mp.insert(make_pair(qwerty[i],dvorak[i]));
}

int main()
{
	gen();
	string s;
	while(getline(cin,s))
	{
		for(char c:s)
		cout<<mp[c];
		cout<<endl;
	}
}
