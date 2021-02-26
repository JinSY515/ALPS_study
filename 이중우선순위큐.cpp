#include <iostream>
#include <set>
using namespace std;
int main(void){
  int t;
  scanf("%d",&t);
  while(t--){
    int n;
    scanf("%d",&n);
    multiset<int>ms;
    
    for(int i=0; i<n; i++){
      char order;
      int data;
      cin >> order >> data;
      if(order=='I'){
        ms.insert(data);
      }
      else{
        if(!ms.empty()){
          if(data==1){
            auto tmp=ms.end();
            tmp--;
            ms.erase(tmp);
          }
          else{
            ms.erase(ms.begin());
          }
        }
      }
    }

    if(ms.empty()){
      printf("EMPTY\n");
    }
    else{
      auto tmp=ms.end();
      tmp--;
      cout << *tmp <<" "<<*ms.begin() << "\n";
    }
  }
}