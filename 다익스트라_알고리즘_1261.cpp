#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 987654321
#define MAX 101
//가중치 0과 1뿐. 큐 2개? 혹은 덱
int n,m;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int map[MAX][MAX]; //가중치 입력하는 곳
int path[MAX][MAX]; //가중치 저장하는 곳

queue <pair<int,int>> zq; //0인 
queue <pair<int,int>> oq; //1인
bool inRange(int x, int y){
  return (0<=x && x<n && 0<=y && y<m);
}

void bfs(){
  zq.push({0,0}); //시작점
  path[0][0]=0; //시작점에서의 가중치는 항상 0

  while(!zq.empty()){
    int x=zq.front().first;
    int y=zq.front().second;
    zq.pop();

    for(int i=0; i<4; i++){
      int nx=x+dx[i];
      int ny=y+dy[i];

      if(inRange(nx,ny) && path[nx][ny]==-INF){ //범위내이고, 방문하지 않았다면
        if(map[nx][ny]==0){ //0이면
          path[nx][ny]=path[x][y];
          zq.push({nx,ny});
        }
        else{ //1이면
          path[nx][ny]=path[x][y]+1; //가중치+1
          oq.push({nx,ny});
        }

      }
    }

    if(zq.empty()){
      swap(zq,oq);
    }
  }
}


int main(void){
  cin >> m >> n;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      scanf("%1d",&map[i][j]);
      path[i][j]=-INF;  //visited 대신
    }
  }
  bfs();
  
  cout << path[n-1][m-1] <<"\n";
  return 0;
}