#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,cn,freqs,mx;
	long long s;
	scanf("%d",&n);
	vector<int> ss;
	map<long long,int> courses;
	while(n)
	{
		courses.clear();
		mx=0;
		for(int i=0;i<n;i++)
		{
			s=0;
			ss.clear();
			for(int j=0;j<5;j++)
			{
				scanf("%d",&cn);
				ss.push_back(cn);
				
			}
			sort(ss.begin(),ss.end());
			for(int i:ss)
			{
				s+=i;
				s*=1000;
			}
			//cout<<s<<endl;
			if(courses.find(s)==courses.end())
				courses.insert(make_pair(s,1));
			else {courses[s]++;}
				mx=max(mx,courses[s]);
		}
		freqs=0;
		
		for(map<long long,int>::iterator i=courses.begin();i!=courses.end();i++)
		{
			if(i->second == mx)freqs+=i->second;
		}
		printf("%d\n",freqs);
	
	
		scanf("%d",&n);	
	}
	return 0;
}
