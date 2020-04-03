class Solution {
public:
    double myPow(double x, int n) {
        double res=x;
        n--;
        bool flag=false;
        if(n<0){
            flag=true;
            n=-n;
        }
                
        while(n!=1)
        {
            res*=res;
            if(n&1)
                res*=x;
            n/=2;
        }
        return flag?1/res:res;
    }
};