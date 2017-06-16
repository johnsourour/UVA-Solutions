#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N,M,t;
	vector<int> books;
	while(scanf("%d",&N)!=EOF)
	{
		books.clear();
		for(int i=0;i<N;i++)
		{
			scanf("%d",&t);
			books.push_back(t);
		}
		sort(books.begin(),books.end());
		int cur=1e9,ansi,ansj;
		scanf("%d",&M);
		vector<int>::iterator tmp;
		for(int i=0;i<N;i++)
		{
			int b=books[i];
			
			tmp=lower_bound(books.begin(),books.end(),M-b); 
		
			if(*tmp+b==M && i!=tmp-books.begin())
			{
			
				if(abs(*tmp-b)<cur)
				{
					cur=abs(*tmp-b);
					ansi=b;
					ansj=*tmp;
				}
			
			}
		}
		printf("Peter should buy books whose prices are %d and %d.\n\n",ansi,ansj);
		
	}
	return 0;
}
	
