#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(){
    string str;

    while(getline(cin,str)){
        if(str=="0")
            return 0;
        istringstream s(str);
        int out=0,n;
        s>>n;
        while(s>>n)
            out+=n;
        
        cout<<out<<endl;


    }

        return 0;
}