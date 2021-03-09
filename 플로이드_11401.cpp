#include <iostream>
using namespace std;
#define INF 987654321

//플로이드
int v,e;
int dp[101][101];
void floyd(){  //플로이드 알고리즘
  for(int k=1; k<=v; k++){
    for(int i=1; i<=v;i++){
      for(int j=1; j<=v; j++){
        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
      }
    }
  }
}
int main(void){
  cin >> v >> e;
  for(int i=1; i<=v; i++){
    for(int j=1; j<=v; j++){
      dp[i][j]=INF; //visited?
    }
  }
  for(int i=0; i<e; i++){
   int a,b,c;
   cin >> a >> b >> c;
   if(dp[a][b]==INF) dp[a][b]=c;
   else if(dp[a][b]>c) dp[a][b]=c; //중복도 있기 때문에 덮어씌우기 제대로 하기
  }

  floyd();
  for(int i=1; i<=v; i++){
    for(int j=1; j<=v; j++){
      if(i==j) dp[i][j]=0;   //i==j인 대각선은 모두 0으로
      if(dp[i][j]==INF) dp[i][j]=0;  //방문X 모두 0으로
      printf("%d ",dp[i][j]);
    }
    printf("\n");
  }

  return 0;

}