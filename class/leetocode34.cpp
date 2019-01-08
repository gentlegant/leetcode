#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto r=lower_bound(nums.begin(),nums.end(),target);
        if(r==nums.end()||*r!=target)
            return {-1,-1};
        return {r-nums.begin(),upper_bound(r,nums.end(),target)-nums.begin()-1};
    }
};