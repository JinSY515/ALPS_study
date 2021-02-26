#include <iostream>
#define N 15 //최대 15

int d[2*N-1]={0};
int w[N]={0}; 
int h[2*N-1]={0};
int dp[N]={0};
int cnt=0;

void chess(int n, int i){
  for(int j=0; j<n; j++){
    if(!w[j] && !h[i+j]&& !d[i-j+n-1] ){
      dp[i]=j;
      if(i==n-1) cnt++;
      else{
        w[j]=h[i+j]=d[i-j+n-1]=1;
        chess(n,i+1);
        w[j]=h[i+j]=d[i-j+n-1]=0;
      }
    }
  }
}
int main(void){
  int n;
  scanf("%d",&n);
  chess(n,0);
  printf("%d\n",cnt);
  return 0;
}