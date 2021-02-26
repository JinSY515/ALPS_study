#include <iostream>
#include <algorithm>
#include <stack>
#define N 500001
using namespace std;

stack<pair<int,int>> s; //스택< 수신 탑 개수 , 탑 높이>
int ans[N]={0};
int input[N]={0};
int main(void){
  int n;
  scanf("%d",&n);
  for(int i=0; i<n; i++){
    scanf("%d",&input[i]);
  }
  s.push({1,input[0]}); 

  for(int i=1; i<=n; i++){
    if(input[i]>s.top().second){ 
      while(!s.empty() && s.top().second<input[i]){
        s.pop();
      }
      if(s.empty()) ans[i]=0;
      else{
        ans[i]=s.top().first;
        if(s.top().second==input[i]) s.pop();
      }
    }
    else{
      ans[i]=s.top().first;
    }
    s.push({i+1,input[i]});
  }

  for(int i=0; i<n; i++){
    printf("%d ",ans[i]);
  }
  return 0;
}