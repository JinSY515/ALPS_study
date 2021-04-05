#include <iostream>
#include <cmath>

using namespace std;

int main(void){
  int a, b, c;
  cin >> a >> b >> c;

  // -1 <= sin(x) <= 1
  // Ax + B = C  : sin(x)= 1일 때
  // Ax - B = C  : sin(x)= -1일 때
  // sin(x)는 그 사이..
  long double start_x= (c-b)/(double)a;
  long double end_x=(c+b)/(double)a;
  long double mid;
  int counter=0;
  while(start_x<end_x){
    if(counter>=10000) break;
    mid=(start_x+end_x)/2;

    if(mid*a + b * sin(mid) > c){
      end_x=mid-0.0000000000000000001;
    }
    else if(mid* a +b * sin(mid) < c){
      start_x=mid+0.0000000000000000001;
    }
    else break;
    counter++;
  }
  printf("%.10Lf\n",mid);
  return 0;
}