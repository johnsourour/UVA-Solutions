#include <bits/stdc++.h>
using namespace std;
vector<int> p;
vector<int> r;
int n;
void init()
{
	r.clear();
	p.clear();
	r.resize(n);
	p.resize(n);
	for(int i=0;i<=n;i++)p[i]=i;
}
int findSet(int i)
{
	if(p[i]==i)return i;
	else return findSet(p[i]);
}
bool isSameSet(int i,int j)
{
	return findSet(i)==findSet(j);
}
void unionSet(int i, int j)
{
	if(!isSameSet(i,j))
	{
		int x=findSet(i);
		int y=findSet(j);
		if(r[x]>r[y])p[y]=x;
		else {
			p[x]=y;
			if(r[x]==r[y])r[y]++;
		}
	}
}
int main() {

	int C,suc,unsuc,t1,t2;
	char s;
	string ss;
	scanf("%d",&C);
	getline(cin,ss);
	getline(cin,ss);
	while(getline(cin,ss) || C)
	{
		if(ss=="")
		{
			printf("%d,%d\n",suc,unsuc);
			printf("\n");
		
			
		}
		else if(!isalpha(ss[0])){
			n=stoi(ss);
			init();
			suc=0;
			unsuc=0;
			C--;
		}
		else{
			sscanf(ss.c_str()," %c%d%d",&s,&t1,&t2);
			if(s=='c') unionSet(t1,t2);
			else
			{
				if(isSameSet(t1,t2))suc++;
				else unsuc++;
			}
		}
		
	}
	printf("%d,%d\n",suc,unsuc);
	return 0;
}
