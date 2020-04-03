#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

#include <windows.h>
using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        vector<int> dpold = triangle[0], dpnew;
        for (int i = 1; i < triangle.size(); i++)
        {
            dpnew.clear();
            for (int j = 0; j <= i; j++)
            {
                dpnew.push_back(min(
                                    j == i ? INT_MAX : dpold[j], j == 0 ? INT_MAX : dpold[j - 1]) +
                                triangle[i][j]);
            }
            dpold = dpnew;
        }

        return accumulate(dpold.begin(), dpold.end(), INT_MAX, [](int p1, int p2) { return min(p1, p2); });
    }
};