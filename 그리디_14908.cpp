#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


typedef struct Shoe{
  int time;
  int comp;
  int th;
}Shoe;

bool cmp(Shoe &a, Shoe &b){
  if(a.time * b.comp < a.comp * b.time) return true;
  else if(a.time * b.comp == a.comp * b.time && a.th < b.th) return true;
  else return false;
}
int main(void){
  int n;
  cin >> n; 
  Shoe shoe[n];
  for(int i=0; i<n; i++){
    int t,s;
    cin >> shoe[i].time >> shoe[i].comp ;
    shoe[i].th=i+1;
  }
  sort(shoe,shoe+n,cmp);

  for(int i=0; i<n; i++){
    cout << shoe[i].th << " ";
  }

  return 0;

}