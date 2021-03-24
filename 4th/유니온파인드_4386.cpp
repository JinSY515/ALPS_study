#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define N 1001

using namespace std;
vector<pair<double,double>> V;
vector<pair<double,pair<double,double>>> constellation;
int parent[N];

void Init(int n){
  for(int i=0; i<n; i++){
    parent[i]=i;
  }
}

int find(int n){
  if(parent[n]==n) return n;
  else return parent[n]=find(parent[n]);
}

void merge(int x, int y){
  x=find(x);
  y=find(y);
  if(x!=y) parent[y]=x; 
}

double dist(double x, double y, double x2, double y2){
  double ret=sqrt(pow(x-x2,2)+pow(y-y2,2));
  return ret;
}

int main(void){
  int n;
  cin >> n;
  Init(n);
  
  for(int i=0; i<n; i++){
    double x, y;
    cin >> x >> y;
    V.push_back({x,y});
  }
  for(int i=0; i<n-1; i++){
    double x=V[i].first;
    double y=V[i].second;
    for(int j=i+1; j<n; j++){
      double x2=V[j].first;
      double y2=V[j].second;

      double d=dist(x,y,x2,y2);
      constellation.push_back({d,{i,j}});
    }
  }
  sort(constellation.begin(),constellation.end());
  double weight=0;
  for(int i=0; i<constellation.size(); i++){
    int a=constellation[i].second.first;
    int b=constellation[i].second.second;

    if(find(a)!=find(b)){
      merge(a,b);
      weight+=constellation[i].first;
    }
  }
  printf("%.2f",weight);

  return 0;
}