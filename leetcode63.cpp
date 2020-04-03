#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
#include <windows.h>
using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> dpold(n, 1), dpnew(n, 1);
        for (int i = 0; i < obstacleGrid[0].size(); i++)
        {
            if (obstacleGrid[0][i])
            {
                fill(dpold.begin() + i, dpold.end(), 0);
                break;
            }
        }
        for (int i = 1; i < m; i++)
        {
            if(obstacleGrid[i][0])
                dpold[0]=0;
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j])
                    dpnew[j] = 0;
                else
                    dpnew[j] = dpold[j] + dpnew[j - 1];
            }
            dpold = dpnew;
        }
        return dpold.back();
    }
};