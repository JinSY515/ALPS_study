#include <iostream>
#define N 201

using namespace std;
int parent[N];

int find(int n){
  if(n==parent[n]) return n;
  else return parent[n]=find(parent[n]);
}

void merge(int x, int y){
  x=find(x);
  y=find(y);
  if(x==y) return;
  parent[y]=x;
}

void Init(int n){
  for(int i=0; i<=n; i++){
    parent[i]=i;
  }
}
int main(void){
  int n,m;
  cin >> n >> m;
  Init(n);
  int state;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      cin >> state;
      if(state) merge(i,j);
    }
  }
  int city;
  cin >> city;
  int related=1;
  int Union=find(city);
  for(int i=0; i<m-1; i++){
    cin >> city;
    if(Union!=find(city)) related=0;
  }
  if(related) cout << "YES\n";
  else cout << "NO\n";

  return 0;

}