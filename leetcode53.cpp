#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int s=INT_MIN,res=s;
        for(auto i:nums){
            s=max(s+i,i);
            res=max(res,s);
        }
        return res;

    }
};