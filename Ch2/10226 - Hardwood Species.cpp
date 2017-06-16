#include <bits/stdc++.h>
using namespace std;

int main() {
	map<string,int> trees;
	double n,res;
	int K;
	string s;
	getline(cin,s);
	K=stoi(s);
	getline(cin,s);
	while(K--)
	{
		n=0;
		trees.clear();
		getline(cin,s);
		while(!cin.eof() && s!="")
		{
			if(trees.find(s)==trees.end())
			{
				trees.insert(make_pair(s,1));
			
			}
			else trees[s]++;
			getline(cin,s);
			
			n++;
		}
		for(map<string,int>::iterator i=trees.begin();i!=trees.end();i++)
		{
			res=(double)(i->second*100)/(double)n;
		cout<<i->first<<" "<<fixed<<setprecision(4)<<res<<endl;
		}
	    if(K!=0)cout<<endl;
	}
	return 0;
}
