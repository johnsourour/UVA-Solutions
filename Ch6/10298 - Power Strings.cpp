#include <bits/stdc++.h>
using namespace std;
#define MAX_N 2000010
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
		i++; j++; 
		if (j == m) { 
			cnt++;
			j = b[j]; 
		}
	}
}
int main() 
{
   while(scanf("%s",&P[0],sizeof P)!=EOF)
   {
   	string s=P;
   	cnt=0;
   	if(s==".")break;
   	m=s.length();
   	string ss=s+s;
   	n=ss.length();
   	for(int i=0;i<n;i++)T[i]=ss[i];
   	memset(b,0,sizeof b);
   	kmpPreprocess();
	kmpSearch();
   	cout<<cnt-1<<endl;
   }
}
