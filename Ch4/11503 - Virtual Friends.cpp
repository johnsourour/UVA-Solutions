#include <bits/stdc++.h>
using namespace std;
vector<int> p;
vector<int> r;
void init()
{
	r.clear();
	p.clear();
}
void addElement(int i)
{
	p.push_back(i);
	r.push_back(1);
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
		int s=r[y]+r[x];
		if(r[x]>r[y]){
			p[y]=x;
		}
		else {
			p[x]=y;
			
		}
		r[y]=s;
		r[x]=s;
		
	
	}
	
}
int main() {

	int T,k,i;
	map<string,int> fm;
	string f,s;
	scanf("%d",&T);
	char f1[25],f2[25];
	while(T--)
	{
		i=0;
		init();
		fm.clear();
		scanf("%d",&k);
		while(k--)
		{
			scanf("%s",&f1[0],sizeof f1);
			scanf("%s",&f2[0],sizeof f2);
			f=f1;
			s=f2;
			if(fm.find(f)==fm.end()){fm.insert(make_pair(f,i++));addElement(i-1);}
			if(fm.find(s)==fm.end()){fm.insert(make_pair(s,i++));addElement(i-1);}
			unionSet(fm[f],fm[s]);
			printf("%d\n",r[findSet(fm[f])]);
		}
		
	}
	return 0;
}
