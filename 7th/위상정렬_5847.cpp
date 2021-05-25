#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void){
  int n,m;
  cin >> n >> m;
  int T[n+1];

  for(int i=1; i<=n; i++){
    cin >> T[i];
  }
  int a, b;
  vector<int> Milk[n+1];
  int inQ[n+1];
  int ret[n+1];
  for(int i=0; i<n+1; i++){
    inQ[i]=0;
    ret[i]=T[i];
  }
  queue<int> q;
  for(int i=0; i<m; i++){
    cin >> a >> b;
    Milk[a].push_back(b);
    inQ[b]++;
  }

  for(int i=1; i<=n; i++){
    if(!inQ[i]) q.push(i);
  }

  while(!q.empty()){
    int cur = q.front();
    q.pop();
    for(int i=0; i<Milk[cur].size(); i++){
      int next=Milk[cur][i];
      ret[next]=max(ret[next], ret[cur]+T[next]);
      inQ[next]--;
      if(!inQ[next]) q.push(next);
    }
    
  }
  int maxRet=0;
  for(int i=1; i<=n; i++){
    maxRet=max(maxRet, ret[i]);
  }
  cout << maxRet;
  return 0;

}