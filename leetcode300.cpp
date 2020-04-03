#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp={INT_MIN};   
        for(auto i:nums){
            auto upper=upper_bound(dp.begin(),dp.end(),i);
            if(upper==dp.end())
                dp.push_back(i);
            else{
                *upper=i;

            }


        }
        return dp.size()-1;
    }
};