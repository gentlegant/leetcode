#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution
{
  
  public:
    int jump(vector<int> &nums)
    {

        vector<int> dp(nums.size(), INT32_MAX);

        dp[0] = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int ii = 1; ii <= nums[i]; ii++)
                if (i + ii < nums.size() && dp[i + ii] > dp[i] + 1)
                    dp[i + ii] = dp[i] + 1;
        }

        return dp.back();
    }
};
class Solution2
{
    public:
    int jump(vector<int>& A) 
    {
     
        int level = 0, currentMax = 0, i = 0, nextMax = 0;

        while (currentMax - i + 1 > 0)
        { //nodes count of current level>0
            level++;
            for (; i <= currentMax; i++)
            { //traverse current level , and update the max reach of next level
                nextMax = max(nextMax, A[i] + i);
                if (nextMax >= A.size() - 1)
                    return level; // if last element is in level+1,  then the min jump=level
            }
            currentMax = nextMax;
        }
        return 0;
    }
};


main(int argc, char const *argv[])
{
    vector<int> b = {2, 3, 1, 1, 4};
    Solution2 a;
    cout << a.jump(b);

    return 0;
}
