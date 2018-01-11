#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100010
char P[MAX_N], T[MAX_N];
int b[MAX_N], n,m; 
void kmpPreprocess() 
{ 
	int i = 0, j = -1; b[0] = -1; 
	while (i < n) 
	{
		while (j >= 0 && P[i] != P[j]) j = b[j]; 
		i++; j++; 
		b[i] = j; 
	}
}
int cnt;
void kmpSearch() 
{ 
	int i = 0, j = 0;
	while (i < n) { 
		while (j >= 0 && T[i] != P[j]) j = b[j]; 
		i++;
		j++;
	
	
	}
	cnt=j;

}
int main() 
{
   while(scanf("%s",&T[0],sizeof T)!=EOF)
   {
   	string ss,s=T;
   	ss=s;
   	cnt=0;
   	if(s==".")break;
   	n=m=s.length();
   	reverse(s.begin(),s.end());
   	for(int i=0;i<n;i++)
   	{
   		P[i]=s[i];
   	}
   	memset(b,0,sizeof b);
   	kmpPreprocess();
	kmpSearch();
	ss=s;
	reverse(ss.begin(),ss.end());
	//cout<<ss<<" "<<cnt<<endl;
	s.erase(0,cnt);
   	cout<<ss+s<<endl;
   	
   }
}
