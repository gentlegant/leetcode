#include<math.h>

#include<iostream>
using namespace std;



int main(){
    int n;
    cin>>n;
    int res=1;
    for(int i=0;i<n;i++)
        res*=3;
    
    cout<<res-1;
    return 0;
}

