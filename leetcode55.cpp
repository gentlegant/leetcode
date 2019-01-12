#include <vector>


#include <iostream>

using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int able=0;
        for(int i=0;i<nums.size();i++){
            if(i>able)
                return false;
            if(i+nums[i]>=able)
                able=i+nums[i];
        }
        return true;
        
    }
};