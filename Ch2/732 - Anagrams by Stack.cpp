#include <bits/stdc++.h>
using namespace std;
vector<char> word;
void printout(vector<char> s)
{
	int i=0;
	for(char c:s)
	{
	    if(i!=0)printf(" ");
		printf("%c",c);
		
		i++;
	}
	printf("\n");
}
void anag(stack<char> S, vector<char> out,int i,string target, string current, bool push)
{
	if(i>word.size() || target.length()<current.length() || current!=target.substr(0,current.length()))return;
	if(!push &&!S.empty()){current+=S.top();S.pop();out.push_back('o');}
	else if(!push)return;
	else{S.push(word[i]);i++;out.push_back('i');}
	
	if(target==current)printout(out);
	else
	{
	anag(S,out,i,target,current,true);
	anag(S,out,i,target,current,false);
	}
	
}
int main() {
	string s,t;
	stack<char> st;
	vector<char> out;
	char ss[100],tt[100];
   while(scanf("%s",&ss[0],sizeof ss)!=EOF)
   {
   		scanf("%s",&tt[0],sizeof tt);
   		t=tt;
   		s=ss;
   		word.clear();
		for(int i=0;i<s.length();i++)word.push_back(s.at(i));
		printf("[\n");
		anag(st,out,0,t,"",true);
		printf("]\n");
   }
	
	return 0;
}
