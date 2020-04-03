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

private:
    int solve(int m, int n)
    {
        int res = 1;
        for (int i = 1; i <= n; i++)
            res = res * (m - i + 1) / i;
        return res;
    }

public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res;
        for (int i = 0; i < numRows; i++)
        {
            vector<int> tmp(i + 1);
            for (int j = 0; j <= (i + 1) / 2; j++)
            {
                tmp.push_back(solve(i, j));
            }

            tmp.insert(tmp.end(), (i % 2 ? tmp.rbegin() : tmp.rbegin() + 1), tmp.rend());
        
            res.push_back(tmp);
        }

        return res;
    }
};

int main()
{

    Solution a /*  */;
    // auto b = a.generate(5);
    // for (auto k : b)
    // {

    //     for (int j : k)
    //         cout << j << " ";
    //     cout << endl;
    // }

    return 0;
}include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
#include <windows.h>
using namespace std;

class Solution
{

private:
    int solve(int m, int n)
    {
        int res = 1;
        for (int i = 1; i <= n; i++)
            res = res * (m - i + 1) / i;
        return res;
    }

public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res;
        for (int i = 0; i < numRows; i++)
        {
            vector<int> tmp(i + 1);
            for (int j = 0; j <= (i + 1) / 2; j++)
            {
                tmp.push_back(solve(i, j));
            }

            tmp.insert(tmp.end(), (i % 2 ? tmp.rbegin() : tmp.rbegin() + 1), tmp.rend());
        
            res.push_back(tmp);
        }

        return res;
    }
};

int main()
{

    Solution a /*  */;
    // auto b = a.generate(5);
    // for (auto k : b)
    // {

    //     for (int j : k)
    //         cout << j << " ";
    //     cout << endl;
    // }

    return 0;
}