#include <iostream>
#define N 1000001
using namespace std;
int parent[N];
int find(int n){
  if(n==parent[n]) return n;
  return parent[n]=find(parent[n]);
}

void merge(int x, int y){
  x=find(x);
  y=find(y);
  if(x==y) return;
  parent[x]=y;
}

void Init(int n){
  for(int i=0; i<=n; i++){
    parent[i]=i;
  }
}
int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,m;
  cin >> n >> m;
  Init(n);
  int order, a, b;
  for(int i=0; i<m; i++){
    cin >> order >> a >> b;
    if(order==0) merge(a,b);
    else if(order==1){
      if(find(a)==find(b))
      cout << "YES\n";
      else 
      cout << "NO\n";
    }
  }
  return 0;
}