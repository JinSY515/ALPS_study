#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdlib.h>

#include <set>
#define N 100001
using namespace std;
typedef struct Co{
  int x;
  int y; //x,y좌표 구조체로 
}Co;
Co co[N];

int cmp(const void *a, const void *b){
  struct Co *m, *n;
  m=(struct Co*)a;
  n=(struct Co*)b;
  if(m->x>n->x) return 1;  //구조체 정렬하기
  else return 0;
}
int gun[N];

int main(void){
  int m,n,l;
  scanf("%d %d %d",&m,&n,&l);
  for(int i=0; i<m; i++){
    scanf("%d",&gun[i]);
  }
  for(int i=0; i<n; i++){
    scanf("%d %d",&co[i].x, &co[i].y);
  }
  int cnt=0;
  int j=0;
  sort(gun,gun+m); //총의 위치 정렬
  qsort(co,n,sizeof(co[0]),cmp); //동물의 위치 x좌표를 기준으로 정렬
  for(int i=0; i<m; i++){
    for(;j<n; j++){
      if(abs(co[j].x-gun[i])>abs(co[j].x-gun[i+1]) && i+1<m) break;  //만약 이웃하는 총의 사정거리 안에 동물이 위치할 때, 세지 않음
      if(abs(co[j].x-gun[i])+co[j].y<=l) {
        cnt++; //사정거리 안에 위치할 때
      }
    }
  }
  printf("%d",cnt);
  return 0;
}