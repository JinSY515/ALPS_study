#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;
int binary(int n, int m, int l){
  int start=1;
  int end=l-1;

  while(start<=end){
    int mid=(start+end)/2;

    int cnt=0;

    for(int i=0; i<v.size()-1; i++){
      int dist=v[i+1]-v[i];
      if(dist/mid>0){
        if(dist%mid==0){
          cnt+=(dist/mid)-1;
        }
        else cnt+=(dist/mid);
      }
    }

    if(cnt>m){
      start=mid+1;
    }
    else{
      end=mid-1;
    }
  }

  return start;
}

int main(void){
  int n,m,l;
  cin >> n >> m >> l;

  
  v.push_back(0);

  for(int i=-0; i<n; i++){
    int a;
    cin >> a;
    v.push_back(a);
  }

  v.push_back(l);
  sort(v.begin(),v.end());

  cout << binary(n,m,l);  
  return 0;
}