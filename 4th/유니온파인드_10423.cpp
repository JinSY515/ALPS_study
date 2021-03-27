#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int parent[1001];
struct cable{
  int from;
  int to;
  int cost;
};

priority_queue<cable,vector<cable>> city;
void Init(int n){
  for(int i=0; i<n; i++){
    parent[i]=i;
  }
}

bool operator<(cable x, cable y){
  return x.cost > y.cost;
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
  int n,m,k;
  cin >> n >> m >> k;
  Init(n);
  vector<int> powerhouse;
  for(int i=0; i<k; i++){
    int tmp;
    cin >> tmp;
    powerhouse.push_back(tmp);
  }
  for(int i=0; i<k-1; i++){
    merge(powerhouse[i],powerhouse[i+1]);
  }
  int u,v,w;
  for(int i=0; i<m; i++){
    cin >> u >> v >> w;
    city.push({u,v,w});
  }

  int ans=0;

  while(!city.empty()){
    if(find(city.top().from)!=find(city.top().to)){
      ans+=city.top().cost;
      merge(city.top().from, city.top().to);
    }
    city.pop();
  }

  cout << ans;

  return 0;
}