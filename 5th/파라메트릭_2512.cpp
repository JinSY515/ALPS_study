#include <iostream>
#include <vector>
//반복문 불변식 지키기.
using namespace std;
vector<int> v;
int min(int a, int b){
  if(a<b) return a;
  else return b;
}

int max(int a, int b){
  if(a>b) return a;
  else return b;
}
long long ret(int n){
  long long result=0;
  for(int i=0; i<v.size(); i++){
    result+=min(v[i],n);
  }
  return result;
}

int main(void){
  int n;
  cin >> n;
  int maxv=0;
  for(int i=0;i<n; i++){
    int a;
    cin >> a;
    v.push_back(a);
    maxv=max(maxv,a);
  }
  long long budget;
  cin >> budget;

  int start=0;
  int end=maxv;
  int result=0;
  while(start<=end){
    int mid=(start+end)/2;

    long long ans=ret(mid);
    
    if(ans<=budget){
      result=mid;
      start=mid+1;
    }
    else{
      end=mid-1;
    }
  }
  cout << result;

  return 0;
}