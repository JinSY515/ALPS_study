#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int, vector<int>,less<int>>pq;
int main(void){
  int n;
  cin >> n;
  vector<int> v;
  for(int i=0; i<n; i++){
    int a;
    cin >> a;
    v.push_back(a);
    pq.push(a);
  }

  int least=0;
  while(pq.size()!=1){
    int j=pq.top();
    pq.pop();
    
    int i;
    for(i=0; i<v.size(); i++){
      if(v[i]==j) break;
    }
    least+=min(v[i]-v[i+1],v[i]-v[i-1]);
   
    for(; i<v.size(); i++){
      v[i]=v[i+1];
    }
  }
  
  cout << least ;
  return 0;
}