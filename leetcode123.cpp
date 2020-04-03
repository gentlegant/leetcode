#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

#include <windows.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int sell0 = 0, buy0 = INT_MIN, buy1=buy0, sell1=sell0, buy2=buy0, sell2=sell0;
        for (auto i : prices)
        {
            buy2 = max(buy2, sell1 - i);
            sell2 = max(sell2, buy2 + i);
            buy1 = max(buy1, sell0 - i);
            sell1 = max(sell1, buy1 + i);
        }
        return sell2;
    }
};