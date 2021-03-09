#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 987654321

//플로이드
int v,e;
int dp[101][101];
int path[101][101];
vector<int>Vec[101][101];

void floyd(){
 
  for(int k=1; k<=v; k++){
    for(int i=1; i<=v;i++){
      for(int j=1; j<=v; j++){
        if(i==j) continue;
        if(dp[i][j]<=dp[i][k]+dp[k][j]) dp[i][j]=dp[i][j];
        else {
          dp[i][j]=dp[i][k]+dp[k][j];
          vector <int> tmp = Vec[k][j];
          Vec[i][j].clear();  //비워주고
          Vec[i][j]=Vec[i][k];  
          for(int t=1; t<tmp.size(); t++){
            Vec[i][j].push_back(tmp[t]);  //이어붙이기
           }
        }
      }
    }
  }
 
}
int main(void){
  cin >> v >> e;
  for(int i=1; i<=v; i++){
    for(int j=1; j<=v; j++){
      dp[i][j]=INF; //visited?
      Vec[i][j].push_back(i);
      Vec[i][j].push_back(j);
    }
  }
  for(int i=0; i<e; i++){
   int a,b,c;
   cin >> a >> b >> c;
   if(dp[a][b]==INF) dp[a][b]=c;
   else if(dp[a][b]>c) dp[a][b]=c;
  }

  floyd();
  for(int i=1; i<=v; i++){
    for(int j=1; j<=v; j++){
      if(i==j) dp[i][j]=0;
      if(dp[i][j]==INF) dp[i][j]=0;
      printf("%d ",dp[i][j]);
    }
    printf("\n");
  }
  for(int i=1; i<=v; i++){
    for(int j=1; j<=v; j++){
      if(i==j || dp[i][j]==INF){
        printf("0\n");
        continue;
      }
      printf("%lu ",Vec[i][j].size());
      for(int k=0; k<Vec[i][j].size(); k++){
        printf("%d ",Vec[i][j][k]);
      }
      printf("\n");
    }
  }
  return 0;
}