#include<bits/stdc++.h>
using namespace std;
#define MAX 10000.0F
#define EPS 1e-4
struct Command{
	int type;//Fuel 0, Leak 1, Mechanic 2, Gas 3, Goal 4
	int start;
	double fuel;
	
};
vector<Command> obs; 
bool can(double c){
	double left=c, cur,dist, leak=0;
	bool ok = true;
	for(int i=0;i<(obs.size())-1 && ok;i++){
		dist = obs[i+1].start - obs[i].start;
		if(obs[i].type==1)leak++;
		else if(obs[i].type==2)leak=0;
		else if(obs[i].type==3)left=c;
		
		cur = (obs[i].fuel / 100.0) + leak;
		//cout<<"dist: "<<dist<<" cur: "<<cur<<" left: "<<left <<" type" <<obs[i].type<<endl;
		if(left-(dist*cur) < 0) ok=false;
		else left-=(dist*cur);
	}
	return ok;
}
int main()
{
	string s, com;
	bool finish=false;
	while(getline(cin,s)){
		bool done=false;
		int cur_fuel, cur_type, cur_start;
		obs.clear();
		while(!done){
			Command tmp;
			stringstream ss(s);
			ss >> cur_start;
			ss >> com;
			if(com.compare("Fuel")==0){
				ss>>com;
				ss>>cur_fuel;
				if(cur_fuel==0){
					done = finish=true;
					break;
					
				}
				cur_type=0;
			}
			else if(com.compare("Mechanic")==0)cur_type=2;
			else if(com.compare("Leak")==0)cur_type=1;
			else if(com.compare("Goal")==0){
				cur_type=4;
				done=true;
			}
			else cur_type=3;
			
			tmp.fuel = cur_fuel;
			tmp.type = cur_type;
			tmp.start = cur_start;
			obs.push_back(tmp);
			if(!done)getline(cin,s);
			
		}
		if(finish)break;
		double lo = 0.0, hi = MAX , mid, ans;
		while(fabs(hi-lo)>EPS){
			mid = (lo + hi) / 2.0;
			if(can(mid)){
				ans = hi = mid;	
			}
			else{
				lo = mid;
			}
		}
		printf("%.3f\n",ans);
		
		
	}

}
