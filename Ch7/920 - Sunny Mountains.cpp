#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define EPS 1e-9
struct point { double x, y;   
  point() { x = y = 0.0; }                      
  point(double _x, double _y) : x(_x), y(_y) {}       
  bool operator < (point other) const { 
  	if (fabs(x - other.x) > EPS)                
      return x > other.x;          
    return y < other.y; }          
  bool operator == (point other) const {
   return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)); } 
};


struct line { double a, b, c; };    

bool areParallel(line l1, line l2) {       
  return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS); }
  
void pointsToLine(point p1, point p2, line &l) {
  if (fabs(p1.x - p2.x) < EPS) {             
    l.a = 1.0;   l.b = 0.0;   l.c = -p1.x;      
  } else {
    l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
    l.b = 1.0;          
    l.c = -(double)(l.a * p1.x) - p1.y;
} }

bool areIntersect(line l1, line l2, point &p) {
  if (areParallel(l1, l2)) return false;            
  p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
  if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
  else                  p.y = -(l2.a * p.x + l2.c);
  return true; }

double dist(point p1, point p2) {           
  return hypot(p1.x - p2.x, p1.y - p2.y); }    

  
int main()
{
	int c,n;
	vector<point> pts;
	scanf("%d",&c);
	while(c--){
		scanf("%d",&n);
		pts.clear();
		pts.resize(n);
		for(int i=0;i<n;i++)scanf("%lf%lf",&pts[i].x,&pts[i].y);	
		sort(pts.begin(),pts.end());
		point last=pts[0];
		double tot=0.0;
		for(int i=0;i<n-1;i++){
			if(i!=0 && (pts[i+1].y-last.y)<EPS)continue;
			line l,l2;
			pointsToLine(pts[i],pts[i+1],l);
			pointsToLine(last,point(0,last.y),l2);
			point cur;
			areIntersect(l,l2,cur);
			tot+=dist(cur,pts[i+1]);
			last=pts[i+1];
			
		}
		printf("%.2f\n",tot);
	}
}
