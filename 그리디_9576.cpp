#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



bool cmp(pair<int,int> x1, pair<int,int> x2){
  if(x1.second != x2.second){
    return x1.second < x2.second;
  }
  else{
    return x1.first < x2.first;
  }
}
int main(void){
  int t;
  cin >> t;
  while(t--){
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>>v;
    bool visited[1001]={false};
    for(int i=0; i<m; i++){
      int a, b;
      cin >> a >> b;
      v.push_back({a,b});
    }
    sort(v.begin(),v.end(),cmp);

    for(int i=0; i<m;i++){
      for(int j=v[i].first; j<=v[i].second; j++){
        if(!visited[j]){
          visited[j]=true;
          break;
        }
      }
    }
    int books=0;
    for(int i=1; i<=n; i++){
      if(visited[i]) books++;
    }
    cout << books <<"\n";
  }
  return 0;
}