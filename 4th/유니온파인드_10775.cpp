#include <iostream>
#include <vector>
#define N 100001


using namespace std;
vector<int> plane;
int gate[N];

void Init(int n){
  for(int i=1; i<=n; i++){
    gate[i]=i;
  }
}

int find(int n){
  if(n==gate[n]) return n;
  else return gate[n]=find(gate[n]);
}

void merge(int x, int y ){
  x=find(x);
  y=find(y);
  if(x!=y) gate[x]=y;
}

int main(void){
  int G,P,g;
  cin >> G >> P;
  Init(G);
  plane.resize(P);
  for(int i=0; i<P; i++){
    cin >> plane[i];
  }
  int ret=0;
  for(int i=0; i<P; i++){
    int dock=find(plane[i]);
    if(dock!=0){
      merge(dock,dock-1);
      ret++;
    }
    else break;
  }
  cout << ret;

  return 0;

}
