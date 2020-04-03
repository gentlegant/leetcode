#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < min(m, n) / 2; i++)
        {

            for (int k = i; k < n - i - 1; k++)
                res.push_back(matrix[i][k]);
            for (auto i : res)
                cout << i << " ";
            cout << endl;
            for (int k = i; k + i < m - 1; k++)
                res.push_back(matrix[k][n - i - 1]);
            for (auto i : res)
                cout << i << " ";
            cout << endl;
            for (int k = n - i - 1; k > i; k--)
                res.push_back(matrix[m - i - 1][k]);
            for (auto i : res)
                cout << i << " ";
            cout << endl;
            for (int k = m - i - 1; k > i; k--)
                res.push_back(matrix[k][i]);
            for (auto i : res)
                cout << i << " ";
            cout << endl;
        }
        if (m > n && n & 1)
        {
            for (int i = n/2;i<m-n/2;i++)
                res.push_back(matrix[i][n/2]);
        }
        else if (n > m && m & 1)
        {
             for (int i = m/2;i<n-m/2;i++)
                res.push_back(matrix[m / 2][i]);
        }

        return res;
    }
};

int main()
{

    Solution a;
    vector<vector<int>> res = {{1}, {2}};
    auto b = a.spiralOrder(res);
    for (auto i : b)
        cout << i << " ";
}