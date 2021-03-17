#include <iostream>
using namespace std;
//플로이드
int his[401][401];
int n,k;
void fill(){
  for(int k=1; k<=n; k++){
    for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
        if(his[i][k]==1 && his[k][j]==1){ // j->k->i 순서대로 일어난다면
          his[i][j]=1;
          his[j][i]=-1;
        }
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int after,before;
  cin >> n >> k;
  for(int i=0; i<k; i++){
    cin >> before >> after;
    his[before][after]=-1;
    his[after][before]=1;
  }
  fill();
  int s;
  int e1,e2;
  cin >> s;
  for(int i=0; i<s; i++){
    cin >> e1 >> e2;
    printf("%d\n",his[e1][e2]);
  }
  return 0;
}