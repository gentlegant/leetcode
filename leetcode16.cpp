// 16. 3Sum Closest
// Medium

// Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly first solution.

// Example:

// Given array nums = [-1, 2, 1, -4], and target = 1.

// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
#include<vector>
#include<iostream>
#include <algorithm>
using namespace std;


class Solution {
private:
     int closer(int x,int y,int target){
        return abs(x-target)<abs(y-target)?x:y;
    }
public:
    int threeSumClosest(vector<int>& nums, int target) {
      
        int res=nums[0]+nums[1]+nums[2];
        sort(nums.begin(), nums.end());

        auto first = nums.begin()-1;
        while (++first < nums.end() - 2)
        {
          
            auto second = first+1;
            auto third = nums.end()-1;
            while (second<third)
            {
                int sum = *first+*second+*third;
                //第一个大于等于third的数
                if(sum==target)
                    return target;
                else{
                    res=closer(res,sum,target);
                    sum>target?third--:second++;
                }
              
            }

        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution a;
    vector<int> b={0,-4,1,-5};
    cout<<a.threeSumClosest(b,0);
    return 0;
}
