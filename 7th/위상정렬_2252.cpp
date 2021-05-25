#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main(void){
  int n,m;
  cin >> n >> m;
  int a, b;
  vector<int> height[n+1];
  int h[n+1];
  for(int i=0; i<n+1; i++) h[i]=0;
  queue<int> q;
  for(int i=0; i<m; i++){
    cin >> a >> b;
    height[a].push_back(b);
    h[b]++;
  }

  for(int i=1;i<=n; i++){
    if(!h[i]) q.push(i);
  }

  while(!q.empty()){
    int cur = q.front();
    q.pop();
    cout << cur << " ";
    for(int i=0; i<height[cur].size(); i++){
      int next = height[cur][i];
      h[next]--;
      if(!h[next]) q.push(next);
    }
  }
  return 0;
}