// 16. 3Sum Closest
// Medium

// Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

// Example:

// Given array nums = [-1, 2, 1, -4], and target = 1.

// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
#include<vector>
#include<iostream>
#include <algorithm>
using namespace std;


class Solution {
public:
    int compare(int x,int y){
        return abs(x)<abs(y)?x:y;
    }


    int threeSumClosest(vector<int>& nums, int target) {
        int res=INT32_MAX;
        sort(nums.begin(), nums.end());
        int oldone = INT32_MAX;
        auto one = nums.begin() - 1;
        while (one < nums.end() - 2)
        {
            //过滤相同的第一个数
            while (*++one == oldone)
                ;
            oldone = *one;

            auto sec = one;

            int oldsec = *one - 1;

            auto end = nums.end();
            while (true)
            {
                //过滤相同的第2个数
                while (*(++sec) == oldsec)
                    ;
                if(sec>=end)
                    break;
                oldsec = *sec;

                int third = target-*one - *sec;

                auto find = upper_bound(sec + 1, end, third)-1;
                if (find != end ){
                    if(*find==third)
                        return 0;
                    else{
                       
                        if(sec!=find)
                            res=compare(res,third-*(find-1));

                        end = find;
                    }
                }
                  

     
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution a;
    vector<int> b={-1,2,1,-4};
    cout<<a.threeSumClosest(b,1);
    return 0;
}
