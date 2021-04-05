#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

bool visited[100001];
int city1, city2;
vector<pair<int,int>> v[100001];

int max(int a, int b){
  if(a>b) return a;
  else return b;
}

bool bfs(int m){
  queue<int> q;
  q.push(city1);
  int curnode;
  while(!q.empty()){
    curnode=q.front();
    q.pop();
    if(curnode==city2) return true;
    for(int i=0; i<v[curnode].size(); i++){
      int nextnode=v[curnode][i].first;
      int nextcost=v[curnode][i].second;
      if(!visited[nextnode] && m <= nextcost){
        visited[nextnode]=true;
        q.push(nextnode);
      }
    }

  
  }
  
  return false;
}
int main(void){
  int n,m;
  cin >> n >> m;
  int a, b, c;
  int cost=0;
  for(int i=0; i<m; i++){
    cin >> a >> b >> c;
    v[a].push_back({b,c});
    v[b].push_back({a,c});
    cost=max(cost,c);
  }

  cin >> city1 >> city2;

  int start=0;
  int end=cost;

  while(start<=end){
    memset(visited,false, sizeof(visited));
    int mid=(start+end)/2;

    if(bfs(mid)) start=mid+1;
    else end=mid-1;
  }

  cout << end;
}