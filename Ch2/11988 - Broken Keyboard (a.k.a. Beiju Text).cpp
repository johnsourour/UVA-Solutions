#include <bits/stdc++.h>
using namespace std;

int main() {
	char c;
	string s;
	list<char> l;
	list<char>::iterator i;
	while(getline(cin,s))
	{
		
		l.clear();
		i=l.begin();
		for(int k=0;k<s.length();k++)
		{
			c=s.at(k);
			if(c==']')
				i=l.end();
			else if(c=='[')
				i=l.begin();
			else
			  	l.insert(i,c);
			
		}
		for(char c:l)
		printf("%c",c);
		printf("\n");
	}
	return 0;
}
