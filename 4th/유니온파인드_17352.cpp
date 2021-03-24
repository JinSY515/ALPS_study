#include <iostream>

#define N 300001
using namespace std;
int graph[N];
int find(int n){
  if(graph[n]==n) return n;
  
  return graph[n]=find(graph[n]);
}
void merge(int x, int y){
  x=find(x);
  y=find(y);
  if(x==y) return;
  
  graph[y]=x;
}

void Init(int n){
  for(int i=0; i<n; i++){
    graph[i]=i;
  }
}

int main(void){
  int n;
  cin >> n;
  Init(n);
  for(int i=0; i<n-2; i++){
    int a, b;
    cin >> a >> b;
    merge(a,b);
  }
  int k=find(1);
  for(int i=2; i<=n; i++){
    int l=find(i);
    if(k!=l){
      cout << 1 << " " << i;
      break;
    }  
  }
  return 0;
}