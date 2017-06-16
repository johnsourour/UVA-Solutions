#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int S,x,y,mov,mm;
	long long P,NUM,n;
	char c,M[4]={'d','l','u','r'};
	scanf("%d%lld",&S,&P);
	while(P!=0 || S!=0)
	{
 
		x=1+(S/2);
		y=1+(S/2);
 		n=1;
 		while(P>n*n)
 		{
 			x++;
 			y++;
 			n+=2;
 			
 		}
 		NUM=n*n;
 		mm=n-1;
 		mov=0;
 		c=M[mov];
 		while(NUM>P)
 		{
 			if(mm==0)
			{
				mov=(mov+1)%4;
				mm=n-2;
			   	c=M[mov];
			}
			else
			{
				mm--;
			}
			if(c=='u')y++;
			else if(c=='d')y--;
			else if(c=='l')x--;			
			else x++;
			NUM--;
			
 		}
 
		printf("Line = %d, column = %d.\n",y,x);
 
 
		scanf("%d%lld",&S,&P);
	}
	return 0;
}
