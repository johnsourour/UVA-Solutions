#include<bits/stdc++.h>
using namespace std;
typedef pair<char,int> ci;
int adjMat1[4][4];
bool adjMat2[4][4];
map<char,int> m;
char sym[4]={'V','U','C','D'};
void gen()
{
	for(int i=0;i<4;i++)
		m.insert(ci(sym[i],i));
	memset(adjMat2, false, sizeof adjMat2);
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			adjMat1[i][j]=(i+j)%4;
			if(i+j>=4)adjMat2[i][j]=true;
		}
	}
}
void calculate(string num1, string &num2, char op)
{
	if(op=='N')return;
	else if(op=='L')
	{
		num2+='V';
	}
	else if(op=='R')
	{
		num2.erase(num2.length()-1,1);
		string tmp="V";
		tmp+=num2;
		num2=tmp;
	}
	else
	{
		string tmp="";
		int f,s;
		int cin=0,cur;
		reverse(num2.begin(),num2.end());
		reverse(num1.begin(),num1.end());
		for(int i=0;i<num2.length();i++)
		{
			if(i>=num1.length())f=0;
			else f=m[num1.at(i)];
			s=m[num2.at(i)];
			if(cin)
			{
				cur=1;
				int nc=0;
				while(cin>1)
				{
					nc+=adjMat2[1][cur];
					cur=adjMat1[1][cur];
				}
			
				cur=adjMat1[1][f];
				nc+=adjMat2[1][f];
				nc+=adjMat2[s][cur];
				cur=adjMat1[s][cur];
				tmp+=sym[cur];
				cin=nc;
			}
			else
			{
				cur=adjMat1[s][f];
				cin=adjMat2[s][f];
				tmp+=sym[cur];
			}
			
		}
		if(cin)
		{
			cur=1;
			cin--;
			while(cin)
			{
				cin+=adjMat2[cur][1];
				cur=adjMat1[cur][1];
				tmp+=sym[cur];
				cin--;
				
			}
			tmp+=sym[cur];
		}
		reverse(tmp.begin(),tmp.end());
		num2=tmp;
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	gen();
	string num1,num2,res;
	char c[10],op;
	printf("COWCULATIONS OUTPUT\n");
	while(T--)
	{
		scanf("%s",&c[0],sizeof c);
		num1=c;
		scanf("%s",&c[0],sizeof c);
		num2=c;
		for(int i=0;i<3;i++)
		{
			scanf(" %c",&op);
			calculate(num1,num2,op);
		}
		if(num2.length()<8)
		{
			reverse(num2.begin(),num2.end());
			while(num2.length()<8)num2+='V';
				reverse(num2.begin(),num2.end());
		}
	
		scanf("%s",&c[0],sizeof c);
		res=c;
		if(res.compare(num2)==0)printf("YES\n");
		else printf("NO\n");
		
	}
	printf("END OF OUTPUT\n");
}
