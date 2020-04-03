#include <math.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int res=1<<15;
        while( ! (res*res<=x &&(res+1)*(res+1)>=x)   )
            res=(res+x/res)/2;


        
        
        return int(res);
    }
};


int main()
{

    Solution a;
    cout<<a.mySqrt(2147395599);
    return 0;

}