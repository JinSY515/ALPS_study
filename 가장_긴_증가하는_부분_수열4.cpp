#include <iostream>
#include <vector>
#define N 1001
using namespace std;

int dp[N]={0};
int max(int a, int b){
  if(a>b) return a;
  else return b;
}
int main(void){
  int n;
  scanf("%d",&n);
  int a[N];
  int Max=0;
  vector<int> list[N];
  vector<int> ans_list;
  for(int i=0; i<n; i++){
    scanf("%d",&a[i]);
    dp[i]=1;
    list[i].push_back(a[i]);
    for(int j=0; j<i; j++){
      if(a[i]>a[j]){
        if(dp[i]<dp[j]+1){
          list[i].clear(); //더 길면 삭제하고
          list[i]=list[j]; //기존 수열 복사한 후
          list[i].push_back(a[i]); //뒤에 추가하기
          dp[i]=dp[j]+1; //개수
        }
      }
    }
    Max=max(dp[i],Max);
    if(ans_list.size()<list[i].size()){ //가장 긴 리스트 나올 때마다 ans리스트 업데이트
      ans_list=list[i];
    }
  }
  printf("%d\n",Max);
  for(int i=0; i<ans_list.size(); i++){
    printf("%d ",ans_list[i]);
  }

  return 0;
  
}