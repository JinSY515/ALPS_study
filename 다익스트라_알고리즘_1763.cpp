#include <iostream>
#include <queue>
#include <vector>

#define MAX 20001
#define NOT_AREA 987654321
using namespace std;
int path[MAX];
priority_queue<pair<int,int>> pq;
vector <pair<int,int>> Ve[MAX];
int V,E,start;

void dik(){
  pq.push({0,start}); //가중치 0인 정점=start
  path[start]=0; //start에서 start까지의 거리=0

  while(!pq.empty()){
    int weight=-pq.top().first; //부호 바꾸기
    int Curnode=pq.top().second;
    pq.pop();

    if(path[Curnode]<weight) continue;
    for(int i=0; i<Ve[Curnode].size(); i++){
      int Nextnode=Ve[Curnode][i].first;
      int Nextweight=Ve[Curnode][i].second;

      if(path[Nextnode]>weight+Nextweight){
        path[Nextnode]=weight+Nextweight; //갱신
        pq.push({-path[Nextnode],Nextnode});
      }
    }
  }
}
int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >>V>> E;
  cin >>start;
  int i;
  for(int i=0; i<E; i++){
    int u,v,w;
    cin >> u >> v >> w;
    Ve[u].push_back({v,w});
  }
  for(i=1; i<=V; i++){
    path[i]=NOT_AREA;
  }
  dik();
  for(int i=1; i<=V; i++){
    if(path[i]==NOT_AREA) cout <<"INF" <<"\n";
    else cout << path[i] << '\n';
  }
  return 0;
}