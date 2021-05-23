#include <iostream>
#include <queue>
#include <vector>

using namespace std;
vector<int>pre[1001]; 
queue<int> q;
int ret[1001]={0};
int INQ[1001]={0};
int main(void){
  
  int n,m;
  cin >> n >> m ;
  for(int i=0; i<m; i++){
    int a,b;
    cin >> a >> b;
    pre[a].push_back(b);
    INQ[b]++;
  }
  for(int i=1; i<=n; i++){
    if(!INQ[i]){
      q.push(i);   //선수과목이 없으면
    }
    ret[i]=1;      //1학기에 들을 수 있다.
  }

  while(!q.empty()){
    int p =q.front();
    q.pop();  //p가 선수과목인 과목들을 q에 추가.

    for(int i=0;i<pre[p].size(); i++){
      int pp = pre[p][i];
      INQ[pp]--;
      if(!INQ[pp]){
        q.push(pp);
        if(ret[pp]<ret[p]+1){
          ret[pp]=ret[p]+1;
        }
      }
    }
  }

  for(int i=1; i<=n; i++){
    cout << ret[i] << " ";
  }

  return 0;

}