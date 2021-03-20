#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int,int>> v;
priority_queue<int>pq;
int main(void){
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    int a, b;
    cin >> a >> b;
    v.push_back({a,b});
  }
  int l,p;
  cin >> l >> p; //l이 거리, p가 연료

  sort(v.begin(),v.end());
  int curP=p; //현재 남은 연료 
  int ans=0;
  int idx=0;

  while(true){
    if(curP >= l) break;
    while(v[idx].first <= curP){
      if(idx>=n) break;
      pq.push(v[idx].second);
      idx++;
    }
    if(pq.empty()){
      ans=-1;
      break;
    }
    curP+=pq.top();
    pq.pop();
    ans++;
  }
  
  cout << ans << "\n";
  return 0;
}