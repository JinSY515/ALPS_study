#include <iostream>
#include <vector>
#include <algorithm>
#define N 10001
using namespace std;
int parent[N];
vector<pair<int,pair<int,int>>>V;

void Init(int n){
  for(int i=0; i<=n; i++){
    parent[i]=i;
  }
}
int find(int n){
  if(n==parent[n]) return n;
  else return parent[n]=find(parent[n]);
}

void merge(int x, int y){
  x=find(x);
  y=find(y);
  if(x!=y) parent[y]=x;
}
int main(void){
  int v,e;
  cin >> v >> e;
  Init(v);
  int a, b, c;
  for(int i=0; i<e; i++){
    cin >> a >> b >> c;
    V.push_back({c,{a,b}});
  }
  sort(V.begin(),V.end());
  int weight=0;
  for(int i=0; i<e; i++){
    if(find(V[i].second.second)!=find(V[i].second.first)){
      merge(V[i].second.first,V[i].second.second);
      weight+=V[i].first;
    }
  }
  cout << weight;
  return 0;
}