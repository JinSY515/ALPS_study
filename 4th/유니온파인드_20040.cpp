#include <iostream>
#define MAX 500001
using namespace std;


int parent[MAX];

void Init(int n){
  for(int i=0; i<n; i++){
    parent[i]=i;
  }
}

int find(int n){
  if(n==parent[n]) return n;
  else return parent[n]=find(parent[n]);
}

bool merge(int x, int y){
  x=find(x);
  y=find(y);
  if(x==y) return true;
  else{
    parent[x]=y;
    return false;
  }
}
int main(void){
  int n,m;
  cin >> n >> m;
  Init(n);
  int n1,n2;
  int ans=0;
  for(int i=1; i<=m; i++){
    cin >> n1 >> n2;
    if(merge(n1,n2)){
      ans=i;
      break;
    }
  }
  cout << ans;

  return 0;
}