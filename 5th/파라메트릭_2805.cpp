#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long v[1000001];

long long binary(long long start, long long end, long long n,long long m){
  
  long long ret=0;
  while(start<=end){
    long long ans=0;
    long long mid=(start+end)/2;
    for(int i=0; i<n; i++){
       if(v[i]>mid) ans+=(v[i]-mid);
    }

    if(ans>=m){
      if(ret<mid) ret=mid;
      start=mid+1;
    }
    else{
      end=mid-1;
    }
    
  }
  return ret;

}
int main(void){
  long long n,m;
  cin >> n >> m;

  for(int i=0; i<n; i++){
    cin >> v[i];
  }
  sort(v,v+n);
  long long ret=binary(0,v[n-1],n,m);
  cout << ret;
  return 0;
}