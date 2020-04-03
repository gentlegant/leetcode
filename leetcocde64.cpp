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
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;
        int m=grid.size(),n=grid[0].size();
        vector<int> dpold(n,1),dpnew(n,1);
        for(int i=0;i<n;i++)
            dpold[i]=i==0?0:dpold[i-1]+grid[0][i];
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++)
                dpnew[j]=min(j==0?INT_MAX:dpnew[j-1],dpold[j])+grid[i][j] ;
            dpold=dpnew;
        }
        return dpold.back();
    }
};