#include <iostream>

#include <vector>
using namespace std;

vector <long long> t;

long long binary(long long start, long long end, long long n, long long m){
  long long ret=0;
  while(start<=end){
    long long mid=(start+end)/2;
    long long int ans=0;

    for(int i=0; i<n; i++){
      ans+=mid/t[i];
    }

    if(ans>=m){
      ret=mid;
      end=mid-1;
    }
    else{
      start=mid+1;
    }
  }

  return ret;
}
int main(void){
  long long n,m;
  cin >> n >> m;
  long long maxv=0;
  for(int i=0; i<n; i++){
    long long a;
    cin >> a;
    t.push_back(a);
    maxv=max(maxv,t[i]);
  }
  cout <<binary(1,maxv*m,n,m);

  return 0;
}