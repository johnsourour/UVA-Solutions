#include<bits/stdc++.h>
using namespace std;
int N,n;
int found(vector<vector<char> > &s, vector<vector<char> > &b)
{
	int c=0;
	bool flag=true;
	for(int i=0;i<N-n+1;i++)
	{
		for(int j=0;j<N-n+1;j++)
		{
			for(int ii=0;ii<n;ii++)
			{
				for(int jj=0;jj<n;jj++)
				{
					 if (b[i + ii][j + jj] != s[ii][jj])
        			{
            			flag=false;
        			}
				}
			}
			
			if(flag)c++;
			else flag=true;
		}
		
	}
	return c;
}
int main()
{
	vector<vector<char> >b;
	vector<vector<char> >s;
	scanf("%d%d",&N,&n);
	while(n||N)
	{
		b.clear();
		s.clear();
		b.resize(N);
		s.resize(n);
		string ss;
		getline(cin,ss);
		for(int i=0;i<N;i++)
		{
			getline(cin,ss);
			for(int j=0;j<N;j++)
			{
			b[i].push_back(ss.at(j));
			}
		}
		for(int i=0;i<n;i++)
		{
			getline(cin,ss);
			for(int j=0;j<n;j++)
			{
			s[i].push_back(ss.at(j));
			}
		}
		
		int i=4;
		while(i--)
		{
			int f=found(s,b);
			if(i==3)printf("%d",f);
			else printf(" %d",f);
			
			for(int r = 0; r < n; r++) {
	  			for(int c = r; c < n; c++) {  
	    			swap(s[r][c], s[c][r]);
	  			}
			}
			for(int r = 0; r < n; r++) {
			    for(int c =0; c < n/2; c++) {
			      swap(s[r][c], s[r][n-c-1]);
			    }
			}
			
		
		}
		
		
		printf("\n");
		scanf("%d%d",&N,&n);
	}
}
