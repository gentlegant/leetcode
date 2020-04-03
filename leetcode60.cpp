#include <vector>

#include <iostream>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
#include <string>
#include <windows.h>
using namespace std;


class Solution {
public:
    string getPermutation(int n, int k) {
        k--;
        string res(n,' ');

        string ss(n,' ');
        int tmp=1;
        for(int i=1;i<n;i++){
            ss[i-1]='0'+i;
            tmp*=i;
        }
        ss[n-1]='0'+n;
        for(int i=1;i<n;i++){
            auto index=k/tmp;
           
            k%=tmp;
            tmp/=(n-i);
            res[i-1]=ss[index];
            ss.erase(ss.begin()+index);
        }
        res.back()=ss[0];
        return res;
    }
};


int main(){
    Solution a;
    for(int i=1;i<=15;i++)
        cout<<a.getPermutation(5,i)<<endl;



}