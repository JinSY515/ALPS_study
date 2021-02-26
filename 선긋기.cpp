#include <iostream>
#include <algorithm>
using namespace std;
#define N 1000001
typedef struct Line{
  int start;
  int end;
}Line;
int n;
Line line[N];

int max(int a, int b){
  if(a>b) return a;
  else return b;
}

int dot(Line a, Line b){
  if(a.start<b.start) return 1;
  else return 0;
}
int main(void){
  scanf("%d",&n);
  for(int i=0; i<n; i++){
    scanf("%d %d",&line[i].start,&line[i].end);
  }
  sort(line,line+n,dot);
  int left=-1000000001;
  int right=-1000000001;
  int length=0;
  for(int i=0; i<n; i++){
    if(line[i].start<=right){  //겹치면
      right=max(right,line[i].end);
    }
    else{  //겹치지 않으면
      length+=(right-left);
      left=line[i].start;
      right=line[i].end;
    }
  }
  length+=(right-left); //마지막 것도 추가
  printf("%d",length);

  return 0;
}