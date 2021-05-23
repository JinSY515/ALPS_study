#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void){
  int t;
  cin >> t;
  while(t--){
    int n, k;
    cin >> n >> k;
    int D[n+1];
    for(int i =1; i<=n; i++){
      cin >> D[i];
    }

    int x,y;
    vector<int> T[n+1];
    int c[n+1];
    int ret[n+1];
    for(int i=0; i<n+1; i++){
      c[i]=0;
      ret[i]=0;
    }
    for(int i=0; i<k; i++){
      cin >> x >> y;
      T[x].push_back(y);
      c[y]++;
    }
    int w;
    cin >> w;

    queue<int> q;
    for(int i=1; i<=n; i++){
      if(!c[i]) q.push(i);
    }
    
    while(q.size()){
      int cur = q.front();
      q.pop();
      for(int i=0; i<T[cur].size(); i++){
        int next = T[cur][i];
        ret[next]=max(ret[next], ret[cur]+D[cur]);
        c[next]--;
        if(!c[next]){
          q.push(next);
        }
        
      }
    }
    cout << ret[w]+D[w] << endl;
  }
  return 0;
}