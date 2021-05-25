#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void){
  int n,m;
  cin >> n >> m;
  int a, b;
  vector<int> problem[n+1];
  
  int ret[n+1];
  priority_queue<int, vector<int>, greater<int>> pq;
  for(int i=0; i<n+1; i++){
    ret[i]=0;
  }

  for(int i=0; i<m; i++){
    cin >> a >> b;
    problem[a].push_back(b);
    ret[b]++;
  }

  for(int i=1; i<=n; i++){
    if(!ret[i]) pq.push(i);
  }

  while(!pq.empty()){
    int cur = pq.top();
    pq.pop();
    cout << cur << " ";
    for(int i=0; i<problem[cur].size(); i++){
      int next = problem[cur][i];
      ret[next]--;
      if(!ret[next]) pq.push(next);
    }
  }

  return 0;


}