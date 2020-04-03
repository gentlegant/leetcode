#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
#include <windows.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dpold(n,1),dpnew(n,1);
        for(int i=1;i<m;i++){
        
            for(int j=1;j<n;j++)
                dpnew[j]=dpold[j]+dpnew[j-1];
            dpold=dpnew;
        }
        return dpnew.back();
    }
};


int main(){

    Solution a;
    cout<<a.uniquePaths(2,2);
    return 0;

}