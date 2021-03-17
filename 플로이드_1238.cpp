#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
//플로이드 가능?
int path[1001][1001]={0};
int n,m,x;
int max(int a, int b){
  if(a>b) return a;
  else return b;
}

void fill(){
  for(int k=1; k<=n; k++){
    for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
        path[i][j]=min(path[i][j],path[i][k]+path[k][j]);
      }
    }
  }
}
int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> x;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      if(i==j) path[i][j]=0;
      else path[i][j]=987654321;
    }
  }

  for(int i=0; i<m; i++){
    int a, b, t;
    cin >> a >> b >> t;
    path[a][b]=t;
  }

  fill();
  int result=0;
  for(int i=1; i<=n; i++){
    result=max(result, path[i][x]+path[x][i]);
  }
  printf("%d",result);

  return 0;
}