#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;
queue <int> q;
int timelen[MAX];
int n,k;

int bfs(){
  q.push(n);
  timelen[n]=0;

  while(!q.empty()){
    int cur=q.front();
    q.pop();

    if(cur==k) break;

    
    if(cur+1<MAX && timelen[cur+1]>timelen[cur]+1){
      timelen[cur+1]=timelen[cur]+1;
      q.push(cur+1);
    
    }

    if(cur-1>=0 && timelen[cur-1]>timelen[cur]+1){
      timelen[cur-1]=timelen[cur]+1;
      q.push(cur-1);
    
    }
    if(cur*2<MAX && timelen[cur*2]> timelen[cur]){
      timelen[cur*2]=timelen[cur];
      q.push(cur*2);
    
    }
  }
  return timelen[k];
}

void Initialize(){
  for(int i=0; i<MAX; i++){
    timelen[i]=987654321;
  }
}
int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;
  
  Initialize();
  int result=bfs();

  cout << result << "\n";
  return 0;

}