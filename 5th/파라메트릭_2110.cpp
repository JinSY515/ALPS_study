#include <iostream>
#include <algorithm>
using namespace std;

int house[200001];

int binary(int n, int c){
  
  int start=1; //최소 거리
  int end=house[n-1]-house[0]; //최대 거리
  int ret=0;
  while(start<=end){
    int cnt=1;
    int mid=(start+end)/2;
    int now=house[0];
    for(int i=1; i<n; i++){
      if(house[i]-now>=mid) {
        cnt++;
        now=house[i];
      }
    }
      if(cnt>=c){
        ret=mid;
        start=mid+1;
      }
      else
        end=mid-1;
      
    }
  
  return ret;
}

int main(void){
  int n,c;
  cin >> n >> c;

  for(int i=0; i<n; i++){
    cin >> house[i];
  }

  sort(house, house+n);
  
  cout << binary(n,c);
  return 0;
}