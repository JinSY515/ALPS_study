#include <iostream>
#include <vector>
#include <algorithm>
#define INF 100000000
using namespace std;

int com[101][101];
bool visited[101];
int mval[101]={0};
vector<int> result;
int n,m;
void floyd(){
  for(int k=1; k<=n; k++){
    for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
        com[i][j]=min(com[i][j],com[i][k]+com[k][j]);
      }
    }
  }
}

void solve(int node){
  int idx=node;
  for(int i=1; i<=n; i++){
    if(com[node][i]<INF){
      visited[i]=true;
      if(mval[idx]>mval[i]){
        idx=i;
      }
    }
  }
  result.push_back(idx);
}
int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> n;
  cin >> m;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      if(i==j) com[i][j]=0;

      else com[i][j]=INF;
    }
    visited[i]=false;
  }
  for(int i=0; i<m; i++){
    int a, b;
    cin >> a >> b;
    com[a][b]=1;
    com[b][a]=1;
  }
  floyd();
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      if(com[i][j]> mval[i] && com[i][j]<INF) mval[i]=com[i][j];
    }
  }
  for(int i=1; i<=n; i++){
    if(!visited[i]){
      solve(i);
    }
  }
  sort(result.begin(),result.end());
  printf("%lu\n",result.size());
  for(int i=0;i<result.size(); i++ ){
    printf("%d\n",result[i]);
  }

  return 0;
}