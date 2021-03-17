#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;
int v,e;
int path[401][401];

void fill(){
  for(int k=1; k<=v; k++){
    for(int i=1; i<=v; i++){
      for(int j=1; j<=v; j++){
        path[i][j]=min(path[i][j],path[i][k]+path[k][j]);
      }
    }
  }
}
int main(void){
  cin >> v >> e;
  for(int i=1; i<=v; i++){
    for(int j=1; j<=v; j++){
      path[i][j]=INF;
    }
  }
  for(int i=0; i<e; i++){
    int a, b, c;
    cin >> a >> b >> c;
    path[a][b]=c;
  }
  fill();
  int result=INF;
  for(int i=1; i<=v; i++){
    result=min(result,path[i][i]);
  }

  if(result==INF) printf("-1");
  else printf("%d",result);

  return 0;

}