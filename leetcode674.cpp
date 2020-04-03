#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int res=1;
        int start=0,end=0;
        while(start<nums.size()){
            end=start;
            while((end+1)<nums.size()&&nums[end+1]>nums[end]){
                end++;
            }
            res=max(res,end-start+1);
            start=end+1;
          
        }
        return res;
    }
};

int main(){
    Solution a;
    vector<int >b={1,3,5,4,7};
    a.findLengthOfLCIS(b);


}