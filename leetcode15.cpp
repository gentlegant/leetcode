#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
  public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int oldi = INT32_MAX;
        auto i = nums.begin() - 1;
        while (i < nums.end() - 2)
        {
            while (*++i == oldi)
                ;
            oldi = *i;

            auto begin = i;

            int old = *i - 1;

            auto end = nums.end();
            while (true)
            {
                //
                while (*(++begin) == old)
                    ;
                if (begin >= end)
                    break;
                old = *begin;

                int sub = -*i - *begin;

                auto end1 = lower_bound(begin + 1, end, sub);
                if (end1 != end && *end1 == sub && end1 != begin)

                    res.push_back(vector<int>{*i, *begin, sub});

                end = end1;
            }
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
    Solution a;
    vector<int> vc{-2, 0, 1, 1, 2};
    auto res = a.threeSum(vc);
    for (auto &v : res)
    {
        for (auto &x : v)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}
