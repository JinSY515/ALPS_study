#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int main(void){
  int n,m;
  cin >> n >> m;
  int p,q,r;
  vector<pair<int,int>> v[1001];
  int dp[1001];
  int k[1001];
  int ret[1001];

  for(int i=0; i<m; i++){
    cin >> p >> q >> r;
    v[p].push_back({q,r});
    k[q]++;
  }

  queue<int> pq;
  pq.push(1);
  while(k[1]){
    int node =pq.front();
    pq.pop();
    for(int i=0; i<v[node].size(); i++){
      int nextNode = v[node][i].first;
      int nextCost = v[node][i].second;
      k[nextNode]--;

      if(dp[nextNode] < dp[node] + nextCost){
        dp[nextNode] = dp[node] + nextCost;
        ret[nextNode] = node;
      }
      if(!k[nextNode]) pq.push(nextNode);
    }
  }

  cout <<dp[1] <<endl;
  vector<int> result;
  int cur = ret[1];
  while(cur!=1){
    result.push_back(cur);
    cur=ret[cur];
  }
  cout << "1 ";
  for(int i=result.size()-1; i>=0; i--){
    cout << result[i] << " ";
  }
  cout <<"1";
  return 0;
}