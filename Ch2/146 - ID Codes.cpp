#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	getline(cin,s);
	while(s!="#")
	{
		if(next_permutation(s.begin(),s.end()))
			printf("%s\n",s.c_str());
		else 
			printf("No Successor\n");
			
		getline(cin,s);
	}
	return 0;
}
