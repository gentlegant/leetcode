#include<math.h>

#include<iostream>
using namespace std;
long long getN(int n){
    
    return pow(3,n)-1;
}


int main(){
    int n;
  
    while(cin>>n)
        cout<<getN(n);
 
    return 0;
}

